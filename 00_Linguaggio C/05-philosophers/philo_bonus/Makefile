# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 13:14:15 by aviolini          #+#    #+#              #
#    Updated: 2021/08/02 14:53:37 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

SRCS 		=	philo_bonus.c \
				utils_bonus.c \
				routines_bonus.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-pthread -Wall -Wextra -Werror

VALGRIND	=	valgrind -s -q --leak-check=full \
 				--trace-children=yes --show-leak-kinds=all \
 				./philo_bonus 4 600 200 200 10
RM			=	rm -f

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all			:	$(NAME)

clean		: 
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

val			:	$(NAME)
				$(VALGRIND)

re 			:	fclean all

.PHONY		:	all clean fclean re