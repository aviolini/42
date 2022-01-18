

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
			@$(RM) $(OBJS)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean server
		
.PHONY : all re clean fclean