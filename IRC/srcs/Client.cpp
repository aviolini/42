#include "Client.hpp"

const std::string & Client::getNickname() const
{
	return this->nickname;
}

const std::string & Client::getHostname() const
{
	return this->hostname;
}

const std::string & Client::getUsername() const
{
	return this->username;
}

const std::string & Client::getRealname() const
{
	return this->realname;
}

const std::string & Client::getServername() const
{
	return this->servername;
}

void Client::setNickname(const std::string & name)
{
	this->nickname = name;
	return;
}

void Client::setUsername(const std::string & name)
{
	this->username = name;
	return;
}

void Client::setRealname(const std::string & name)
{
	this->realname = name;
	return;
}

const int & Client::get_fd() const 
{
	return this->fd;
}

const std::string Client::getMask() const
{
	return this->nickname + "!" + this->username + "@" + this->hostname;
}

const std::string Client::printFlag() const
{
	if(this->checkFlag(C_OPER))
		return "+o";
	return "-o";
}
