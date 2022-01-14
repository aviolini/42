#include <iostream>
#include <string>
#include <sys/socket.h>



int main()
{
	
	std::cout << socket(AF_UNIX, SOCK_STREAM, ip) << std::endl;


	return 0;
}