#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "ServExc.hpp"

#define MESS(x) ({std::string::assign(x); break;})

class Reply : public std::string
{
public:
	int nreply;
	std::string cmd461;

	Reply(): nreply(0){}
	Reply(const int & reply, const int n = 0, ...) : nreply(reply)
	{
		switch (reply)
		{
			case 001 : MESS( ":Welcome to the Internet Relay Network <nick>!<user>@<host>" ); 										//RPL_WELCOME
			case 002 : MESS( ":Your host is <servername>, running version <ver>" ); 													//RPL_YOURHOST
			case 003 : MESS( ":This server was created <date>" ); 																	//RPL_CREATED
			case 004 : MESS( "<servername> <version> <available user modes> <available channel modes>" ); 							//RPL_MYINFO
			case 200 : MESS( "Link <version & debug level> <destination> <next server> V<protocol version> <link uptime in seconds> <backstream sendq> <upstream sendq>" ); //RPL_TRACELINK
			case 201 : MESS( "Try. <class> <server>" );																				//RPL_TRACECONNECTING
			case 202 : MESS( "H.S. <class> <server>" );																				//RPL_TRACEHANDSHAKE
			case 203 : MESS( "???? <class> [<client IP address in dot form>]" );													//RPL_TRACEUNKNOWN
			case 204 : MESS( "Oper <class> <nick>" );																				//RPL_TRACEOPERATOR
			case 205 : MESS( "User <class> <nick>" );																				//RPL_TRACEUSER
			case 206 : MESS( "Serv <class> <int>S <int>C <server> <nick!user|*!*>@<host|server> V<protocol version>");				//RPL_TRACESERVER
			case 207 : MESS( "Service <class> <name> <type> <active type>" );														//RPL_TRACESERVICE
			case 208 : MESS( "<newtype> 0 <client name>" );																			//RPL_TRACENEWTYPE
			case 209 : MESS( "Class <class> <count>" );																				//RPL_TRACECLASS
			case 211 : MESS( "<linkname> <sendq> <sent messages> <sent Kbytes> <received messages> <received Kbytes> <time open>");	//RPL_STATSLINKINFO
			case 212 : MESS( "<command> <count> <byte count> <remote count>" );														//RPL_STATSCOMMANDS
			case 219 : MESS( "<stats letter> :End of STATS report" );																//RPL_ENDOFSTATS
			case 221 : MESS( "<user mode string>" );																				//RPL_UMODEIS
			case 234 : MESS( "<name> <server> <mask> <type> <hopcount> <info>" );													//RPL_SERVLIST
			case 235 : MESS( "<mask> <type> :End of service listing" );																//RPL_SERVLISTEND
			case 242 : MESS( ":Server Up %d days %d:%02d:%02d" );																	//RPL_STATSUPTIME
			case 243 : MESS( "O <hostmask> * <name>" );																				//RPL_STATSOLINE
			case 251 : MESS( ":There are <integer> users and <integer> services on <integer> servers" );							//RPL_LUSERCLIENT
			case 252 : MESS( "<integer> :operator(s) online" );																		//RPL_LUSEROP
			case 253 : MESS( "<integer> :unknown connection(s)" );																	//RPL_LUSERUNKNOWN
			case 254 : MESS( "<integer> :channels formed" );																		//RPL_LUSERCHANNELS
			case 255 : MESS( ":I have <integer> clients and <integer> servers" );													//RPL_LUSERME
			case 256 : MESS( "<server> :Administrative info" );																		//RPL_ADMINME
			case 257 : MESS( ":<admin info>" );																						//RPL_ADMINLOC1
			case 258 : MESS( ":<admin info>" );																						//RPL_ADMINLOC2
			case 259 : MESS( ":<admin info>" );																						//RPL_ADMINEMAIL
			case 261 : MESS( "File <logfile> <debug level>" );																		//RPL_TRACELOG
			case 262 : MESS( "<server name> <version & debug level> :End of TRACE" );												//RPL_TRACEEND
			case 263 : MESS( "<command> :Please wait a while and try again." );														//RPL_TRYAGAIN
			case 301 : MESS( "<nick> :<away message>" ); 																			//RPL_AWAY
			case 302 : MESS( ":*1<reply> *( " " <reply> )" ); 																		//RPL_USERHOST
			// case 303 : MESS( ":*1<nick> *( " " <nick> )" );
			case 303 : MESS( ":<nick>" );																							//RPL_ISON
			case 305 : MESS( ":You are no longer marked as being away" ); 															//RPL_UNAWAY
			case 306 : MESS( ":You have been marked as being away" ); 																//RPL_NOWAWAY
			case 311 : MESS( "<nick> <user> <host> * :<real name>" ); 																//RPL_WHOISUSER
			case 312 : MESS( "<nick> <server> :<server info>" ); 																	//RPL_WHOISSERVER
			case 313 : MESS( "<nick> :is an IRC operator" ); 																		//RPL_WHOISOPERATOR
			case 314 : MESS( "<nick> <user> <host> * :<real name>" ); 																//RPL_WHOWASUSER
			case 315 : MESS( "<name> :End of WHO list" );																			//RPL_ENDOFWHO
			case 317 : MESS( "<nick> <integer> :seconds idle" );																	//RPL_WHOISIDLE
			case 318 : MESS( "<nick> :End of WHOIS list" ); 																		//RPL_ENDOFWHOIS
			// case 319 : MESS( "<nick> :*( ( '@' / '+' ) <channel> " " )" );
			case 319 : MESS( "<nick> : <channel list>" ); 																			//RPL_WHOISCHANNELS
			case 321 : MESS( ":Channel users name"); 																				//RPL_LISTSTART
			case 322 : MESS( "<channel> <# visible> :<topic>" );																	//RPL_LIST
			case 323 : MESS( ":End of LIST" );																						//RPL_LISTEND
			case 324 : MESS( "<channel> <mode> <mode params>" );																	//RPL_CHANNELMODEIS
			case 325 : MESS( "<channel> <nickname>" );																				//RPL_UNIQOPIS
			case 331 : MESS( "<channel> :No topic is set" );																		//RPL_NOTOPIC
			case 332 : MESS( "<channel> :<topic>" );																				//RPL_TOPIC
			case 341 : MESS( "<channel> <nick>" );																					//RPL_INVITING
			case 342 : MESS( "<user> :Summoning user to IRC" );																		//RPL_SUMMONING
			case 346 : MESS( "<channel> <invitemask>" );																			//RPL_INVITELIST
			case 347 : MESS( "<channel> :End of channel invite list" );																//RPL_ENDOFINVITELIST
			case 348 : MESS( "<channel> <exceptionmask>" );																			//RPL_EXCEPTLIST
			case 349 : MESS( "<channel> :End of channel exception list" );															//RPL_ENDOFEXCEPTLIST
			case 351 : MESS( "<version>.<debuglevel> <server> :<comments>" );														//RPL_VERSION	
			// case 352 : MESS( "<channel> <user> <host> <server> <nick> ( 'H' / 'G' > ['*''] [ ( '@' / '+' ) ] :<hopcount> <real name>");
			case 352 : MESS( "<channel> <user> <host> <server> <nick> H<ifoper><flag> :<hopcount> <real name>");					//RPL_WHOREPLY
			// case 353 : MESS( "( '=' / '*' / '@' ) <channel> :[ '@' / '+' ] <nick> *( " " [ '@' / '+' ] <nick> )" );
			case 353 : MESS( "= <channel> :<nick>" );																				//RPL_NAMREPLY
			case 364 : MESS( "<mask> <server> :<hopcount> <server info>" );															//RPL_LINKS
			case 365 : MESS( "<mask> :End of LINKS list" );																			//RPL_ENDOFLINKS
			case 366 : MESS( "<channel> :End of NAMES list" );																		//RPL_ENDOFNAMES
			case 367 : MESS( "<channel> <banmask>" );																				//RPL_BANLIST
			case 368 : MESS( "<channel> :End of channel ban list" );																//RPL_ENDOFBANLIST
			case 369 : MESS( "<nick> :End of WHOWAS" );																				//RPL_ENDOFWHOWAS
			case 371 : MESS( ":<string>" );																							//RPL_INFO
			case 372 : MESS( ":- <text>" );																							//RPL_MOTD
			case 374 : MESS( ":End of INFO list" );																					//RPL_ENDOFINFO
			case 375 : MESS( ":- <server> Message of the day - " );																	//RPL_MOTDSTART
			case 376 : MESS( ":End of MOTD command" );																				//RPL_ENDOFMOTD
			case 381 : MESS( ":You are now an IRC operator" );																		//RPL_YOUREOPER
			case 382 : MESS( "<config file> :Rehashing" );																			//RPL_REHASHING
			case 383 : MESS( "You are service <servicename>" );																		//RPL_YOURESERVICE
			case 391 : MESS( "<server> :<string showing server's local time>" );													//RPL_TIME
			case 392 : MESS( ":UserID   Terminal  Host" );																			//RPL_USERSSTART
			case 393 : MESS( ":<username> <ttyline> <hostname>" );																	//RPL_USERS
			case 394 : MESS( ":End of users" );																						//RPL_ENDOFUSERS
			case 395 : MESS( ":Nobody logged in" );																					//RPL_NOUSERS
			case 401 : MESS( "<nickname> :No such nick/channel" );																	//ERR_NOSUCHNICK
			case 402 : MESS( "<server name> :No such server" );																		//ERR_NOSUCHSERVER
			case 403 : MESS( "<channel name> :No such channel" );																	//ERR_NOSUCHCHANNEL
			case 404 : MESS( "<channel name> :Cannot send to channel" );															//ERR_CANNOTSENDTOCHAN
			case 405 : MESS( "<channel name> :You have joined too many channels" );													//ERR_TOOMANYCHANNELS
			case 406 : MESS( "<nickname> :There was no such nickname" );															//ERR_WASNOSUCHNICK
			case 407 : MESS( "<target> :<error code> recipients. <abort message>" );												//ERR_TOOMANYTARGETS
			case 408 : MESS( "<service name> :No such service" );																	//ERR_NOSUCHSERVICE
			case 409 : MESS( ":No origin specified" );																				//ERR_NOORIGIN
			case 411 : MESS( ":No recipient given (<command>)" );																	//ERR_NORECIPIENT
			case 412 : MESS( ":No text to send" );																					//ERR_NOTEXTTOSEND
			case 413 : MESS( ":No toplevel domain specified" );																		//ERR_NOTOPLEVEL
			case 414 : MESS( "<mask> :Wildcard in toplevel domain" );																//ERR_WILDTOPLEVEL
			case 415 : MESS( "<mask> :Bad Server/host mask" );																		//ERR_BADMASK
			case 421 : MESS( "<command> :Unknown command" );																		//ERR_UNKNOWNCOMMAND
			case 422 : MESS( ":MOTD File is missing" );																				//ERR_NOMOTD
			case 423 : MESS( "<server> :No administrative info available" );														//ERR_NOADMININFO
			case 424 : MESS( ":File error doing <file op> on <file>" );																//ERR_FILEERROR
			case 431 : MESS( ":No nickname given" );																				//ERR_NONICKNAMEGIVEN
			case 432 : MESS( "<nick> :Erroneous nickname" );																		//ERR_ERRONEUSNICKNAME
			case 433 : MESS( "<nick> :Nickname is already in use" );																//ERR_NICKNAMEINUSE
			case 435 : MESS( "<newnick> <channel> :Cannot change nickname while banned on channel" );
			case 436 : MESS( "<nick> :Nickname collision KILL from <user>@<host>" );												//ERR_NICKCOLLISION
			case 437 : MESS( "<nick/channel>:Nick/channel is temporarily unavailable" );											//ERR_UNAVAILRESOURCE
			case 441 : MESS( "<nick> <channel> :They aren't on that channel" );														//ERR_USERNOTINCHANNEL
			case 442 : MESS( "<channel> :You're not on that channel" );																//ERR_NOTONCHANNEL
			case 443 : MESS( "<user> <channel> :is already on channel" );															//ERR_USERONCHANNEL
			case 444 : MESS( "<user> :User not logged in" );																		//ERR_NOLOGIN
			case 445 : MESS( ":SUMMON has been disabled" );																			//ERR_SUMMONDISABLED
			case 446 : MESS( ":USERS has been disabled" );																			//ERR_USERSDISABLED
			case 451 : MESS( ":You have not registered" );																			//ERR_NOTREGISTERED
			case 461 : MESS( "<command> :Not enough parameters" );																	//ERR_NEEDMOREPARAMS
			case 462 : MESS( ":Unauthorized command (already registered)" );														//ERR_ALREADYREGISTRED
			case 463 : MESS( ":Your host isn't among the privileged" );																//ERR_NOPERMFORHOST
			case 464 : MESS( ":Password incorrect" );																				//ERR_PASSWDMISMATCH
			case 465 : MESS( ":You are banned from this server" );																	//ERR_YOUREBANNEDCREEP
			case 467 : MESS( "<channel> :Channel key already set" );																//ERR_KEYSET
			case 471 : MESS( "<channel> :Cannot join channel (+l)" );																//ERR_CHANNELISFULL
			case 472 : MESS( "<char> :is unknown mode char to me for <channel>" );													//ERR_UNKNOWNMODE
			case 473 : MESS( "<channel> :Cannot join channel (+i)" );																//ERR_INVITEONLYCHAN
			case 474 : MESS( "<channel> :Cannot join channel (+b)" );																//ERR_BANNEDFROMCHAN
			case 475 : MESS( "<channel> :Cannot join channel (+k)" );																//ERR_BADCHANNELKEY
			case 476 : MESS( "<channel> :Bad Channel Mask" );																		//ERR_BADCHANMASK
			case 477 : MESS( "<channel> :Channel doesn't support modes" );															//ERR_NOCHANMODES
			case 478 : MESS( "<channel> <channel> <char> :Channel list is full" );													//ERR_BANLISTFULL
			case 481 : MESS( ":Permission Denied- You're not an IRC operator" );													//ERR_NOPRIVILEGES
			case 482 : MESS( "<channel> :You're not channel operator" );															//ERR_CHANOPRIVSNEEDED
			case 483 : MESS( ":You can't kill a server!" );																			//ERR_CANTKILLSERVER
			case 484 : MESS( ":Your connection is restricted!" );																	//ERR_RESTRICTED
			case 485 : MESS( ":You're not the original channel operator" );															//ERR_UNIQOPPRIVSNEEDED
			case 486 : MESS( "<remotenick> :You must identify to a registered nick to private message that person" );
			case 491 : MESS( ":No O-lines for your host" );																			//ERR_NOOPERHOST
			case 501 : MESS( ":Unknown MODE flag" );																				//ERR_UMODEUNKNOWNFLAG
			case 502 : MESS( ":Cannot change mode for other users" );																//ERR_USERSDONTMATCH
			// case 704 : MESS( "<subject> :<first line of help section>" ); 														//RPL_HELPSTART
			// case 705 : MESS( "<subject> :<line of help text>" ); 																//RPL_HELPTXT 
			// case 706 : MESS( "<subject> :<last line of help text>" ); 															//RPL_ENDOFHELP
			case 704 : MESS( "<command> :<syntax>" ); 	// 704 RPL_COMMANDSYNTAX													//RPL_HELPSTART
			case 705 : MESS( "<command> :<line of help text>" ); 		// 705 RPL_COMMANDHELP										//RPL_HELPTXT 
			case 706 : MESS( "<command> :End of /HELP" ); 	// 706 RPL_ENDHELP														//RPL_ENDOFHELP
			case 723 : MESS( "<priv> :Insufficient oper privileges." ); 															//ERR_NOPRIVS
			case 900 : MESS( "<nick>!<user>@<host> <account> :You are now logged in as <username>" ); 								//RPL_LOGGEDIN
			case 901 : MESS( "<nick>!<user>@<host> :You are now logged out" ); 														//RPL_LOGGEDOUT
			case 902 : MESS( ":You must use a nick assigned to you" ); 																//ERR_NICKLOCKED
			default: MESS("ERROR: NO REPLY MATCHED");
		}
		if (n)
		{
			va_list ap;
			va_start(ap, n);
			int pos = 0;
			for (int i = 0; i < n; ++i)
			{
				size_t start = std::string::find('<', pos);
				size_t stop = std::string::find('>', pos);
				int len = stop - start + 1;
				if(start == npos || stop == npos || len <= 0)
					throw ServExc("reply: error arguments");
				std::string tmp(va_arg(ap, char *));
				if (this->nreply == 461)
					this->cmd461 = tmp;
				std::string::replace(start, len, tmp);
				pos = start + tmp.size();
			}
			va_end(ap);
		}
		std::string::insert(0, " ");
		std::string::append("\r\n");
	}

	~Reply(){}

	Reply & operator= (const Reply & x)
	{
		std::string::operator=(x);
		this->nreply = x.nreply;
		return *this;
	}

	const std::string getnreply() const
	{
		std::stringstream ss;
		if (nreply < 10)
			ss << 0 << 0 << nreply << " ";
		else
			ss << nreply << " ";
		return ss.str();
	}
	const std::string &get461() const
	{
		return this->cmd461;
	}

};