#include "utils.hpp"

#define DEST_IP "127.0.0.1"
#define DEST_PORT 3490

int main(void)
{
//SOCKET
	int sockfd;
	sockfd = socket(PF_INET, SOCK_STREAM, 0); /* esegui il controllo degli errori!*/
	if (sockfd < 0)
		return ret_error("SOCKET ERROR");
//SOCKADDR_IN
	struct sockaddr_in dest_addr;  // conterrà l’indirizzo di destinazione
	dest_addr.sin_family = AF_INET; // host byte order
	dest_addr.sin_port = htons(DEST_PORT); // short, network byte order
	dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
	memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
	print_sockaddr_in(dest_addr);
//CONNECT
	if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof dest_addr) < 0)
		return ret_error("CONNECT ERROR");

///////////////////////////////////////////////////////
//READ WELCOME_MESSAGE FROM THE SERVER
	char buffer[1024]; 
	read(sockfd, buffer, 1024);
	std::cout << buffer << std::endl;
//SEND WELCOME_MESSAGE TO THE SERVER
	char message[] = "|----------------------|\n|Sei connesso al client|\n|----------------------|";
	send(sockfd, message, strlen(message), 0);
///////////////////////////////////////////////////////

	return 0;
}