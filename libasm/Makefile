# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 18:16:17 by aviolini          #+#    #+#              #
#    Updated: 2021/04/26 14:14:51 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS		=	./ft_strlen.s \
				./ft_strcpy.s \
				./ft_strcmp.s \
				./ft_write.s \
				./ft_read.s \
				./ft_strdup.s 			
				
SRCS_B		=	./ft_list_push_front.s \
				./ft_list_size.s \
				./ft_list_sort.s \
				./ft_list_remove_if.s \
				./ft_atoi_base.s

OBJS		=	$(SRCS:.s=.o)
OBJS_B		=	$(SRCS_B:.s=.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NASM		=	nasm
NFLAGS		=	-fmacho64
RM			=	rm -f

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

bonus		:	$(OBJS) $(OBJS_B)
				ar rcs $(NAME) $(OBJS) $(OBJS_B)

%.o			:	%.s
				$(NASM) $(NFLAGS) $< -o $@

clean		:	
				$(RM) $(OBJS) $(OBJS_B)

fclean		:	clean
				$(RM) $(NAME) test.sh test_bonus.sh

test_bonus	:	bonus
				$(CC) $(CFLAGS) -I. test_bonus.c -o test_bonus.sh -L. -lasm $(NAME_B)

test		:	all
				$(CC) $(CFLAGS) -I. test.c -o test.sh -L. -lasm $(NAME)

run			:	test
				./test.sh

run_bonus	:	test_bonus
				./test_bonus.sh

re			:	fclean all

.PHONY		:	all clean fclean re


