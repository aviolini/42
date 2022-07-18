#pragma once
#include "Client.hpp"
#include "Channel.hpp"
#include "ServExc.hpp"
#include "Time_ko.hpp"
#include "Reply.hpp"
#include <map>
#include <csignal>
#include <netdb.h>
#include <fcntl.h>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "Help.hpp"

std::string ChParser(std::string ch_name);
void CmdParser(std::string &cmd);
bool CmdExists(const std::string &cmd, const std::string *arr, const size_t len);
void NickParser(std::string &cmd);
void ParamsParser(std::string &args);
std::string itao(size_t ref);

class Server
{
	struct addrinfo *res;
	struct sockaddr addr_in;
	int fd;
	int fdmax;
	fd_set master;
	std::string password;
	std::string msgotd;
	std::map<int, Client*> clients;
	std::map<std::string, Channel> channels;
	time_ko timemap;
	CHelp helper;

	struct s_stat
	{
		size_t bsent;
		size_t msent;
		size_t brecv;
		size_t mrecv;
	} t_stat;

	typedef std::pair<int, Client*> cl_node;
	typedef std::map<int, Client*>::iterator cl_iterator;
	typedef std::map<int, Client*>::const_iterator const_cl_iterator;
	typedef std::pair<std::string, Channel> chan_node;
	typedef std::map<std::string, Channel>::iterator chan_iterator;

public:

	Server(){};
	Server(const std::string & port, const std::string & password):password(password), msgotd(MMOTD)
	{
		this->t_stat.bsent = 0;
		this->t_stat.msent = 0;
		this->t_stat.brecv = 0;
		this->t_stat.mrecv = 0;
    	struct hostent *hp = gethostbyname(HOSTNAME);
		if (!hp)
			throw ServExc ("gethostbyname: Error hostname");
		std::string host = inet_ntoa( *( struct in_addr*)( hp -> h_addr_list[0]));
		struct addrinfo hints;
		memset(&hints, '\0', sizeof hints);
		hints.ai_protocol = 6;
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		int ret;
		if ((ret = getaddrinfo(host.c_str(), port.c_str(), &hints, &this->res)) < 0)
			throw ServExc ("getaddrinfo: Error arguments");
		if (!this->res)
			throw ServExc (gai_strerror(ret));
		if (atoi(port.c_str()) < 1024)
				throw ServExc ("getaddrinfo: Error port");
		this->addr_in = *res->ai_addr;
		this->fd = socket(PF_INET, SOCK_STREAM, 6);
		if (this->fd < 0)
			throw ServExc("socket: error");
		int yes = 1;
		if (setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)))
			throw ServExc("setsockopt: error");
		if (fcntl(this->fd, F_SETFL, O_NONBLOCK) < 0)
			throw ServExc("fcntl: error");
		if (bind(this->fd, &this->addr_in, sizeof (this->addr_in)))
			throw ServExc("bind: error");
		if (listen(this->fd, BACKLOG) < 0)
			throw ServExc("listen: error");
		print_Server_addrinfo();
		this->fdmax = this->fd;
		FD_ZERO(&this->master);
		FD_SET(this->fd, &this->master);
		FD_SET(STDIN_FILENO, &this->master);
	};
	~Server(){
		while (this->clients.size())
			this->quit(":Server Destr", this->clients.begin()->second);
		FD_ZERO(&this->master);
		this->channels.clear();
		this->clients.clear();
		this->timemap.clear();
		close(this->fd);
		freeaddrinfo(this->res);
		std::cout << "Server connection closed" << std::endl;
	};

	int		runSelect();
	const std::string Prefix() const;
private:
	void	setChannel	(const std::pair< Server::chan_iterator, bool> &ins_ret, const std::string &key, Client &cl_ask);
	int		serv_resp(std::string buffer,const int &cl_fd); 
	void	check_cmd(const std::string & cmd, std::string args, const int &cl_fd);
	Server::cl_iterator findClient	(const std::string &nick);
	struct timeval* timeout ( void );
	void	sendrpl(const Reply & reply, const int & dest_cl_fd);
	void	sendstr(const std::string & str, const int & dest_cl_fd, const int & src_prefix_fd = 0);
	void	sendrplchan(const Reply & reply, const int & nick_cl_fd, const Channel & dest_channel, const int &except = 0);
	void	sendstrchan(const std::string & str, const Channel & dest_channel, const int & src_prefix_fd = 0, const int &except = 0);
	void	print_Server_addrinfo() const;
	void	print_Client_sockaddr(const int & fd) const;

	//cmds_reg
	void	cap (std::string args, Client *cl_ask);
	void	pass(std::string args, Client * cl_ask);
	void	nick(std::string args, Client *cl_ask);
	void	user(std::string args, Client *cl_ask);
	void	oper(std::string args, Client *cl_ask);
	void	quit(std::string args, Client *cl_ask);
	void	squit(std::string args, Client *cl_ask = 0);

	//cmds_ch
	void	join(std::string args, Client *cl_ask);
	void	part(std::string args, Client *cl_ask);
	void	mode(std::string args, Client *cl_ask);
	void	topic(std::string args, Client *cl_ask);
	void	names(std::string args, Client *cl_ask);
	void	list(std::string args, Client *cl_ask);
	void	invite(std::string args, Client *cl_ask);
	void	kick(std::string args, Client *cl_ask);
	void	kick_base(std::string args, Client *cl_ask);

	//cmd_misc
	void	ping(std::string args, Client *cl_ask);
	void	pong(std::string args, Client *cl_ask);
	void	who(std::string args, Client *cl_ask);
	void	privmsg(std::string args, Client *cl_ask);
	void	notice(std::string args, Client *cl_ask);
	void	kill(std::string args, Client *cl_ask);
	void	whois(std::string args, Client *cl_ask);

	//cmd_serv
	void	motd(std::string args, Client *cl_ask);
	void	lusers(std::string args, Client *cl_ask);
	void	version(std::string args, Client *cl_ask);
	void	stats(std::string args, Client *cl_ask);
	void	links(std::string args, Client *cl_ask);
	void	srvtime(std::string args, Client *cl_ask);
	void	srvconnect(std::string args, Client *cl_ask);
	void	srvtrace(std::string args, Client *cl_ask);
	void	srvadmin(std::string args, Client *cl_ask);
	void	srvinfo(std::string args, Client *cl_ask);
	void	welcome(std::string args, Client *cl_ask);

	//cmd_help	
	void	help(std::string args, Client *cl_ask);
	void	setbot(std::string args, Client *cl_ask);
	void	bothelp(std::string args, Client *cl_ask);

};
