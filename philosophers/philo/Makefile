# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 13:14:15 by aviolini          #+#    #+#              #
#    Updated: 2021/07/29 17:11:12 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	philo

SRCS	=	philo.c \
			routines.c \
			utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-pthread -Wall -Wextra -Werror

RM 		=	rm -f

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all 	:	$(NAME)


clean 	: 
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re