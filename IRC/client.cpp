#include "utils.hpp"

#define DEST_IP "127.0.0.1"
#define DEST_PORT 3490
#define BUFFER_SIZE 1024

int main(void)
{
//SOCKET
	int sockfd;
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		return ret_error("SOCKET ERROR");
//SOCKADDR_IN
	struct sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(DEST_PORT);
	dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
	memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
	print_sockaddr_in(dest_addr);
//CONNECT
	if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof dest_addr) < 0)
		return ret_error("CONNECT ERROR");
//READ WELCOME_MESSAGE FROM THE SERVER
	char buffer[BUFFER_SIZE]; 
	read(sockfd, buffer, BUFFER_SIZE);
	std::cout << buffer << std::endl;
//SEND WELCOME_MESSAGE TO THE SERVER
	char message[] = "|----------------------|\n|Sei connesso al client|\n|----------------------|";
	send(sockfd, message, strlen(message), 0);
	write(1, "SCRIVI QUALCOSA AL SERVER\n", 26);
//SEND SOMETHING TO THE SERVER
	int r;
	while ((r = read(0, buffer, 1024)) > 0)
	{
		buffer[r] = '\0';
		write(sockfd, buffer, strlen(buffer));
	}
	write(1, "CHIUSURA CONNESSIONE\n", 21);
	write(sockfd, "CHIUSURA CONNESSIONE\n", 21);
	close(sockfd);

	return 0;
}