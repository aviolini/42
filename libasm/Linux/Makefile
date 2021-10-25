# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 18:16:17 by aviolini          #+#    #+#              #
#    Updated: 2021/04/23 23:20:25 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

TEST	=	test.sh

SRCS	=	./ft_strlen.s \
			./ft_strcpy.s \
			./ft_strcmp.s \
			./ft_write.s \
			./ft_read.s \
			./ft_strdup.s
			
OBJS	=	$(SRCS:.s=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NASM	=	nasm
NFLAGS	=	-felf64
LFLAGS	=	-L. -lasm -no-pie
RM		=	rm -f

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)

all		:	$(NAME)

%.o		:	%.s
			$(NASM) $(NFLAGS) $< -o $@

clean	:	
			$(RM) $(OBJS) $(MAIN_OBJ)

fclean	:	clean
			$(RM) $(NAME) $(TEST)

test	:	all
			$(CC) $(CFLAGS) test.c -o $(TEST) $(LFLAGS)

run		:	test
			./$(TEST)

re		:	fclean all

.PHONY	:	all clean fclean re


