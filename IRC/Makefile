

NAME		=	ircserv

SRCS		=	main.cpp utils.cpp

INC			=	utils.hpp

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -rf


$(NAME)	:	$(OBJS) $(INC)
			@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

server	:	$(NAME)

server1	:	#SIMPLE ONLY-LISTEN-SERVER
			@$(CXX) $(CXXFLAGS) -I . ./tests/server1.cpp utils.cpp -o server1
			./server1

rmclient:
			@rm -f client

client	:	rmclient
			@rm -rf client
			@$(CXX) $(CXXFLAGS) client.cpp utils.cpp -o client
			@./client			

run		:	re
			clear
			@./$(NAME)

%.o		:	%.cpp
			@$(CXX) $(CXXFLAGS) -c $<

clean	:
			@rm -f server	
			@rm -f client
			@rm -f server?	
			@$(RM) $(OBJS)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean server
		
.PHONY : all re clean fclean