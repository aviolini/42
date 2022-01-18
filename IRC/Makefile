

NAME		=	ircserv

SRCS		=	main.cpp

INC			=

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -rf


$(NAME)	:	$(OBJS) $(INC)
			@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all		:	$(NAME)

run		:	re
			clear
			@./$(NAME)

server	:	clean												#////////DEL
			@clang -Wall -Wextra -Werror ex_server.c -o server
			@./server || echo ""

client	: 	clean												#////////DEL
			@clang -Wall -Wextra -Werror ex_client.c -o client
			@./client || echo "" 

%.o		:	%.cpp
			@$(CXX) $(CXXFLAGS) -c $<

clean	:
			@rm -f server	
			@rm -f client
			@$(RM) $(OBJS)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all	
		
.PHONY : all re clean fclean