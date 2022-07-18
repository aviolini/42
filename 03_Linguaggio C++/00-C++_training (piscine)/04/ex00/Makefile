# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <arrigo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 02:03:57 by aviolini          #+#    #+#              #
#    Updated: 2021/09/03 02:03:59 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	main

SRCS		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJS		=	$(SRCS:.cpp=.o)

CC			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -rf

$(NAME)		:	$(OBJS)
				$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o			:	%.cpp
				$(CC) $(CXXFLAGS) -c $< -o $@

all			:	$(NAME)

clean		:	
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
