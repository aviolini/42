

#include <iostream>
#include <string>
//SOCKET
#include <sys/socket.h> // int socket(int domain, int type, int protocol)
#include <errno.h>
//INET ADDR
// #include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//GET PROTOBYNAME
#include <netdb.h>

int main()
{

//SOCKET
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		// std::cout << "SOCKET_FD_ERROR: " << strerror(errno) << std::endl;
		perror("SOCKET_FD_ERROR: ");
	else
		std::cout << "SOCKET_FD: " << fd << std::endl;

//INET ADDR
{
	struct sockaddr_in ina;
	ina.sin_addr.s_addr = inet_addr("10.12.110.57");
	if (ina.sin_addr.s_addr < 0)
		std::cout << "INET_ADDR_ERROR" << std::endl;
	else
	{
		std::cout << "INET_ADDR: " << ina.sin_addr.s_addr << std::endl;
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





	return 0;
}