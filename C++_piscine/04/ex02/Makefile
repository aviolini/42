# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 16:26:35 by aviolini          #+#    #+#              #
#    Updated: 2021/09/03 16:50:21 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	main

SRCS		=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS		=	$(SRCS:.cpp=.o)

RM			=	rm -f

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o			:	%.cpp
				$(CXX) $(CXXFLAGS) -c $< -o $@

all			:	$(NAME)

re			:	fclean all

clean		:	
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
.PHONY		:	all re clean fclean
