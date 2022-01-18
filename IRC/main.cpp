
#include <unistd.h>
#include "utils.hpp"

#define MYPORT 3490
#define BACKLOG 3


int main()
{

/*
//INET ADDR
{
	std::cout << "-------TEST INET_ADDR-----" << std::endl;
	struct sockaddr_in ina;
	ina.sin_addr.s_addr = inet_addr("10.12.110.57");
	if (ina.sin_addr.s_addr < 0)
		std::cout << "INET_ADDR_ERROR" << std::endl;
	else
	{
		std::cout << "INET_ADDR: " << ina.sin_addr.s_addr << std::endl;
		std::cout << "-------TEST INET_NTOA-----" << std::endl;
		char *output_inet_ntoa = inet_ntoa(ina.sin_addr);
		std::cout << "INET_NTOA: " << output_inet_ntoa << std::endl;
	}
}
//GET PROTO BY NAME
char protocol[12][10] = {"ip","icmp","ggp","tcp", "egp","pup","udp","hmp","xns-idp", "rdp","rvd" };
for (int i = 0; i < 12; ++i)
{
	struct protoent * t = getprotobyname(protocol[i]);
	if (t)
	{
		std::cout << "-------------" << std::endl;
		std::cout << "PROTOCOL NAME: \t" << t->p_name << std::endl;
		std::cout << "ALIAS LIST: \t" << t->p_aliases[0] << std::endl;
		std::cout << "PROTOCOL NUMBER:" << t->p_proto << std::endl;
	}
}
*/

//SOCKET
	std::cout << "-------APERTURA SOCKET-----" << std::endl;
	int fd = socket(PF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		return ret_error("SOCKET_FD ERROR");
	else
		std::cout << "SOCKET_FD: " << fd << std::endl;
//SOCKADDR_IN
	struct sockaddr_in my_addr;
	my_addr.sin_family = AF_INET;
	///////////////////////////////////////////
	// my_addr.sin_port = htons(0); 					// sceglie una porta a caso non in uso
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY); 	// usa il mio indirizzo IP
	my_addr.sin_port = htons(MYPORT);
	// my_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	///////////////////////////////////////////
	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);
	print_sockaddr_in(my_addr);
//SETSOCKOPT
	int yes = 1;
	if (setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)))
		return ret_error("SETSOCKOPT ERROR");
//BIND
	if (bind(fd, (struct sockaddr *)&my_addr, sizeof my_addr ))
		return ret_error("BIND ERROR");
//LISTEN
	if (listen(fd, BACKLOG) < 0)
		return ret_error("LISTEN ERROR");
//ACCEPT
	struct sockaddr_in their_addr; // informazioni sull’indirizzo di chi si connette
	int sin_size = sizeof(their_addr);
	int new_fd = accept(fd, (struct sockaddr *) &their_addr, (socklen_t *)&sin_size);
	if (new_fd < 0)
		return ret_error("ACCEPT ERROR");
	else
		std::cout << "accepted\n";
	// while(1);
	return 0;
}