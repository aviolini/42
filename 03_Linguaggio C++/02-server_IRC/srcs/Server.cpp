#include "Server.hpp"

int Server::runSelect()
{
	fd_set read_fds;
	FD_ZERO(&read_fds);
	struct timeval *tout = NULL;
	int qwe = 666;
   	if (std::signal(SIGINT, SIG_IGN) == SIG_ERR || std::signal(SIGQUIT, SIG_IGN) == SIG_ERR)
    	throw ServExc ("signal: error");
	while (FD_ISSET(this->fd, &this->master))
	{
		tout = this->timeout();
		read_fds = this->master;
		if ((qwe=select(this->fdmax + 1, &read_fds, 0, 0, tout)) < 0)
			throw ServExc("select: error\n");
        if (FD_ISSET(STDIN_FILENO, &read_fds))
		{
			std::string s;
			std::cin >> s;
			if (!s.compare("quit") || !s.compare("\0"))
				this->squit(std::string(), 0);
			else
				std::cout << "Enter 'quit' or CTRL-D to exit" << std::endl;
		}
		for (int i = this->fd; i <= this->fdmax; i++)
		{
            if (this->fdmax < MAX_ACCEPT - 1 && FD_ISSET(i, &read_fds) && i == this->fd)
            {
                struct sockaddr_in temp;
                socklen_t tempsize = sizeof(temp);
                int newfd;
                if ((newfd = accept(this->fd, (struct sockaddr *)&temp, &tempsize)) < 0)
                    throw ServExc("accept: error");
                this->clients[newfd] = new	Client(newfd, temp, inet_ntoa(((struct sockaddr_in *)&this->addr_in)->sin_addr));
                this->print_Client_sockaddr(newfd);
				this->timemap[newfd] = TIME_REFILL;
                FD_SET(newfd, &this->master);
                if (newfd > this->fdmax)
                    this->fdmax = newfd;
            }
            if (FD_ISSET(i, &read_fds) && i > this->fd)
            {
                char buffer[BUF_SIZE];
                size_t nbytes = 0;
                bzero(buffer, sizeof(buffer));
                if ((nbytes = recv(i, buffer, BUF_SIZE, 0)) <= 0)
                {
                    if (nbytes < 0)
                        throw ServExc("recv: error");
                    if (nbytes == 0)
                        std::cout << this->clients[i]->getNickname() << " close connection" << std::endl;
					this->quit("caught client sig_int", this->clients[i]);
					continue ;
                }
				this->t_stat.brecv += nbytes;
                if (nbytes == BUF_SIZE && buffer[BUF_SIZE - 2] != '\r' && buffer[BUF_SIZE - 1] != '\n')
				{
					std::string resp = this->Prefix() + "NOTICE " + this->clients[i]->getNickname() \
						+ " :MESSAGE TOO LONG! :undefined behaviour\r\n";
					// 704 RPL_COMMANDSYNTAX // :prefix 704 <target> <command> :text
					resp += this->Prefix() + "704 * char[512]_MESSAGE := [':' <prefix> <SPACE> ] <command> <params> <crlf>\r\n";
					send(i, resp.c_str(), resp.size(), 0);
				}				
				this->clients[i]->cl_msg += buffer;
                if (std::strchr(buffer, '\r') != NULL && std::strchr(buffer, '\n') != NULL)
				{
                	this->serv_resp(this->clients[i]->cl_msg, i);
					if (this->clients.find(i) != this->clients.end())
						this->clients[i]->cl_msg.clear();
					if (FD_ISSET(i, &read_fds) && FD_ISSET(i, &this->master))
						this->timemap[i] = TIME_REFILL;
					++this->t_stat.mrecv;
				}
            }
        }
    }
	std::cout << "...closing connection..." << std::endl;
	return 0;
}

const std::string Server::Prefix() const
{
	char *addr = inet_ntoa(((struct sockaddr_in *)(&this->addr_in))->sin_addr);
	return ":" + static_cast<std::string>(addr) + " ";
}

void Server::setChannel (const std::pair< Server::chan_iterator, bool> &ins_ret, const std::string &key, Client &cl_ask)
{
	Server::chan_node chan = *ins_ret.first;
	int new_chan = ins_ret.second;
	std::string resp;

	if (new_chan)
	{
		ins_ret.first->second.setKey(key);
		ins_ret.first->second.setUser(cl_ask, Flag(U_OPER));
		this->sendstr("JOIN :" + ins_ret.first->first, cl_ask.get_fd(),cl_ask.get_fd());
		this->sendrpl(Reply(332, 2, ins_ret.first->first.c_str(), ins_ret.first->second.getTopic().c_str()), cl_ask.get_fd());  //332 RPL_TOPIC "<channel> :<topic>"
		this->sendrpl(Reply(353, 2, ins_ret.first->first.c_str(), ins_ret.first->second.getUsersNick().c_str()), cl_ask.get_fd()); // 353 RPL_NAMREPLY "<channel> :[[@|+]<nick> [[@|+]<nick> [...]]]"
		this->sendrpl(Reply(366, 1, ins_ret.first->first.c_str()), cl_ask.get_fd()); 	// 366 RPL_ENDOFNAMES "<channel> :End of /NAMES list"	
		return ;
	}
	if (ins_ret.first->second.checkFlag(CH_I) && !ins_ret.first->second.check_invlist(cl_ask.getNickname()))
			return this->sendrpl(Reply(473, 1, ins_ret.first->first.c_str()), cl_ask.get_fd()); // 473 ERR_INVITEONLYCHAN "<channel> :Cannot join channel (+i)"
	if (ins_ret.first->second.checkFlag(CH_K))
	{
		if (key != ins_ret.first->second.getKey())
			return this->sendrpl(Reply(475, 1, ins_ret.first->first.c_str()), cl_ask.get_fd()); // 475     ERR_BADCHANNELKEY "<channel> :Cannot join channel (+k)"
	}
	if (ins_ret.first->second.setUser(cl_ask, Flag()))
	{
		ins_ret.first->second.clear_invlist(cl_ask.getNickname());
		this->sendstrchan("JOIN :" + ins_ret.first->first, ins_ret.first->second, cl_ask.get_fd());
		resp.clear();
		this->sendrpl(Reply(332, 2, ins_ret.first->first.c_str(), ins_ret.first->second.getTopic().c_str()), cl_ask.get_fd());  //332 RPL_TOPIC "<channel> :<topic>"
		this->sendrpl(Reply(353, 2, ins_ret.first->first.c_str(), ins_ret.first->second.getUsersNick().c_str()), cl_ask.get_fd()); // 353 RPL_NAMREPLY "<channel> :[[@|+]<nick> [[@|+]<nick> [...]]]"
		this->sendrpl(Reply(366, 1, ins_ret.first->first.c_str()), cl_ask.get_fd()); 	// 366 RPL_ENDOFNAMES "<channel> :End of /NAMES list"	
		return ;
	}
	return this->sendrpl(Reply(443, 2, cl_ask.getNickname().c_str(), ins_ret.first->first.c_str()), cl_ask.get_fd()); // 443 ERR_USERONCHANNEL "<user> <channel> :is already on channel"
}

int Server::serv_resp(std::string buffer, const int &cl_fd)
{
	std::string msg, cmd, args;
	size_t space = 0;

	for (size_t crlf = 0; buffer.size() && crlf != buffer.size();)
	{
		crlf = buffer.find("\n") != std::string::npos ? buffer.find("\n") : buffer.size();
		msg = buffer.substr(0, crlf);
		while (*msg.rbegin() == '\r' || *msg.rbegin() == '\n')
			msg.erase(msg.end() - 1);
		if (msg.size() == 0)
			return 0;
		space = msg.find(' ');
		if (msg[0] == ':')
			msg.erase(0, space + 1);
		space = msg.find(' ') != std::string::npos ? msg.find(' ') : msg.size();
		cmd = msg.substr(0, space);
		CmdParser(cmd);
		args = space != msg.size() ? msg.substr(space + 1) : "";
		ParamsParser(args);
		if (cmd.size() != 0)
			this->check_cmd(cmd, args, cl_fd);
		buffer = crlf != buffer.size() ? buffer.substr(crlf + 1) : "";
		if (cmd == "QUIT")
			return 0;
	}
	return 0;
}

void Server::check_cmd(const std::string & cmd, std::string args, const int &cl_fd)
{
	std::string reg_str [] = { "CAP", "PASS", "NICK", "USER", "PING", "QUIT", "SQUIT", "PONG", "HELP", "BOT" };
	std::string usr_str [] = { "JOIN", "WHO", "MODE", "PRIVMSG",
		 "LIST", "PART", "TOPIC", "NAMES", "INVITE", "KICK", "OPER", "NOTICE", "KILL", "WHOIS",
		 "MOTD", "LUSERS", "VERSION", "STATS", "LINKS", "TIME", "CONNECT", "TRACE", "ADMIN", "INFO" };
	if (!CmdExists(cmd, reg_str, sizeof(reg_str)) && !CmdExists(cmd, usr_str, sizeof(usr_str)))
		return this->sendrpl(Reply(421, 1, cmd.c_str()), cl_fd); 							// 421 ERR_UNKNOWNCOMMAND "<command> :Unknown command"		
	std::cout << "cmd -" << cmd << "-<"<< args << ">-" << cl_fd <<std::endl;
	if (args == "" && cmd != "LIST" && cmd != "SQUIT"
	 && cmd != "MOTD" && cmd != "LUSERS" && cmd != "VERSION"
	 && cmd != "STATS"&& cmd != "LINKS"
	 && cmd != "TIME"&& cmd != "CONNECT"
	 && cmd != "TRACE"&& cmd != "ADMIN"&& cmd !="INFO")
		return this->sendrpl(Reply(461, 1, cmd.c_str()), cl_fd); 						// 461 ERR_NEEDMOREPARAMS "<command> :Not enough parameters"

	Server::cl_iterator cl_it = this->clients.find(cl_fd);
	Client *cl_ask = cl_it->second;

	void (Server::*reg_cmds[])(std::string, Client *) = \
		{&Server::cap, &Server::pass, &Server::nick, &Server::user, &Server::ping, &Server::quit, &Server::squit, &Server::pong, &Server::help, &Server::setbot};

	for (unsigned long i = 0; i < sizeof(reg_str)/sizeof(std::string); ++i)
		if (reg_str[i].compare(cmd) == 0)
			return (this->*reg_cmds[i])(args, cl_ask);

	if (cl_ask->isReg())
	{
		void (Server::*usr_cmds[])(std::string, Client *) = \
			{&Server::join, &Server::who, &Server::mode, &Server::privmsg,
			 &Server::list, &Server::part, &Server::topic, &Server::names,
			 &Server::invite, &Server::kick, &Server::oper, &Server::notice, &Server::kill, &Server::whois,
			 &Server::motd, &Server::lusers, &Server::version, &Server::stats, &Server::links,
			 &Server::srvtime, &Server::srvconnect, &Server::srvtrace, &Server::srvadmin, &Server::srvinfo};
		for (unsigned long i = 0; i < sizeof(usr_str)/sizeof(std::string); ++i)
			if (usr_str[i].compare(cmd) == 0)
				return (this->*usr_cmds[i])(args, cl_ask);
	}
	return this->sendrpl(Reply(451), cl_fd);										// 451 ERR_NOTREGISTERED ":You have not registered"
}

Server::cl_iterator Server::findClient(const std::string &nick)
{
	Server::cl_iterator cl_it = this->clients.begin();
	for ( ; cl_it != this->clients.end(); ++cl_it)
		if (cl_it->second->getNickname().compare(nick) == 0)
			return cl_it;
	return this->clients.end();
}

struct timeval* Server::timeout( void )
{
	this->timemap.update_ko();
	for (size_t x = 0; x < this->timemap.size() && this->timemap.expired && this->timemap.expired[x] != 0; ++x) 
	{
		if (this->clients[this->timemap.expired[x]]->checkFlag(C_PINGED) == false)
		{
			this->clients[this->timemap.expired[x]]->setFlag(C_PINGED);
			this->sendstr( "PING :checking Connection", this->timemap.expired[x]);
			this->timemap[this->timemap.expired[x]] = TIME_REFILL;
		}
		else
		{
			this->quit("Killed by Server :timeout connection", this->clients[this->timemap.expired[x]]);
			this->timemap.erase(this->timemap.expired[x]);
		}
	}
	delete [] this->timemap.expired;
	this->timemap.expired = NULL;
	return this->timemap.last_ko();
}

void Server::sendrpl(const Reply & r, const int & cl_fd)
{
	Server::const_cl_iterator cl_it = this->clients.find(cl_fd);
	std::string resp = this->Prefix() + r.getnreply() + cl_it->second->getNickname() + r;
	int ret;
	if ((ret = send(cl_fd, resp.c_str(), resp.size(), 0)) < 0)
		throw ServExc("error:send");
	this->t_stat.bsent += static_cast<size_t>(ret);
	++this->t_stat.msent;
	if(r.nreply == 461 || (r.nreply == 421 && cl_it->second->checkFlag(C_BOT)))
		this->help(r.get461(), this->clients[cl_fd]);
	return ;
}

void Server::sendrplchan(const Reply & r, const int & cl_fd, const Channel & channel, const int &except)
{
	std::string resp = this->Prefix() + r.getnreply() + this->clients.find(cl_fd)->second->getNickname() + r;
	for (Channel::const_usr_iterator usr_it = channel.users.begin(); usr_it != channel.users.end(); ++usr_it)
	{
		if (usr_it->first->get_fd() != except)
		{
			int ret;
			if ((ret = send(usr_it->first->get_fd(), resp.c_str(), resp.size(), 0)) < 0)
				throw ServExc("error:send");
			this->t_stat.bsent += static_cast<size_t>(ret);
			++this->t_stat.msent;
		}
	}
	return ;
}

void Server::sendstr(const std::string & s, const int & cl_fd, const int & prefix_fd)
{
	std::string resp;
	if (!prefix_fd)	
		resp = this->Prefix() + s + "\r\n";
	else if (prefix_fd == -1)
		resp = ":bot!helper@127.0.1.1 " + s + "\r\n";
	else
		resp = ":" + this->clients.find(prefix_fd)->second->getMask() + " " + s + "\r\n";
	int ret;
	if ((ret = send(cl_fd, resp.c_str(), resp.size(), 0)) < 0)
		throw ServExc("error:send");
	this->t_stat.bsent += static_cast<size_t>(ret);
	++this->t_stat.msent;
	return ;
}

void Server::sendstrchan(const std::string & s, const Channel & channel, const int & prefix_fd, const int &except)
{
	std::string resp;
	if (!prefix_fd)	
		resp = this->Prefix() + s + "\r\n";
	else
		resp = ":" + this->clients.find(prefix_fd)->second->getMask() + " " + s + "\r\n";
	for (Channel::const_usr_iterator usr_it = channel.users.begin(); usr_it != channel.users.end(); ++usr_it)
	{
		if (usr_it->first->get_fd() != except)
		{
			int ret;
			if ((ret = send(usr_it->first->get_fd(), resp.c_str(), resp.size(), 0)) < 0)
				throw ServExc("error:send");
			this->t_stat.bsent += static_cast<size_t>(ret);
			++this->t_stat.msent;
		}
	}
	return ;
}

void Server::print_Server_addrinfo () const
{
	struct addrinfo *tmp = this->res;
	while (tmp)
	{
		std::cout << "--SERVER ADDRINFO--FD:"<< this->fd << "---" << std::endl;
        std::cout << "AI_FAMILY:\t" << tmp->ai_family << std::endl;
        std::cout << "AI_SOCKTYPE:\t" << tmp->ai_socktype << std::endl;
        std::cout << "AI_PROTOCOL:\t" << tmp->ai_protocol << std::endl;
        std::cout << "AI_ADDRLEN:\t" << tmp->ai_addrlen << std::endl;
		std::cout << "SOCKET ADDRESS:\t" << inet_ntoa(((struct sockaddr_in *)(tmp->ai_addr))->sin_addr) << std::endl;
		std::cout << "SOCKET PORT:\t" << ntohs( ((struct sockaddr_in *)(tmp->ai_addr))->sin_port) << std::endl;
		tmp = tmp->ai_next;
	}
	std::cout << "--------------------------" << std::endl; 
}

void Server::print_Client_sockaddr(const int & fd) const
{
	struct sockaddr_in tmp_addr_in = this->clients.find(fd)->second->addr_in;

	std::cout << "--CLIENT ADDRINFO--FD:"<< fd << "---" << std::endl;
	std::cout << "NO_FD SOCKET:\t" << fd << std::endl;
	std::cout << "SOCKET FAMILY:\t" << tmp_addr_in.sin_family << std::endl;
	std::cout << "SOCKET ADDRESS:\t" << inet_ntoa(tmp_addr_in.sin_addr) << std::endl;
	std::cout << "SOCKET PORT:\t" << ntohs( tmp_addr_in.sin_port) << std::endl;
	std::cout << "HOSTNAME:\t" << this->clients.find(fd)->second->getHostname() << std::endl;
	std::cout << "--------------------------" << std::endl; 
}
