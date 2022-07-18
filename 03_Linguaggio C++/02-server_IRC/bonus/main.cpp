#include "Bot.hpp"
#include <iostream>
#include <string>
#include <csignal>

int main(int ac, char **av)
{
	time_t	t;
	srand((unsigned) time(&t));
	try
	{
		if (ac != 5)
			throw std::invalid_argument ("error:arguments\n<serv_addr> <serv_port> <serv_password> <num_clients>");
		std::string serv_addr = av[1];
		std::string serv_port = av[2];
		std::string serv_pass = av[3];
		int n_clients = atoi(av[4]);
		if (n_clients <= 0)
			throw std::invalid_argument ("error:arguments\n<serv_addr> <serv_port> <serv_password> <num_clients>");
		if (std::signal(SIGINT, SIG_IGN) == SIG_ERR || std::signal(SIGQUIT, SIG_IGN) == SIG_ERR)
    		throw std::runtime_error("error:signal");
		RandomNick rand_nick(n_clients);
		Bot *bot;
		bot = new Bot[n_clients];
		std::string chan[] = { "qwe", "asd", "ch1", "ch2"};
		int n_chan = sizeof(chan) / sizeof(std::string);
		for (int i = 0; i < n_clients; ++i)
		{
			bot[i].reg(serv_addr, serv_port,serv_pass,rand_nick.get_nick());
			int r = rand() % n_chan;
			bot[i].send_cmd("JOIN " + chan[r]);
			std::cout << bot[i].getNickname() << " joined " << chan[r] << std::endl;
			usleep(10000);
		}
		std::cout << n_clients << " clients created\n";
		std::cout << n_chan << " channels created\n";
		while (1)
		{
			std::string s;
			std::cin >> s;
			if (!s.compare("quit") || !s.compare("\0"))
				break;
			else
				std::cout << "Enter 'quit' or CTRL-D to exit" << std::endl;
		}
		delete[] bot;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}