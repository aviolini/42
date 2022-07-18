# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 18:59:05 by arrigo            #+#    #+#              #
#    Updated: 2021/09/02 22:24:35 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	main

SRCS	=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC		=	clang++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

RM		=	rm -rf

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.cpp.o	:
			$(CC) $(CFLAGS) -c $< -o $@

all		:	$(NAME)

re		:	fclean all

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

.PHONY	:	all clean fclean re
