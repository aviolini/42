# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 02:03:57 by aviolini          #+#    #+#              #
#    Updated: 2021/09/03 11:11:18 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	main

SRCS		=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -rf

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o			:	%.cpp
				$(CXX) $(CXXFLAGS) -c $< -o $@

all			:	$(NAME)

clean		:	
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
