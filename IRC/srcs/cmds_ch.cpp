#include "Server.hpp"

/* JOIN <channel>
resp:
	:clientmask() JOIN :<channel>
	:server() 332 clientNick() <channel> :topic
	:server() 333 clientNick() <channel> nickofwhosettedtopic() timewhensettedtopic()
	:server() 353 clientNick() [=|*|@] <channel> :<space_separated_list_of_nicks>	// = --> public  * --> private   @ --> secret
	:server() 366 clientNick() <channel> ":End of /NAMES list"
*/
void	Server::join(std::string args, Client *cl_ask)
{
	Server::chan_node chan;
	std::string keys = args.find(' ') != std::string::npos ? args.substr(args.find(' ') +1) : "";
	size_t key_com = keys.find(',') != std::string::npos ? keys.find(',') : keys.size();
	if (keys.size())
		args = args.substr(0, args.find(" "));
	size_t comma = args.find(',') != std::string::npos ? args.find(',') : args.size();

	while (args.size())
	{
		chan = Server::chan_node(ChParser(args.substr(0, comma)), Channel());
		std::pair< Server::chan_iterator, bool> ins_ret = this->channels.insert(chan);
		this->setChannel(ins_ret, keys.substr(0, key_com), *cl_ask);
		keys = key_com != keys.size() ? keys.substr(key_com + 1) : "";
		key_com = keys.find(',') != std::string::npos ? keys.find(',') : keys.size();
		args = comma != args.size() ? args.substr(comma + 1) : "";
		comma = args.find(',') != std::string::npos ? args.find(',') : args.size();
	}
	return ;
}

/* PART <channel>[,<channel>,..] :reason
resp:
	// :<source_mask> PART <channel> :<part message>
*/
void	Server::part(std::string args, Client *cl_ask)
{
	size_t comma;
	size_t colon = args.find(' ');
	std::string msg = colon != std::string::npos ? args.substr(colon) : " :for no reason..";
	Server::chan_iterator ch_it;

	args = args.substr(0, colon);
	while (args.size())
	{
		comma = args.find(',') != std::string::npos ? args.find(',') : args.size();
		ch_it = this->channels.find(ChParser(args.substr(0, comma)));
		if (ch_it == this->channels.end())
			return this->sendrpl(Reply(403, 1, args.substr(0, comma).c_str()), cl_ask->get_fd()); // 403 ERR_NOSUCHCHANNEL "<channel name> :No such channel"
		if (ch_it->second.partCh(cl_ask) == false)
			return this->sendrpl(Reply(442, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 442 ERR_NOTONCHANNEL "<channel> :You're not on that channel"
		this->sendstrchan(" PART " + ch_it->first + msg, ch_it->second, cl_ask->get_fd());
		this->sendstr(" PART " + ch_it->first + msg, cl_ask->get_fd(),  cl_ask->get_fd());
		if (ch_it->second.UsrNbr() == "0")
			this->channels.erase(ch_it->first);
		args = comma != args.size() ? args.substr(comma + 1) : "";
	}
	return ;
}

/* MODE <channel>
resp:
	:server 324 clientNick() <channel> +mode
	:server 329 clientNick() <channel> time of creation

2. MODE <channel> b
resp:
	:server 368 clientNick() <channel> ":End of Channel Ban List"
*/

void	Server::mode(std::string args, Client *cl_ask)
{
	size_t start = args.find(" ") != std::string::npos ? args.find(" ") : args.size();
	if (args[0] == '#' || args[0] == '&' || args[0] == '+' || args[0] == '!')
	{
		Server::chan_iterator ch_it = this->channels.find(args.substr(0, start));
		if (ch_it == this->channels.end())
			return this->sendrpl(Reply(403, 1, args.substr(0, start).c_str()),cl_ask->get_fd()); // 403 ERR_NOSUCHCHANNEL "<channel name> :No such channel"
		if (start == args.size())
			return this->sendrpl(Reply(324, 3, ch_it->first.c_str(), ch_it->second.printFlag().c_str(), ""), cl_ask->get_fd()); // 324 RPL_CHANNELMODEIS "<channel> <mode> <mode params>"
		args.erase(0,start + 1);
		if (args[0] == 'b')
			return ;
		if (!ch_it->second.checkUsrFlag(cl_ask, U_OPER))
			return this->sendrpl(Reply(482, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 482 ERR_CHANOPRIVSNEEDED "<channel> :You're not channel operator"
		char set = '+';
		while (args[0] == '-' || args[0] == '+')
		{
			set = args[0];
			args.erase(0,1);
		}
		while(!args.empty())
		{
			if (args[0] == 'o')					//CHANOP
			{
				args.erase(0,1);
				if (args[0] != ' ')
					return ;
				args.erase(0,1);
				std::string nick = args.substr(0, args.find(" "));
				if (ch_it->second.isOnCh(nick) == 0)
					return this->sendrpl(Reply(401, 1, nick.c_str()), cl_ask->get_fd()); // 401 ERR_NOSUCHNICK "<nickname> :No such nick/channel"
				if ((set == '+' && !ch_it->second.checkUsrFlag(args, U_OPER)) || (set == '-' && ch_it->second.checkUsrFlag(args, U_OPER)))
					for (Channel::usr_iterator usr_it = ch_it->second.users.begin(); usr_it != ch_it->second.users.end(); ++usr_it)
						this->sendstr(" MODE " + ch_it->first + " " + set + "o " + nick , usr_it->first->get_fd());
				if (set == '+')
					ch_it->second.setUsrFlag(args, U_OPER);
				else
					ch_it->second.clearUsrFlag(args, U_OPER);
				return ;
			}
			else if (args[0] == 'k')			//KEY
			{
				args.erase(0,1);
				if (args[0] != ' ')
					return ;
				args.erase(0,1);
				std::string pass = args.substr(0, args.find(" "));
				if (set == '+')
				{
					if (ch_it->second.getKey().compare(pass) != 0)
						for (Channel::usr_iterator usr_it = ch_it->second.users.begin(); usr_it != ch_it->second.users.end(); ++usr_it)
							this->sendstr(" MODE " + ch_it->first + " +k " + pass , usr_it->first->get_fd());
					ch_it->second.setFlag(CH_K);
					ch_it->second.setKey(args);
				}
				else
				{
					if (ch_it->second.checkFlag(CH_K))
						for (Channel::usr_iterator usr_it = ch_it->second.users.begin(); usr_it != ch_it->second.users.end(); ++usr_it)
							this->sendstr(" MODE " + ch_it->first + " -k ", usr_it->first->get_fd());
					ch_it->second.clearFlag(CH_K);
					ch_it->second.setKey(std::string());
				}
				return ;
			}
			else if (args[0] == 'i' || args[0] == 't' || args[0] == 'n')  //INVITE ONLY //TOPIC //ONLY MEMBERS
			{
				unsigned char flag = CH_I;
				if (args[0] == 't')
					flag = CH_T;
				else if (args[0] == 'n')
					flag = CH_N;
				if ((set == '+' && !ch_it->second.checkFlag(flag)) || (set == '-' && ch_it->second.checkFlag(flag)))
					for (Channel::usr_iterator usr_it = ch_it->second.users.begin(); usr_it != ch_it->second.users.end(); ++usr_it)
						this->sendstr(" MODE " + ch_it->first + " " + set + args[0] , usr_it->first->get_fd());
				if (set == '+')
					ch_it->second.setFlag(flag);
				else
					ch_it->second.clearFlag(flag);
			}
			else
			{
				char s[2] = {args[0], '\0'};
				this->sendrpl(Reply(472, 2, s, ch_it->first.c_str()), cl_ask->get_fd());  // 472 ERR_UNKNOWNMODE "<char> :is unknown mode char to me for <channel>"
			}
			args.erase(0,1);
		}
		return ;
	}
	Server::cl_iterator cl_it = this->findClient(args.substr(0, start));	
	if (cl_it == this->clients.end())
		return this->sendrpl(Reply(401, 1, args.substr(0, start).c_str()), cl_ask->get_fd()); // 401 ERR_NOSUCHNICK "<nickname> :No such nick/channel"
	if (start == args.size())
	{
		if (cl_it->second == cl_ask)
			return this->sendrpl(Reply(221, 1, cl_it->second->printFlag().c_str()), cl_ask->get_fd()); 			// 221 RPL_UMODEIS "<user mode string>"
		return ;
	}
	args.erase(0, start + 1);
	if (!cl_ask->checkFlag(C_OPER))
		return this->sendrpl(Reply(481), cl_ask->get_fd()); // 481 ERR_CHANOPRIVSNEEDED "<channel> :You're not channel operator"
	char set = '+';
	while (args[0] == '-' || args[0] == '+')
	{
		set = args[0];
		args.erase(0,1);
	}
	while (!args.empty())
	{
		if (args[0] == 'o')
		{
			if ((set == '+' && !cl_it->second->checkFlag(C_OPER)) || (set == '-' && cl_it->second->checkFlag(C_OPER)))
					this->sendstr(" MODE " + cl_it->second->getNickname() + " :" + set + "o", cl_it->first);
			if (set == '+' && !cl_it->second->checkFlag(C_OPER))
				this->sendrpl(Reply(381), cl_it->first); 				// 381 RPL_YOUREOPER ":You are now an IRC operator"
			if (set == '+')
				cl_it->second->setFlag(C_OPER);
			else
				cl_it->second->clearFlag(C_OPER);
			return ;
		}
		else
			this->sendrpl(Reply(501), cl_ask->get_fd()); // 501 ERR_UMODEUNKNOWNFLAG ":Unknown MODE flag"
		args.erase(0,1);
	}
	return ;
}

/* TOPIC
	"<client> <channel> :<topic>"
resp:
	// :prefix 332 target <channel> :<topic>
	// :prefix 331 target <channel> :No topic is set
*/
void	Server::topic(std::string args, Client *cl_ask)
{
	size_t colon = args.find(':');
	std::string resp;
	Server::chan_iterator ch_it;
	if (colon != std::string::npos)
	{
		resp = args.substr(colon + 1);
		args = args.substr(0, colon - 1);
	}
	if (args[0] == ':')
		return this->sendrpl(Reply(461, 1, "TOPIC"), cl_ask->get_fd());   // 461 ERR_NEEDMOREPARAMS "<command> :Not enough parameters"
	if ((ch_it = this->channels.find(ChParser(args))) == this->channels.end())
		return this->sendrpl(Reply(403, 1, args.c_str()), cl_ask->get_fd()); // 403 ERR_NOSUCHCHANNEL "<channel name> :No such channel"
	if (ch_it->second.isOnCh(cl_ask) == false)
		return this->sendrpl(Reply(442, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 442 ERR_NOTONCHANNEL "<channel> :You're not on that channel"
	if (colon != std::string::npos)
	{
		if (ch_it->second.checkFlag(CH_T) && ch_it->second.checkUsrFlag(cl_ask, U_OPER) == false)
			return this->sendrpl(Reply(482, 1, ch_it->first.c_str()), cl_ask->get_fd());  // 482 RRR_CHANOPRIVSNEEDED "<channel> :You're not channel operator"
		ch_it->second.setTopic(resp);
		return this->sendstrchan("TOPIC " + ch_it->first + " :" + ch_it->second.getTopic(), this->channels[ch_it->first], cl_ask->get_fd());
	}
	if (ch_it->second.getTopic().empty())
		return this->sendrpl(Reply(331, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 331 RPL_NOTOPIC "<channel> :No topic is set"
	return this->sendrpl(Reply(332, 2, ch_it->first.c_str(), ch_it->second.getTopic().c_str()), cl_ask->get_fd()); // 332 RPL_TOPIC "<channel> :<topic>"
}

//	NAMES [<channel>[,<channel>,...]]
// 353: RPL_NAMREPLY [I,E,U,D]
	// :prefix 353 target [=|*|@] <channel> :<space_separated_list_of_nicks>
void	Server::names(std::string args, Client *cl_ask)
{
	std::string resp;
	size_t comma;
	Server::chan_iterator ch_it;
	if (args.size() == 0)
		return this->sendrpl(Reply(366, 1, "*"), cl_ask->get_fd()); 	// 366 RPL_ENDOFNAMES "<channel> :End of /NAMES list"
	while (args.size())
	{
		comma = args.find(',') != std::string::npos ? args.find(',') : args.size();
		if ((ch_it = this->channels.find(ChParser(args.substr(0, comma)))) != this->channels.end())
		{
			this->sendrpl(Reply(353, 2, ch_it->first.c_str(),  // 353 RPL_NAMREPLY "<channel> :[[@|+]<nick> [[@|+]<nick> [...]]]"
										ch_it->second.getUsersNick().c_str()),
										cl_ask->get_fd());
			this->sendrpl(Reply(366, 1, ch_it->first.c_str()), cl_ask->get_fd()); 	// 366 RPL_ENDOFNAMES "<channel> :End of /NAMES list"
		}
		else
			this->sendrpl(Reply(366, 1, "*"), cl_ask->get_fd()); 	// 366 RPL_ENDOFNAMES "<channel> :End of /NAMES list"
		args = comma != args.size() ? args.substr(comma + 1) : "";
	}
	return ;
}

/* LIST
:server-prefix 321 target(clientNick) "Channel :Users Name"
:server-prefix 322 target(clientNick) #channelName numeroUsers :[ch_mode] topic
:server-prefix 322 target(clientNick) #channelName numeroUsers :[ch_mode] topic
...
:server-prefix 323 target(clientNick) ":End of /LIST"
*/
void	Server::list(std::string args, Client *cl_ask)
{
	this->sendrpl(Reply(321), cl_ask->get_fd()); // 321 RPL_LISTSTART "Channel :Users  Name"
	Server::chan_iterator ch_it;
	size_t comma;
	for (ch_it = this->channels.begin(); args.size() == 0 && ch_it != this->channels.end(); ++ch_it)
	{
		if (ch_it->second.checkFlag(CH_I))
			continue ;
		this->sendrpl(Reply(322, 3, ch_it->first.c_str(),     // 322 RPL_LIST "<channel> <# visible> :<topic>"
									ch_it->second.UsrNbr().c_str(),
									ch_it->second.checkFlag(CH_K)?"":ch_it->second.getTopic().c_str()),
							cl_ask->get_fd());
	}
	while (args.size())
	{
		comma = args.find(',') != std::string::npos ? args.find(',') : args.size();
		ch_it = this->channels.find(ChParser(args.substr(0, comma)));
		if (ch_it != this->channels.end())
		{
			if (ch_it->second.checkFlag(CH_I))
				continue ;
			this->sendrpl(Reply(322, 3, ch_it->first.c_str(),     // 322 RPL_LIST "<channel> <# visible> :<topic>"
										ch_it->second.UsrNbr().c_str(),
										ch_it->second.checkFlag(CH_K)?"":ch_it->second.getTopic().c_str()),
								cl_ask->get_fd());
		}
		args = comma != args.size() ? args.substr(comma + 1) : "";
	}
	return this->sendrpl(Reply(323), cl_ask->get_fd());                 // 323 RPL_LISTEND ":End of /LIST"
}

// INVITE <nickname> <channel>
	// :source INVITE <target> <channel>
void	Server::invite(std::string args, Client *cl_ask)
{
	size_t space = args.find(" ");
	Server::cl_iterator cl_it;
	Server::chan_iterator ch_it;
	if (space == std::string::npos)
		return this->sendrpl(Reply(461, 1, "INVITE"), cl_ask->get_fd());   // 461 ERR_NEEDMOREPARAMS "<command> :Not enough parameters"
	cl_it = this->findClient(args.substr(0, space));
	if ( cl_it == this->clients.end())
		return this->sendrpl(Reply(401, 1, args.substr(0, space).c_str()), cl_ask->get_fd()); // 401 ERR_NOSUCHNICK "<nickname> :No such nick/channel"
	ch_it = this->channels.find(ChParser(args.substr(space + 1)));
	if ( ch_it == this->channels.end())
		return this->sendrpl(Reply(403, 1, args.substr(space + 1).c_str()), cl_ask->get_fd()); // 403 ERR_NOSUCHCHANNEL "<channel name> :No such channel"
	if (ch_it->second.isOnCh(cl_ask) == false)
		return this->sendrpl(Reply(442, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 442 ERR_NOTONCHANNEL "<channel> :You're not on that channel"
	if (ch_it->second.isOnCh(cl_it->second) == true)
		return this->sendrpl(Reply(443, 2, cl_it->second->getNickname().c_str(), ch_it->first.c_str()), cl_ask->get_fd()); // 443 ERR_USERONCHANNEL "<user> <channel> :is already on channel"
	if (ch_it->second.checkFlag(CH_I) && ch_it->second.checkUsrFlag(cl_ask, U_OPER) == false)
		return this->sendrpl(Reply(482, 1, ch_it->first.c_str()), cl_ask->get_fd());  // 482 RRR_CHANOPRIVSNEEDED "<channel> :You're not channel operator"
	ch_it->second.set_invlist(args);
	this->privmsg(cl_it->second->getNickname() + " :You're invited on channel "  + ch_it->first + ",you can join with key=" + ch_it->second.getKey() , cl_it->second);
	return this->sendstr("INVITE " + args, cl_it->first, cl_ask->get_fd());
}

// KICK <channel>{,<channel>} <user>{,<user>} [<comment>]
void	Server::kick(std::string args, Client *cl_ask)
{
	size_t space = args.find(' ');
	if (space == std::string::npos)
		return this->sendrpl(Reply(461, 1, args.c_str()), cl_ask->get_fd());   // 461 ERR_NEEDMOREPARAMS "<command> :Not enough parameters"
	size_t colon = args.find(':');
	size_t comma;
	std::string msg = colon != std::string::npos ? args.substr(colon) : ":for no reason";
	std::string chans = args.substr(0, space);
	std::string usrs = colon != std::string::npos ? args.substr(space + 1, colon - space - 2) : args.substr(space + 1);
	args = usrs;
	while (chans.size())
	{
		comma = chans.find(',')!= std::string::npos ? chans.find(',') : chans.size();
		usrs = args;
		while (usrs.size())
		{
			space = usrs.find(',')!= std::string::npos ? usrs.find(',') : usrs.size();
			this->kick_base(chans.substr(0, comma) + " " + usrs.substr(0, space) + " " + msg, cl_ask);
			usrs = space != usrs.size() ? usrs.substr(space + 1) : "";
		}
		chans = comma != chans.size() ? chans.substr(comma + 1) : "";
	}
	return ;
}

// // KICK <channel> <user> [<comment>]
// 	//	:source KICK <channel> <user> [<comment>]
void	Server::kick_base(std::string args, Client *cl_ask)
{
	size_t space = args.find(" ");
	Server::chan_iterator ch_it;
	Server::cl_iterator cl_it;
	if (space == std::string::npos)
		return this->sendrpl(Reply(461, 1, "KICK"), cl_ask->get_fd());   // 461 ERR_NEEDMOREPARAMS "<command> :Not enough parameters"
	ch_it = this->channels.find(ChParser(args.substr(0, space)));
	if ( ch_it == this->channels.end())
		return this->sendrpl(Reply(403, 1, args.substr(0, space).c_str()), cl_ask->get_fd()); // 403 ERR_NOSUCHCHANNEL "<channel name> :No such channel"
	args = args.substr(space + 1);
	space = args.find(" ");
	if (space == std::string::npos)
	{
		cl_it = this->findClient(args);
		args += " :for no reason";
	}
	else
		cl_it = this->findClient(args.substr(0, space));
	if ( cl_it == this->clients.end())
		return this->sendrpl(Reply(401, 1, args.substr(0, space).c_str()), cl_ask->get_fd()); // 401 ERR_NOSUCHNICK "<nickname> :No such nick/channel"
	if (ch_it->second.isOnCh(cl_ask) == false)
		return this->sendrpl(Reply(442, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 442 ERR_NOTONCHANNEL "<channel> :You're not on that channel"
	if (ch_it->second.isOnCh(cl_it->second) == false)
		return this->sendrpl(Reply(441, 2, cl_it->second->getNickname().c_str(), ch_it->first.c_str()), cl_ask->get_fd()); // 441 ERR_USERNOTINCHANNEL "<nick> <channel> :They aren't on that channel"
	if (ch_it->second.checkUsrFlag(cl_ask, U_OPER) == false)
		return this->sendrpl(Reply(482, 1, ch_it->first.c_str()), cl_ask->get_fd()); // 482 ERR_CHANOPRIVSNEEDED "<channel> :You're not channel operator"
	this->sendstrchan("KICK " + ch_it->first + " " + args, ch_it->second,cl_ask->get_fd());
	ch_it->second.partCh(cl_it->second);
	return ;
}

