#pragma once

#include <map>
#include <string>
#include <utility>

class CHelp : public std::map<std::string, std::pair<std::string, std::string> >
{
public:
	typedef std::map<std::string, std::pair<std::string, std::string> > helpMap;
	CHelp()
	: helpMap()
	{
		(*this)["PASS"] = std::make_pair(" :PASS <password>", " :<password> is required to connect @IRCserver");
		(*this)["NICK"] = std::make_pair(" :NICK <nickname>", " :set your <nickname> (max len = 9)");
		(*this)["USER"] = std::make_pair(" :USER <username> :<realname>", " :set your registration <username> and your <realname>");
		(*this)["OPER"] = std::make_pair(" :OPER <nick> <root_password>", " :obtain Operator privileges passing your <nick> and right <root_password>");
		(*this)["MODE"] = std::make_pair(" :MODE <nickname> {[+|-]o} [<user>]  ||  MODE <channel> {[+|-]|o|i|t|n|k}", " :change <nickname> client modes: \"+o\" to give Operator privileges @<user> || \"-o\" to deop yourself  && :change <channel> modes: 'i' invite only / 't' safe topic / 'n' not reachable from outside / 'k <key>' set/unset a key / 'o <user> set/unset chanop'");
		(*this)["QUIT"] = std::make_pair(" :QUIT :<Quit Message>", " :close connection passing a <Quit Message>");
		(*this)["SQUIT"] = std::make_pair(" :SQUIT", " :shutdown the server");
		(*this)["JOIN"] = std::make_pair(" :JOIN <channel1> [,<channel2>,<channel3>,..] [<key1>[,<key2>,<key3>,..]]", " :join|create <channels> with relatives <keys>");
		(*this)["WHO"] = std::make_pair(" :WHO <channel>|<nick>", " :get <channel>|<nick> general info");
		(*this)["PRIVMSG"] = std::make_pair(" :PRIVMSG <channel>|<nick> :<message>", " :send <message> to target");
		(*this)["LIST"] = std::make_pair(" :LIST [<channel>]", " :get members number and topic of <channel>|all existing channel");
		(*this)["PART"] = std::make_pair(" :PART <channel1> [,<channel2>,<channel3>,..] :<Part Reason>", " :leave <channels> with an optional goodbye <Part Reason>");
		(*this)["TOPIC"] = std::make_pair(" :TOPIC <channel> [:<newtopic>]", " :get <channel> topic | set/unset <channel> <newtopic>");
		(*this)["NAMES"] = std::make_pair(" :NAMES <channel>[,<channel>,...]", " :get nicks of <channels> member");
		(*this)["INVITE"] = std::make_pair(" :INVITE <nickname> <channel>", " :invite <nickname> to join <channel>");
		(*this)["KICK"] = std::make_pair(" :KICK <channel>{,<channel>} <user>{,<user>} [<comment>]", " :remove <users> from <channels>");
		(*this)["NOTICE"] = std::make_pair(" :NOTICE <channel>|<nick> :<text>", " :send <text> to target");		
		(*this)["KILL"] = std::make_pair(" :KILL <nick> [:<comment>]", " :disconnect <nick> from server");		
		(*this)["WHOIS"] = std::make_pair(" :WHOIS <nick>>", " :get <nick> details");		
		(*this)["MOTD"] = std::make_pair(" :MOTD [:<new_motd>]", " :get the message of the day | set a <new_motd>");
		(*this)["LUSERS"] = std::make_pair(" :LUSERS", " :get server size info");
		(*this)["VERSION"] = std::make_pair(" :VERSION", " :get server version info");
		(*this)["STATS"] = std::make_pair(" :STATS l", " :get server sent/recv details: <link> <sendq> <sent messages> <sent Kbytes> <received messages> <received Kbytes> <time open>");
		(*this)["LINKS"] = std::make_pair(" :LINKS", " :get server links");
		(*this)["TIME"] = std::make_pair(" :TIME", " :get server current time");
		(*this)["CONNECT"] = std::make_pair(" :CONNECT <target server> <port> [ <remote server> ]", " :forbidden");
		(*this)["TRACE"] = std::make_pair(" :TRACE", " :get server users route");
		(*this)["ADMIN"] = std::make_pair(" :ADMIN", " :get administrative info");
		(*this)["INFO"] = std::make_pair(" :INFO", " :get server general info");
		(*this)["PING"] = std::make_pair(" :PING :<txt>", " :request a PONG reply");
		(*this)["PONG"] = std::make_pair(" :PONG :<txt>", " :reply to a PING");
		(*this)["BOT"] = std::make_pair(" :BOT <+|->", " :set|unset the bot helper");
		(*this)["HELP"] = std::make_pair(" :HELP <cmd>", " :This is a list of available commands: :PASS, NICK, USER, OPER, MODE, QUIT, SQUIT, JOIN, WHO, PRIVMSG, LIST, PART, TOPIC, NAMES, INVITE, KICK, NOTICE, KILL, WHOIS, MOTD, LUSERS, VERSION, STATS, LINKS, TIME, CONNECT, TRACE, ADMIN, INFO, PING, PONG, BOT");		
	};
	~CHelp()
	{ };
};