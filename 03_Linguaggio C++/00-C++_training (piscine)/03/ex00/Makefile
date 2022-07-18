# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 11:53:31 by aviolini          #+#    #+#              #
#    Updated: 2021/08/31 14:01:22 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	main

SRCS		=	main.cpp ClapTrap.cpp

OBJS		=	$(SRCS:.cpp=.o)

CC			=	clang++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -rf

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				
all			:	$(NAME)

.cpp.o		:	
				$(CC) -c $(CFLAGS) $< -o $@

re			:	fclean all

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

.PHONY		:	all clean fclean re