#pragma once
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

class Bot
{
	int fd;
	std::string nickname;
	std::string username;
	std::string realname;
public:
	Bot(){}
	~Bot()
	{
			std::cout << this->getNickname() << " quitted\n";			
			this->send_cmd("QUIT :exit");
			usleep(10000);
			close(this->get_fd());
	}

	void reg(std::string serv_addr, std::string serv_port, std::string password, std::string nick)
	{
	//SOCKET
		this->fd = socket(PF_INET, SOCK_STREAM, 0);
		if (this->fd < 0)
			throw std::runtime_error("error:socket or arguments");
	//SOCKADDR_IN
		struct sockaddr_in dest_addr;
		dest_addr.sin_family = AF_INET;
		dest_addr.sin_port = htons(atoi(serv_port.c_str()));
		dest_addr.sin_addr.s_addr = inet_addr(serv_addr.c_str());
		memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
	//CONNECT
		if (connect(this->fd, (struct sockaddr *)&dest_addr, sizeof dest_addr) < 0)
			throw std::runtime_error("error:connect or arguments");

		this->nickname = nick;
		this->username = nickname + "UserName";
		this->realname = nickname + "RealName";
		this->send_cmd("NICK "+ nickname);
		this->send_cmd("USER "+ this->username + " :" + this->realname);
		this->send_cmd("PASS "+ password);
		std::cout << "NICK:"<< this->nickname << " FD:"<< this->fd << std::endl;
	}

	const int & get_fd() const
	{
		return this->fd;
	}

	const std::string & getNickname() const
	{
		return this->nickname;
	}

	const std::string & getUsername() const
	{
		return this->username;
	}

	const std::string & getRealname() const
	{
		return this->realname;
	}

	void send_cmd(std::string cmd)
	{
		cmd += "\r\n";
		if (send(this->fd, cmd.c_str(), cmd.size(), 0) < 0)
			throw std::runtime_error("error:send");
	}
};

class RandomNick
{
	std::string nick_list;
public:
	RandomNick(int num_nick)
	{
		std::string c[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
		time_t	t;
		srand((unsigned) time(&t));

		for (int i = 0; i < num_nick;)
		{
			std::string tmp;
			tmp = c[rand() % 26] + c[rand() % 26] + c[rand() % 26] + c[rand() % 26] + " ";
			if (this->nick_list.find(tmp) == std::string::npos)
			{
				this->nick_list.append(tmp);
				i++;
			}
		}
	}
	~RandomNick(){}
	std::string get_nick()
	{
		if (this->nick_list.empty())
			return "EMPTY NICK LIST";
		size_t pos = this->nick_list.find(" ");
		std::string tmp = this->nick_list.substr(0, pos);
		this->nick_list.erase(0, pos + 1);
		return tmp;
	}

	const std::string & print_nick() const
	{
		return this->nick_list;
	}
};
