# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 12:11:35 by aviolini          #+#    #+#              #
#    Updated: 2021/06/03 12:37:06 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	pipex.c \
			exit.c \
			tools.c \
			libft_tools.c \
			libft_tools2.c \
			libft_tools3.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all		:	$(NAME)

clean	: 
			$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)
			
re		:	fclean all

.PHONY	:	all clean fclean re