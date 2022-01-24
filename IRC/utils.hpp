#pragma once

#include <iostream>
#include <string>
//SOCKET
#include <sys/socket.h> // int socket(int domain, int type, int protocol)
#include <errno.h>
//INET ADDR
// #include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//INET NTOA
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>

//GET PROTOBYNAME
#include <netdb.h>
//BIND //int bind(int sockfd, struct sockaddr *my_addr, int addrle
#include <sys/types.h> 


//ACCEPT int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
#include <sys/types.h>
#include <sys/socket.h>

//READ
# include <unistd.h>

//MEMSET
#include <string.h>

//PERROR
#include <stdio.h>

//SIGNAL
#include <signal.h>

//ADDRINFO
#include <netdb.h>

//FSTAT
#include <sys/stat.h>

//FCNTL
#include <fcntl.h>

//SELECT
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>

int ret_error(std::string s, int err = errno);
void print_sockaddr_in (struct sockaddr_in my_addr);
void print_addrinfo (struct addrinfo hints);
void print_fd (struct stat buf);


