#include "Channel.hpp"

bool Channel::setUser(Client &usr, const Flag &flag)
{
	Channel::usr_node usrNode(&usr, flag);
	std::pair< Channel::usr_iterator, bool> ins_ret = this->users.insert(usrNode);
	return ins_ret.second;
}

void Channel::setKey(const std::string &key)
{
	this->key = key;
	if (key.size())
		this->setFlag(CH_K);
}

const std::string & Channel::getKey() const
{
	return this->key;
}

void Channel::setTopic(const std::string &topic)
{
	this->topic = topic;
}

const std::string & Channel::getTopic() const
{
	return this->topic;
}

std::string Channel::UsrNbr() const
{
	std::stringstream ss;
	ss << this->users.size();
	return ss.str();
}

std::string Channel::getUsersNick() const
{
	std::string resp;
	for (Channel::const_usr_iterator usr_it = this->users.begin(); usr_it != this->users.end(); ++usr_it)
	{
		resp += this->printUsrFlag(usr_it->first);
		resp += usr_it->first->getNickname() + " ";
	}
	return resp;
}

bool Channel::partCh(Client *canc_cl)
{
	return this->users.erase(canc_cl);
}

bool Channel::isOnCh(Client *cl_ask) const
{
	return (this->users.find(cl_ask) != this->users.end());
}

bool Channel::isOnCh(std::string nick) const
{
	for (Channel::const_usr_iterator it = this->users.begin(); it != this->users.end(); ++it)
	{
		if (it->first->getNickname().compare(nick) == 0)
				return true;
	}
	return false;
}

void Channel::set_invlist(const std::string & nick)
{
	this->invlist += nick + " ";
}

void Channel::clear_invlist(const std::string & nick)
{
	if (this->invlist.find(nick + " ") != std::string::npos)
		this->invlist.erase(this->invlist.find(nick + " "), sizeof(nick) + 1);
}

bool Channel::check_invlist(const std::string & nick) const
{
	if (this->invlist.find(nick + " ") != std::string::npos)
		return true;
	return false;
}

std::string Channel::printFlag() const
{
	std::string resp;
	unsigned char mask = 0b00000001;
	for (int i = 0; i < 8; ++i)
	{
		if (this->getFlag() & mask)	
		{
			switch (mask)
			{
				case CH_I : resp += "i"; break;
				case CH_T : resp += "t"; break;
				case CH_K : resp += "k"; break;
				case CH_N : resp += "n"; break;
				default : break;
			}
		}
		mask = mask << 1;
	}
	return "+" + resp;
}

bool Channel::checkUsrFlag(Client *cl_ask, const unsigned char & flag) const
{
	return this->users.find(cl_ask)->second.checkFlag(flag);
}

bool Channel::checkUsrFlag(std::string nick, const unsigned char & flag) const
{
	for (std::map<Client *, Flag>::const_iterator it = this->users.begin(); it != this->users.end(); ++it)
	{
		if (it->first->getNickname().compare(nick) == 0)
			return this->users.find(it->first)->second.checkFlag(flag);
	}
	return false;
}

void Channel::setUsrFlag(Client *cl_ask, const unsigned char & flag)
{
	return this->users[cl_ask].setFlag(flag);
}

void Channel::setUsrFlag(std::string nick, const unsigned char & flag)
{
	for (std::map<Client *, Flag>::iterator it = this->users.begin(); it != this->users.end(); ++it)
	{
		if (it->first->getNickname().compare(nick) == 0)
		{
			this->users[it->first].setFlag(flag);
			return;
		}
	}
	return ;
}

void Channel::clearUsrFlag(Client *cl_ask, const unsigned char & flag)
{
	return this->users[cl_ask].clearFlag(flag);
}

void Channel::clearUsrFlag(std::string nick, const unsigned char & flag)
{
	for (Channel::usr_iterator it = this->users.begin(); it != this->users.end(); ++it)
	{
		if (it->first->getNickname().compare(nick) == 0)
		{
			this->users[it->first].clearFlag(flag);
			return;
		}
	}
	return ;
}

std::string Channel::printUsrFlag(Client * cl_ask) const
{
	if(this->users.find(cl_ask)->second.checkFlag(U_OPER))
		return "@";
	return "";
}
