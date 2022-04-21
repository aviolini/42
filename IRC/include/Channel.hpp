#pragma once
#include "Client.hpp"
#include <sstream>

//Channel users' flags
#define U_OPER  0b00000001 // == 1 -> 'is @operator'

//Channel's flag
#define CH_I           0b00000010 // -> 'i' invite-only channel flag;
#define CH_T           0b00000100 // -> 't' topic settable by channel operator only flag;
#define CH_K           0b00001000 // -> 'k' set a channel key (password);
#define CH_N           0b00010000 // -> 'n' no messages to channel from clients on the outside;

struct ClientCompare
{
   bool operator() (const Client* lhs, const Client* rhs) const
   {
       return lhs->get_fd() < rhs->get_fd();
   }
};

class Channel : public Flag
{
public:
	Channel(): Flag(), topic("just chatting") {}
	~Channel(){}

private:
	std::string key;
	std::string topic;
	std::string invlist;
	std::map <Client *, Flag, ClientCompare> users;

	typedef std::pair<Client *, Flag> usr_node;
	typedef std::map<Client *, Flag>::iterator usr_iterator;
	typedef std::map<Client *, Flag>::const_iterator const_usr_iterator;

public:
	friend class Server;

	bool	setUser(Client &usr, const Flag &flag);
	void	setKey(const std::string &key);
	const std::string & getKey() const;
	void	setTopic(const std::string &topic);
	const std::string & getTopic() const;
	std::string UsrNbr() const;
	std::string getUsersNick() const;
	bool 	partCh(Client *canc_cl);
	bool 	isOnCh(Client *cl_ask) const;
	bool 	isOnCh(std::string nick) const;
	void	set_invlist(const std::string & nick);
	void	clear_invlist(const std::string & nick);
	bool	check_invlist(const std::string & nick) const;
	std::string printFlag() const;
	bool 	checkUsrFlag(Client *cl_ask, const unsigned char & flag) const;
	bool 	checkUsrFlag(std::string nick, const unsigned char & flag) const;
	void 	setUsrFlag(Client *cl_ask, const unsigned char & flag);
	void 	setUsrFlag(std::string nick, const unsigned char & flag);
	void 	clearUsrFlag(Client *cl_ask, const unsigned char & flag);
	void 	clearUsrFlag(std::string nick, const unsigned char & flag);
	std::string printUsrFlag(Client * cl_ask) const;
};
