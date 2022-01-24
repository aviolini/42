
#include <utils.hpp>

#define MYPORT 3490
#define BACKLOG 3
#define BUFFER_SIZE 1024
#define HOST "127.0.0.1"

int main()
{

/*

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
//FCNTL
	// if (fcntl(fd, F_SETFL, O_NONBLOCK) < 0)
	// 	return ret_error("FCNTL ERROR");
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
//GETADDRINFO
// struct addrinfo hints;
// if (getaddrinfo(HOST, 0, &hints, 0) < 0)
// 	return ret_error("ADDR INFO");
// print_addrinfo(hints);
//GETSOCKNAME
	// struct sockaddr info;
	// socklen_t s;
	// if (getsockname(fd, &info, &s) < 0)
	// 	return ret_error("GET SOCK NAME ERROR");
	// else
	// 	print_sockaddr_in(*((struct sockaddr_in *)&info));
//FSTAT
	struct stat buf;
	if (fstat(fd, &buf) < 0)
		return ret_error("FSTAT ERROR");
	print_fd(buf);
//LISTEN
	if (listen(fd, BACKLOG) < 0)
		return ret_error("LISTEN ERROR");
	// std::cout << "SELECT" << std::endl;
//ACCEPT
	struct sockaddr_in their_addr; // informazioni sull’indirizzo di chi si connette
	int sin_size = sizeof(their_addr);
	int new_fd = accept(fd, (struct sockaddr *) &their_addr, (socklen_t *)&sin_size);
	if (new_fd < 0)
		return ret_error("ACCEPT ERROR");
// //SELECT
// 	struct timeval tv;
// 	tv.tv_sec = 2;
// 	tv.tv_usec = 500000;
// 	fd_set readfds;
// 	FD_ZERO(&readfds);
// 	FD_SET(fd, &readfds);
// 	int nfd = 2;
// 	if ((nfd = select(nfd + 1, &readfds, NULL,NULL,NULL)) < 0)
// 		return ret_error("SELECT ERROR");
//SEND WELCOME_MESSAGE TO THE CLIENT
	char message[] = "|----------------------|\n|Sei connesso al server|\n|----------------------|";
	send(new_fd, message, strlen(message), 0);
//READ WELCOME_MESSAGE FROM THE CLIENT
	char buffer[BUFFER_SIZE]; 
	read(new_fd, buffer, BUFFER_SIZE);
	std::cout << buffer << std::endl;
//READ SOMETHING FROM THE CLIENT
	int r;
	while ((r = read(new_fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		write(1, buffer, strlen(buffer));
	}
	close(new_fd);
	close(fd);	
	return 0;
}