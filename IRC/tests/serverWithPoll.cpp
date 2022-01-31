
#include "utils.hpp"

// #define MYPORT 3490
#define BACKLOG 3
#define HOST "127.0.0.1"
#define BUFFER_SIZE 256


int main(int ac, char **av)
{
	short myport;
	if (ac != 2)
	{
		myport = 6667;
		std::cout << "Default port number: " << myport << std::endl;
	}
	else
		myport = atoi(av[1]);
//SOCKET
	std::cout << "-------APERTURA SOCKET-----" << std::endl;
	int fd = socket(PF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		return ret_error("SOCKET_FD ERROR");
	else
		std::cout << "SOCKET_FD: " << fd << std::endl;
//FCNTL
	if (fcntl(fd, F_SETFL, O_NONBLOCK) < 0)
		return ret_error("FCNTL ERROR");
//SOCKADDR_IN
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	///////////////////////////////////////////
	// servaddr.sin_port = htons(0); 					// sceglie una porta a caso non in uso
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 	// usa il mio indirizzo IP
	servaddr.sin_port = htons(myport);
	// servaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	///////////////////////////////////////////
	memset(servaddr.sin_zero, '\0', sizeof servaddr.sin_zero);
	socklen_t servaddrsize = sizeof(servaddr);
	print_sockaddr_in(&servaddr);
//SETSOCKOPT
	int yes = 1;
	if (setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)))
		return ret_error("SETSOCKOPT ERROR");
	
//BIND
	if (bind(fd, (struct sockaddr *)&servaddr, servaddrsize ))
		return ret_error("BIND ERROR");
//GETADDRINFO
	struct addrinfo hints;
	memset(&hints, '\0', sizeof hints);
	hints.ai_protocol = 132;
	struct addrinfo *res;

	int ret;
	if ((ret = getaddrinfo(HOST, 0, &hints, &res)) < 0)
	{
		std::cout << gai_strerror(ret) << std::endl;
		exit(1);
	}
	struct addrinfo *temp = res;
	int x = 0;
	while (temp)
	{
		std::cout << "RES: " << x++ << std::endl;
		print_addrinfo(temp);
		temp = temp->ai_next;
	}
/*
//GETSOCKNAME
	struct sockaddr info;
	memset(&info, '\0', sizeof info);
	socklen_t s;
	if (getsockname(fd, &info, &s) < 0)
		return ret_error("GET SOCK NAME ERROR");
	else
		print_sockaddr_in(((struct sockaddr_in *)&info));
//FSTAT
	struct stat buf;
	if (fstat(fd, &buf) < 0)
		return ret_error("FSTAT ERROR");
	print_fd(buf);
*/
//LISTEN
	if (listen(fd, BACKLOG) < 0)
		return ret_error("LISTEN ERROR");

//POLL

	// int nfds, num_open_fd;
	// struct pollfd *pfds;


	std::cout << "TODO" << std::endl;

	return 0;
}