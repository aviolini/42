
all :
		clang++ -Wall -Wextra -Werror -std=c++98 main.cpp -o clientsBOT
run : all
		./clientsBOT 10.11.7.3 6666 psw 250
#<serv_addr> <serv_port> <serv_password> <num_clients>

clean :
	rm -f clientsBOT

fclean : clean

re : fclean all

PHONY : all run clean fclean re