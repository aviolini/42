

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

%.o		:	%.cpp
			@$(CXX) $(CXXFLAGS) -c $<

clean	:
			@$(RM) $(OBJS)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all	
		
.PHONY : all re clean fclean