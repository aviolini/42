#pragma once
#include "Flag.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <map>
#include <unistd.h>

//Server clients' flags
#define C_PASS 0b00000001 // -> 'set password field'
#define C_NICK 0b00000010 // -> 'set nick field'
#define C_USER 0b00000100 // -> 'set user field'
#define C_OPER 0b00010000 // -> 'set operator'
#define C_PINGED 0b01000000 // -> 'ping timeout'
#define C_BOT 0b10000000 // -> 'set bot'

class Client : public Flag
{
	const int fd;
	struct sockaddr_in addr_in;
	std::string nickname;
	std::string hostname;
	std::string username;
	std::string realname;
	std::string servername;
	std::string cl_msg;

public:
	Client(const int & newfd, struct sockaddr_in addr, const std::string & servname)
	: Flag(), fd(newfd), addr_in(addr), hostname(inet_ntoa(this->addr_in.sin_addr)), servername(servname) {}
	~Client(){
		close(this->fd);
	}
	friend class Server;
	const std::string & getNickname() const;
	const std::string & getHostname() const;
	const std::string & getUsername() const;
	const std::string & getRealname() const;
	const std::string & getServername() const;
	void	setNickname(const std::string & name);
	void	setUsername(const std::string & name);
	void	setRealname(const std::string & name);
	const int &get_fd() const;
	const std::string getMask() const;
	const std::string  printFlag() const;
};
