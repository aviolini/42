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

//EXIT
#include <stdlib.h>

int ret_error(std::string s, int err = errno);
void print_sockaddr_in (struct sockaddr_in *my_addr);
void print_addrinfo (struct addrinfo *hints);
void print_fd (struct stat buf);


/*

struct addrinfo {
        int              ai_flags;     // AI_PASSIVE, AI_CANONNAME, etc.
        int              ai_family;    // AF_INET, AF_INET6, AF_UNSPEC
        int              ai_socktype;  // SOCK_STREAM, SOCK_DGRAM
        int              ai_protocol;  // use 0 for "any"
        size_t           ai_addrlen;   // size of ai_addr in bytes
        struct sockaddr *ai_addr;      // struct sockaddr_in or _in6
        char            *ai_canonname; // full canonical hostname
    
        struct addrinfo *ai_next;      // linked list, next node
    };


struct sockaddr {
        unsigned short    sa_family;    // address family, AF_xxx
        char              sa_data[14];  // 14 bytes of protocol address
    }; 

struct sockaddr_in {
        short int          sin_family;  // Address family, AF_INET
        unsigned short int sin_port;    // Port number
        struct in_addr     sin_addr;    // Internet address
        unsigned char      sin_zero[8]; // Same size as struct sockaddr
    };

struct in_addr {
        uint32_t s_addr; // that's a 32-bit int (4 bytes)
    };




*/