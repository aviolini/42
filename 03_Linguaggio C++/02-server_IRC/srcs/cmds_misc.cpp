#include "Server.hpp"

void	Server::setbot(std::string args, Client *cl_ask)
{
	if (args[0] == '+')
	{
		if (cl_ask->checkFlag(C_BOT))
			return ;
		cl_ask->setFlag(C_BOT);
		return this->sendstr("PRIVMSG " + cl_ask->getNickname() + " :HI, I'm the BOT HELPER!! I'll give you some tips during your journey! DONT REPLY :)", cl_ask->get_fd(), -1);
	}
	else if (args[0] == '-')
	{
		if (cl_ask->checkFlag(C_BOT) == false)
			return ;
		cl_ask->clearFlag(C_BOT);	
		return this->sendstr("PRIVMSG " + cl_ask->getNickname() + " :Adios, have a nice day!", cl_ask->get_fd(), -1);
	}
	return this->sendrpl(Reply(472, 2, args.c_str(), "BOT"), cl_ask->get_fd()); // 315 RPL_ENDOFWHO "<name> :End of /WHO list"
}

void	Server::ping(std::string args, Client *cl_ask)
{
	args = " " + args;
	args = SERV_NAME + args;
	return this->sendstr("PONG " + args, cl_ask->get_fd());
}

void	Server::pong(std::string args, Client *cl_ask)
{
	cl_ask->clearFlag(C_PINGED);
	(void)args;
	return ;
}

// 352: RPL_WHOREPLY [I,E,U,D]	
	//:prefix 352 target <chan> <usr> <hst> <srv> <nck> <stat> :<hops> <real>
// 315: RPL_ENDOFWHO [I,E,U,D]
	// :prefix 315 target <channel/nick> :End of /WHO List.
/* WHO <channel>
resp:
	:server 352 clientNick() <channel> clientUserName() clientHost() clientServer() clientNick() clientMode() :<hops=0> clientRealName()
	:server 352 clientNick() <channel> otherUserUserName() otherUserHost() otherUserServer() otherUserNick() otherUserMode() :<hops=0> otherUserRealName()
	:server 352 clientNick() <channel> otherUserUserName() otherUserHost() otherUserServer() otherUserNick() otherUserMode() :<hops=0> otherUserRealName()
	...
	:server 315 clientNick() <channel> ":End of /WHO list"
*/
void	Server::who(std::string args, Client *cl_ask)
{
	size_t start = args.find(" ") != std::string::npos ? args.find(" ") : args.size();
	if (args[0] == '#')
	{
		Server::chan_iterator ch_it = this->channels.find(args.substr(0, start));
		if (ch_it == this->channels.end())
			return this->sendrpl(Reply(403, 1, args.substr(0, start).c_str()), cl_ask->get_fd()); // 403 ERR_NOSUCHCHANNEL "<channel name> :No such channel"
		for (Channel::usr_iterator usr_it = ch_it->second.users.begin(); usr_it != ch_it->second.users.end(); ++usr_it)
		{
			this->sendrpl(Reply(352, 9, args.substr(0,start).c_str(), // 352 RPL_WHOREPLY "<channel> <user> <host> <server> <nick> ( "H" / "G" > ["*"] [ ( "@" / "+" ) ] :<hopcount> <real name>"
										usr_it->first->getUsername().c_str(),
										usr_it->first->getHostname().c_str(),
										usr_it->first->getServername().c_str(),
										usr_it->first->getNickname().c_str(),
										usr_it->first->checkFlag(C_OPER)?"*":"",
										ch_it->second.printUsrFlag(usr_it->first).c_str(), "0",
										usr_it->first->getRealname().substr(1).c_str())
								, cl_ask->get_fd());
		}
		return this->sendrpl(Reply(315, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 315 RPL_ENDOFWHO "<name> :End of /WHO list"
	}
	if (args.size())
	{
		std::string resp;
		Server::cl_iterator cl_it = this->findClient(args.substr(0, start));
		if (cl_it == this->clients.end())
			return this->sendrpl(Reply(401, 1, args.substr(0, start).c_str()), cl_ask->get_fd()); // 401 ERR_NOSUCHNICK "<nickname> :No such nick/channel"
		this->sendrpl(Reply(352, 9, "*", // 352 RPL_WHOREPLY "<channel> <user> <host> <server> <nick> ( "H" / "G" > ["*"] [ ( "@" / "+" ) ] :<hopcount> <real name>"
									cl_it->second->getUsername().c_str(),
									cl_it->second->getHostname().c_str(),
									cl_it->second->getServername().c_str(),
									cl_it->second->getNickname().c_str(),
									cl_it->second->checkFlag(C_OPER)?"*":"",
									"", "0",
									cl_it->second->getRealname().substr(1).c_str())
							, cl_ask->get_fd());
		this->sendrpl(Reply(315, 1, cl_it->second->getNickname().c_str()), cl_ask->get_fd()); // 315 RPL_ENDOFWHO "<name> :End of /WHO list"
	}
	return ;
}

//	:source PRIVMSG <target> :<message>
void	Server::privmsg(std::string args, Client *cl_ask) 
{
	size_t start = args.find(" ");
	if (args[0] == '#' || args[0] == '&' || args[0] == '+' || args[0] == '!')
	{
		Server::chan_iterator ch_it = this->channels.find(args.substr(0, start));
		if (ch_it == this->channels.end())
			return this->sendrpl(Reply(403, 1, args.substr(0, start).c_str()), cl_ask->get_fd()); // 403 ERR_NOSUCHCHANNEL "<channel name> :No such channel"
		start = args.find(":");
		if (start == std::string::npos)
			return this->sendrpl(Reply(412), cl_ask->get_fd()); // 412 ERR_NOTEXTTOSEND ":No text to send"
		if (ch_it->second.checkFlag(CH_N) && ch_it->second.isOnCh(cl_ask) == false)
			return this->sendrpl(Reply(404, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 404 ERR_CANNOTSENDTOCHAN "<channel name> :Cannot send to channel"
		return this->sendstrchan("PRIVMSG " + args.substr(0, start) + " " + args.substr(start), ch_it->second, cl_ask->get_fd(), cl_ask->get_fd());
	}
	Server::cl_iterator cl_it = this->findClient(args.substr(0, start));	
	if (cl_it == this->clients.end())
		return this->sendrpl(Reply(401, 1, args.substr(0, start).c_str()), cl_ask->get_fd()); // 401 ERR_NOSUCHNICK "<nickname> :No such nick/channel"
	start = args.find(":");
	if (start == std::string::npos)
		return this->sendrpl(Reply(412), cl_ask->get_fd()); // 412 ERR_NOTEXTTOSEND ":No text to send"
	return this->sendstr("PRIVMSG " + args.substr(0, start) + " " + args.substr(start), cl_it->first, cl_ask->get_fd());
}

//	:source NOTICE <target> :<message>
void	Server::notice(std::string args, Client *cl_ask) 
{
	size_t start = args.find(" ");
	if (args[0] == '#' || args[0] == '&' || args[0] == '+' || args[0] == '!')
	{
		Server::chan_iterator ch_it = this->channels.find(args.substr(0, start));
		if (ch_it == this->channels.end())
			return this->sendrpl(Reply(403, 1, args.substr(0, start).c_str()), cl_ask->get_fd()); // 403 ERR_NOSUCHCHANNEL "<channel name> :No such channel"
		start = args.find(":");
		if (start == std::string::npos)
			return this->sendrpl(Reply(412), cl_ask->get_fd()); // 412 ERR_NOTEXTTOSEND ":No text to send"
		return this->sendstrchan("NOTICE " + args.substr(0, start) + " " + args.substr(start), ch_it->second, cl_ask->get_fd(), cl_ask->get_fd());
	}
	Server::cl_iterator cl_it = this->findClient(args.substr(0, start));	
	if (cl_it == this->clients.end())
		return ; //no such client
	start = args.find(":");
	if (start == std::string::npos)
		return this->sendrpl(Reply(412), cl_ask->get_fd()); // 412 ERR_NOTEXTTOSEND ":No text to send"
	return this->sendstr("NOTICE " + args.substr(0, start) + " " + args.substr(start), cl_it->first, cl_ask->get_fd());
}

//	KILL <nick> <reason>
// resp:
//	:source ERROR :Closing Link: clientName() (Quit: <clientRealName)
void	Server::kill(std::string args, Client *cl_ask)
{
	if (cl_ask->checkFlag(C_OPER) == false)
		return this->sendrpl(Reply(481), cl_ask->get_fd()); // 481 ERR_CHANOPRIVSNEEDED "<channel> :You're not channel operator"
	size_t colon = args.find(':');
	if (colon == std::string::npos)
		return this->sendrpl(Reply(461, 1, "KILL"), cl_ask->get_fd());   // 461 ERR_NEEDMOREPARAMS "<command> :Not enough parameters"
	Server::cl_iterator cl_it = this->findClient(args.substr(0, colon - 1));
	if (cl_it == this->clients.end())
		return this->sendrpl(Reply(401, 1, args.substr(0, colon - 1).c_str()), cl_ask->get_fd()); // 401 ERR_NOSUCHNICK "<nickname> :No such nick/channel"
	return this->quit("Killed by " + cl_ask->getNickname() + args.substr(colon - 1), cl_it->second);
}

//WHOIS [<server> | <nick>] <nick>
void	Server::whois(std::string args, Client *cl_ask)
{
	size_t space = args.find_last_of(' ') != std::string::npos ? args.find_last_of(' ') + 1 : 0;
	Server::cl_iterator cl_it = this->findClient(args.substr(space));
	if (cl_it == this->clients.end())
		return this->sendrpl(Reply(401, 1, args.substr(space).c_str()), cl_ask->get_fd()); // 401 ERR_NOSUCHNICK "<nickname> :No such nick/channel"
	this->sendrpl(Reply(311, 4, cl_it->second->getNickname().c_str(),  // 311 RPL_WHOISUSER "<nick> <user> <host> * :<real name>"
								cl_it->second->getUsername().c_str(),
								cl_it->second->getHostname().c_str(),
								cl_it->second->getRealname().c_str()),
							cl_ask->get_fd());
	this->sendrpl(Reply(312, 3, cl_it->second->getNickname().c_str(),  // 312 RPL_WHOISSERVER "<nick> <server> :<server info>"
								this->Prefix().substr(1).c_str(),
								SERV_NAME),//"SERVER DESCRIPTION"),
							cl_ask->get_fd());
	if (cl_it->second->checkFlag(C_OPER))
		this->sendrpl(Reply(313, 1, cl_it->second->getNickname().c_str()), cl_ask->get_fd()); // 313 RPL_WHOISOPERATOR "<nick> :is an IRC operator"
	std::string chan_list;
	for ( Server::chan_iterator ch_it = this->channels.begin(); ch_it != this->channels.end(); ++ch_it)
		if (ch_it->second.isOnCh(cl_it->second))
			chan_list += ch_it->first + " ";
	if (!chan_list.empty())
		this->sendrpl(Reply(319, 2, cl_it->second->getNickname().c_str(), chan_list.c_str()), cl_ask->get_fd()); // 319 RPL_WHOISCHANNELS "<nick> :{[@|+]<channel><space>}"
	return this->sendrpl(Reply(318, 1, cl_it->second->getNickname().c_str()), cl_ask->get_fd()); // 318 RPL_ENDOFWHOIS "<nick> :End of /WHOIS list"
}
