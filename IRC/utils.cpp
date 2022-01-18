
#include "utils.hpp"

int ret_error(std::string s, int err)
{
	perror(s.c_str());
	std::cout << "error: " << err << "\n";
	return err;
}

void print_sockaddr_in (struct sockaddr_in my_addr)
{
	std::cout << "------PRINT SOCKADDR_IN--------" << std::endl; 
	std::cout << "SOCKET FAMILY:\t" << my_addr.sin_family << std::endl;
	std::cout << "SOCKET ADDRESS:\t" << my_addr.sin_addr.s_addr << std::endl;
	std::cout << "SOCKET PORT:\t" << ntohs( my_addr.sin_port) << std::endl;
	std::cout << "SOCKET_ADDR LEN:\t" << my_addr.sin_len << std::endl;
	std::cout << "-------------------------------" << std::endl; 
}