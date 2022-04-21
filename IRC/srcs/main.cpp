#include "Server.hpp"

int main( int ac, char **av)
{
	try
	{
		if (ac != 3)
			throw ServExc ("Error arguments");
		Server serv(av[1], av[2]);
		serv.runSelect();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}