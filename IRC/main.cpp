
#include "utils.hpp"

#define MYPORT 3490
#define BACKLOG 3
#define HOST "127.0.0.1"
#define BUFFER_SIZE 256


int main()
{

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
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	///////////////////////////////////////////
	// servaddr.sin_port = htons(0); 					// sceglie una porta a caso non in uso
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 	// usa il mio indirizzo IP
	servaddr.sin_port = htons(MYPORT);
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
//LISTEN
	if (listen(fd, BACKLOG) < 0)
		return ret_error("LISTEN ERROR");
	// std::cout << "SELECT" << std::endl;
//SELECT
	struct sockaddr_in cliaddr; // informazioni sull’indirizzo di chi si connette
	socklen_t cliaddrsize = sizeof(cliaddr);
	fd_set master;
	fd_set read_fds;
	int fdmax;
	int newfd;
	int i, j;
	FD_ZERO(&master);
	FD_ZERO(&read_fds);
	FD_SET(fd, &master);
	fdmax = fd;
	while (1)
	{
		read_fds = master;
		if (select(fdmax + 1, &read_fds, 0,0,0) < 0)
			return ret_error("SELECT ERROR");
		for (i = 0; i <= fdmax; ++i)
		{
			if (FD_ISSET(i, &read_fds)) // C'E' UN FILE DESRCIPTOR PRONTO PER LA LETTURA
			{
				if (i == fd)
				{
					cliaddrsize = sizeof cliaddr;
					if ((newfd = accept(fd, (struct sockaddr *)&cliaddr, &cliaddrsize)) < 0)
						return ret_error("ACCEPT ERROR");
					else
					{
						std::cout << "HERE" << std::endl;
						FD_SET(newfd, &master);
						if (newfd > fdmax)
							fdmax = newfd;
						//NUOVA CONNESSIONE
					}
				}
				else
				{
					char buffer[BUFFER_SIZE];
					int nbytes;
					if ((nbytes = recv(i, buffer, BUFFER_SIZE, 0)) <= 0)
					{
						if (nbytes < 0)
							return ret_error("RECV ERROR");
						if (nbytes == 0)
							std::cout << "connessione chiusa" << std::endl;
						close(i);
						FD_CLR(i, &master);
						return 0;
					}
					else
					{
						std::cout << "CLIENT: " << buffer;
						memset(buffer,'\0',BUFFER_SIZE);
						(void)j;
						// for (j = 0; j <= fdmax; ++j)
						// {
						// 	if (FD_ISSET(j, &master))
						// 		if (j != fd && j != i)
						// 			if (send(j,buffer,nbytes,0) < 0)
						// 				return ret_error("SEND ERROR");
						// }
					}
				}
			}
		}

	}


//ACCEPT
	// int new_fd = accept(fd, (struct sockaddr *) &their_addr, (socklen_t *)&sin_size);
	// if (new_fd < 0)
	// 	return ret_error("ACCEPT ERROR");
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
// 	char message[] = "|----------------------|\n|Sei connesso al server|\n|----------------------|";
// 	send(new_fd, message, strlen(message), 0);
// //READ WELCOME_MESSAGE FROM THE CLIENT
// 	char buffer[BUFFER_SIZE]; 
// 	read(new_fd, buffer, BUFFER_SIZE);
// 	std::cout << buffer << std::endl;
// //READ SOMETHING FROM THE CLIENT
// 	int r;
// 	while ((r = read(new_fd, buffer, BUFFER_SIZE)) > 0)
// 	{
// 		buffer[r] = '\0';
// 		write(1, buffer, strlen(buffer));
// 	}
// 	close(new_fd);
// 	close(fd);	
	return 0;
}