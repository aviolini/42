#include "Server.hpp"

// :prefix 375 target : - <server> Message of the Day -
// :prefix 372 target : - <motd>
// :prefix 376 target :End of /MOTD command.
// :prefix 422 <target> :- MOTD file not found!  Please contact your IRC administrator.
void	Server::motd(std::string args, Client *cl_ask)
{
    size_t colon = args.find(':');
    if (colon != std::string::npos && cl_ask->checkFlag(C_OPER))
        this->msgotd = args.substr(colon + 1);
    this->sendrpl(Reply(375, 1, inet_ntoa(((struct sockaddr_in *)(&this->addr_in))->sin_addr)), cl_ask->get_fd());
    this->sendrpl(Reply(372, 1, this->msgotd.c_str()), cl_ask->get_fd());
    return this->sendrpl(Reply(376), cl_ask->get_fd());
}

void	Server::lusers(std::string args, Client *cl_ask)
{
    size_t op = 0;
    size_t notreg = 0;
    for (Server::cl_iterator cl_it = this->clients.begin(); cl_it != this->clients.end(); ++cl_it)
    {
        if (cl_it->second->checkFlag(C_OPER))
            ++op;
        if (cl_it->second->isReg() == false)
            ++notreg;        
    }
    args = itao(this->clients.size());
    this->sendrpl(Reply(251, 3, args.c_str(), "0", "1"), cl_ask->get_fd());
    if (op)
    {
        args = itao(op);
        this->sendrpl(Reply(252, 1, args.c_str()), cl_ask->get_fd());
    }
    if (notreg)
    {
        args = itao(notreg);
        this->sendrpl(Reply(253, 1, args.c_str()), cl_ask->get_fd());
    }
    args = itao(this->channels.size());
    this->sendrpl(Reply(254,1,args.c_str()), cl_ask->get_fd());
    args = itao(this->clients.size());
    return this->sendrpl(Reply(255, 2, args.c_str(), "0"), cl_ask->get_fd());
}

void	Server::version(std::string args, Client *cl_ask)
{
		(void)args;
	(void)cl_ask;
    return this->sendrpl(Reply(351, 4, VERS, DBG,
         SERV_NAME, VERS2), cl_ask->get_fd());
}

// 211 "<linkname> <sendq> <sent messages> <sent Kbytes> <received messages> <received Kbytes> <time open>");	//RPL_STATSLINKINFO
void	Server::stats(std::string args, Client *cl_ask)
{
    if (args.empty())
        return this->sendrpl(Reply(219, 1, "l"), cl_ask->get_fd());
    if (args[0] == 'l')
    {
        this->sendrpl(Reply(211, 7, SERV_NAME, "0", itao(this->t_stat.msent).c_str(), itao(this->t_stat.bsent).c_str(),
                itao(this->t_stat.mrecv).c_str(), itao(this->t_stat.brecv).c_str(), __DATE__), cl_ask->get_fd());
        return this->sendrpl(Reply(219, 1, "l"), cl_ask->get_fd());
    }
    else
        return this->sendrpl(Reply(481), cl_ask->get_fd());
}

//  364 : MESS( "<mask> <server> :<hopcount> <server info>" );															//RPL_LINKS
// case 365 : MESS( "<mask> :End of LINKS list" );	
void	Server::links(std::string args, Client *cl_ask)
{
    args = __TIME__;
    args = "server created " + args;
    this->sendrpl(Reply(364, 4, "*", SERV_NAME, "0", args.c_str()), cl_ask->get_fd());
    return this->sendrpl(Reply(365, 1, "*"), cl_ask->get_fd());
}

// case 391 : MESS( "<server> :<string showing server's local time>" );													//RPL_TIME
void	Server::srvtime(std::string, Client *cl_ask)
{
    time_t rawtime;
    time (&rawtime);
    return this->sendrpl(Reply(391, 2, SERV_NAME, std::ctime(&rawtime)), cl_ask->get_fd());
}

void	Server::srvconnect(std::string args, Client *cl_ask)
{
	(void)args;
    return this->sendrpl(Reply(481), cl_ask->get_fd()); //481 permission denied
}

void	Server::srvtrace(std::string args, Client *cl_ask)
{
    // case 204 : MESS( "Oper <class> <nick>" );																				//RPL_TRACEOPERATOR
	// case 205 : MESS( "User <class> <nick>" );
	// case 262 : MESS( "<server name> <version & debug level> :End of TRACE" );												//RPL_TRACEEND
    for (Server::cl_iterator cl_it = this->clients.begin(); cl_it != this->clients.end(); ++cl_it)
    {
        if (cl_it->second->checkFlag(C_OPER))
            this->sendrpl(Reply(204, 2, "O", cl_it->second->getNickname().c_str()), cl_ask->get_fd());
        else
            this->sendrpl(Reply(205, 2, "U", cl_it->second->getNickname().c_str()), cl_ask->get_fd());
    }
    args = VERS;
    args += DBG;
    return this->sendrpl(Reply(262, 2, SERV_NAME, args.c_str()), cl_ask->get_fd());
}

void	Server::srvadmin(std::string args, Client *cl_ask)
{
    // 256    RPL_ADMINME  "<server> :Administrative info"
    // 257    RPL_ADMINLOC1    ":<admin info>"  // server administrative info
    // 258    RPL_ADMINLOC2  ":<admin info>" // admin,city,state,country
    // 259    RPL_ADMINEMAIL    ":<admin info>"
    this->sendrpl(Reply(256, 1, SERV_NAME), cl_ask->get_fd());
    args = AD1;
    this->sendrpl(Reply(257, 1, args.c_str()), cl_ask->get_fd());
    args = AD2;
    this->sendrpl(Reply(258, 1, args.c_str()), cl_ask->get_fd());
    args = ADMAIL;
    return this->sendrpl(Reply(259, 1, args.c_str()), cl_ask->get_fd());
}

void	Server::srvinfo(std::string args, Client *cl_ask)
{
	args = INFO0;
    this->sendrpl(Reply(371, 1, INFO0), cl_ask->get_fd());
    args = INFO1;
    this->sendrpl(Reply(372, 1, args.c_str()), cl_ask->get_fd());
	args = INFO2;
    this->sendrpl(Reply(372, 1, args.c_str()), cl_ask->get_fd());
    args = "Server is up since: ";
    args += __DATE__;
    args += " ";
    args += __TIME__;
    this->sendrpl(Reply(372, 1, args.c_str()), cl_ask->get_fd());
	args = INFO3;
    this->sendrpl(Reply(372, 1, args.c_str()), cl_ask->get_fd());
	args = INFO4;
    this->sendrpl(Reply(372, 1, args.c_str()), cl_ask->get_fd());
    return this->sendrpl(Reply(374), cl_ask->get_fd());

}

void	Server::welcome(std::string args, Client *cl_ask)
{
	(void)args;
	(void)cl_ask;
	this->sendrpl(Reply(001, 3, cl_ask->getNickname().c_str(), cl_ask->getUsername().c_str(),
	cl_ask->getHostname().c_str()), cl_ask->get_fd());						// 001 RPL_WELCOME "Welcome to the Internet Relay Network <nick>!<user>@<host>"	
	this->sendrpl(Reply(002, 2, SERV_NAME, VERS),cl_ask->get_fd()); 		//002 RPL_YOURHOST "Your host is <servername>, running version <ver>"
	this->sendrpl(Reply(003, 1, __DATE__),cl_ask->get_fd()); 				//003 RPL_CREATED "This server was created <date>"
	this->lusers(std::string(), cl_ask);
	this->sendrpl(Reply(221, 1, cl_ask->printFlag().c_str()), cl_ask->get_fd()); 			// 221 RPL_UMODEIS "<user mode string>"
	this->motd(std::string(), cl_ask);
	return ;
}
