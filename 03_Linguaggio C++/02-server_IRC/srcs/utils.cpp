#include "Server.hpp"

std::string ChParser(std::string ch_name)
{
	switch (ch_name[0])
	{
		case '#':   break ;
		case '&':   ch_name[0] = '#'; break;
		case '+':   ch_name[0] = '#'; break;
		case '!':   ch_name[0] = '#'; break;
		default :   ch_name = '#' + ch_name; break;
	}
	for (size_t x = 1; x < ch_name.size(); ++x)
	{
		ch_name[x] = std::tolower(ch_name[x]);
		if (ch_name[x] == ' ' || ch_name[x] == 7 || ch_name[x] == ',')
			ch_name.erase(x--, 1);
	}
	if (ch_name.size() > 50)
		ch_name = ch_name.substr(0, 50);
	return ch_name;
}

void    CmdParser(std::string &cmd)
{
	for (size_t x = 0; x < cmd.size(); ++x)
	{
		if (cmd[x] >= 'a' && cmd[x] <= 'z')
			cmd[x] = std::toupper(cmd[x]);
	}
}

bool CmdExists(const std::string &cmd, const std::string *arr, const size_t len)
{
	for (unsigned long i = 0; i < len / sizeof(std::string); ++i)
		if (arr[i].compare(cmd) == 0)
			return true;
	return false;
}

void    NickParser(std::string &nick)
{
	for (size_t x = 0; x < nick.size(); ++x)
	{
		if (nick[x] >= 'a' && nick[x] <= 'z')
			continue ;   // <letter>     ::= 'a' ... 'z' | 'A' ... 'Z'
		if (nick[x] >= 'A' && nick[x] <= 'Z')
			continue ;
		if (nick[x] >= '0' && nick[x] <= '9')
			continue ;   // <number>     ::= '0' ... '9'
		if (nick[x] == '-' || nick[x] == '[' || nick[x] == ']' || nick[x] == '\\'
			|| nick[x] == '|' || nick[x] == '^' || nick[x] == '{' || nick[x] == '}')
			continue ;  // <special>    ::= '-' | '[' | ']' | '\' | '`' | '^' | '{' | '}'
		nick.erase(x--, 1);
	}
	if (nick.size() > 9)
		nick = nick.substr(0, 9);

}

void ParamsParser(std::string &args)
{
	while (args[0] == ' ')
		args.erase(0, 1);
	size_t colon = args.find(':') != std::string::npos ? args.find(':') : args.size();
	for (size_t x = 0; x < colon; ++x)
	{
		if (args[x] == ' ')
		{
			++x;
			while (args[x] && args[x] == ' ')
				args.erase(x, 1);
		}
	}
	while (*args.rbegin() == ' ')
		args.erase(args.end() - 1);
	return ;
}

std::string itao(size_t ref)
{
	std::stringstream ss;
	ss << ref;
	return ss.str();
}