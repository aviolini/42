#include "Server.hpp"

void	Server::help(std::string args, Client *cl_ask)
{
	CmdParser(args);
	CHelp::helpMap::iterator help_it = this->helper.find(args);
	if (help_it == this->helper.end())
	{
		return this->sendrpl(Reply(705, 2, "HELP", this->helper["HELP"].second.c_str()), cl_ask->get_fd());
	}
	if (cl_ask->checkFlag(C_BOT) == false)
		return this->sendrpl(Reply(704, 2, help_it->first.c_str(), help_it->second.first.c_str()), cl_ask->get_fd());
	this->sendstr("PRIVMSG " + cl_ask->getNickname() + help_it->second.first.c_str(), cl_ask->get_fd(), -1);
	return this->sendstr("PRIVMSG " + cl_ask->getNickname() + help_it->second.second.c_str(), cl_ask->get_fd(), -1);

}
