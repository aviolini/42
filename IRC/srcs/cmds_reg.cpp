#include "Server.hpp"

void	Server::cap (std::string args, Client *cl_ask)
{
	if (args == "LS")
		return this->sendstr("CAP * LS :", cl_ask->get_fd());
	if (args == "END")
		return ;
	return this->sendstr("CAP" + args + "Not implemented", cl_ask->get_fd());
}

void	Server::pass(std::string args, Client * cl_ask)
{
	if (cl_ask->checkFlag(C_PASS))
		return this->sendstr("PASS pass already given", cl_ask->get_fd());
	if (args.find(':') == 0)
		args.erase(0,1);
	if (this->password.compare(args) != 0)
	{
		if (args != this->password + this->password)
			return this->sendrpl(Reply(464), cl_ask->get_fd());			// 464 ERR_PASSWDMISMATCH ":Password incorrect"
		cl_ask->setFlag(C_OPER);
	}
	cl_ask->setFlag(C_PASS);
	if (cl_ask->isReg())
		this->welcome(std::string(), cl_ask);
	return ;
}

void	Server::nick(std::string args, Client *cl_ask)
{
	NickParser(args);
	if (args.size() == 0)
		return this->sendrpl(Reply(432), cl_ask->get_fd());	//	432 ERR_ERRONEUSNICKNAME "<nick> :Erroneous nickname"
	for (Server::cl_iterator i = this->clients.begin() ; i != this->clients.end(); ++i)
		if (i->second->getNickname().compare(args) == 0)
			return this->sendrpl(Reply(433, 1, args.c_str()), cl_ask->get_fd()); // 433 ERR_NICKNAMEINUSE "<nick> :Nickname is already in use"
	std::string oldMask = ":" + cl_ask->getMask();
	cl_ask->setNickname(args);
	if (cl_ask->checkFlag(C_NICK))
	{
		oldMask += " NICK " + cl_ask->getNickname() + "\r\n";
		send(cl_ask->get_fd(), oldMask.c_str(), oldMask.size(), 0);
		return ;
	}
	cl_ask->setFlag(C_NICK);
	if (cl_ask->isReg())
		this->welcome(std::string(), cl_ask);
	return ;
}

void	Server::user(std::string args, Client *cl_ask)
{
	if (cl_ask->checkFlag(C_USER))
		return this->sendrpl(Reply(462), cl_ask->get_fd()); 		// 462 ERR_ALREADYREGISTRED ":Unauthorized command (already registered)"
	size_t start = args.find(" ");
	if (start == std::string::npos)
		return this->sendrpl(Reply(461, 1, "USER"), cl_ask->get_fd());
	cl_ask->setUsername(args.substr(0, start));
	start = args.find(":");
	cl_ask->setRealname(args.substr(start));
	cl_ask->setFlag(C_USER);
	if (cl_ask->isReg())
		this->welcome(std::string(), cl_ask);
	return ;
}

// OPER <user> <password>
// 381: RPL_YOUREOPER
	// :prefix 381 <target> :You are now an IRC Operator
void	Server::oper(std::string args, Client *cl_ask)
{
	size_t space = args.find(' ');
	if (space == std::string::npos)
		return this->sendrpl(Reply(461, 1, "OPER"), cl_ask->get_fd());   // 461 ERR_NEEDMOREPARAMS "<command> :Not enough parameters"
	if (args.substr(0, space) != cl_ask->getNickname())
		return this->sendrpl(Reply(502), cl_ask->get_fd()); // 502 ERR_USERSDONTMATCH ":Cant change mode for other users"
	if (args.substr(space + 1) != this->password + this->password)
		return this->sendrpl(Reply(464), cl_ask->get_fd());  // 464 ERR_PASSWDMISMATCH ":Password incorrect"
	cl_ask->setFlag(C_OPER);
	return this->sendrpl(Reply(381), cl_ask->get_fd()); 				// 381 RPL_YOUREOPER ":You are now an IRC operator"
}

/* QUIT :<clientRealName>
resp:
	:source ERROR :Closing Link: clientName() (Quit: <clientRealName)
*/
void	Server::quit(std::string args, Client *cl_ask)
{
	std::string resp = ":" + cl_ask->getMask() + " ERROR :Closing Link: " + cl_ask->getNickname() 
		+ " (Quit: " + args + " " + cl_ask->getRealname() + ")\r\n";
	Server::chan_iterator ch_it = this->channels.begin();
	while (ch_it != this->channels.end())
	{
		if (ch_it->second.isOnCh(cl_ask))
		{
			this->part(ch_it->first + " : Quit " + args , cl_ask);
			ch_it = this->channels.begin();
			continue ;
		}
		 ++ch_it;
	}
	send(cl_ask->get_fd(), resp.c_str(), resp.size(), 0);
	FD_CLR(cl_ask->get_fd(), &this->master);
	if (cl_ask->get_fd() == this->fdmax)
		--this->fdmax;
	this->clients.erase(cl_ask->get_fd());
	this->timemap.erase(cl_ask->get_fd());
	delete cl_ask;
	return ;
}

void	Server::squit(std::string args, Client *cl_ask)
{
	if (cl_ask != NULL && cl_ask->checkFlag(C_OPER) == false)
		return this->sendrpl(Reply(481), cl_ask->get_fd()); 				// 481 ERR_NOPRIVILEGES ":Permission Denied- You're not an IRC operator"
	args = ":Server Quitted";
	if (cl_ask != NULL)
		args += " by " + cl_ask->getMask();
	while (this->clients.size())
		this->quit(args, this->clients.begin()->second);
	FD_CLR(this->fd, &this->master);
	return ;
}

