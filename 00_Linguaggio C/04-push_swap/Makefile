# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 08:00:42 by arrigo            #+#    #+#              #
#    Updated: 2021/05/26 14:30:58 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

BONUS	=	checker

SRCS	=	./init_and_exit.c \
			./insert_args.c \
			./define_steps.c \
			./define_steps2.c \
			./define_steps3.c \
			./sort_min_of_five.c \
			./sort_five.c \
			./sort_five_parts.c \
			./operations_stack_a.c \
			./operations_stack_a_2.c \
			./operations_stack_b.c \
			./operations_stack_b_2.c \
			./operations_stack_b_3.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SFLAGS	=	-fsanitize=address -g3

LFLAGS	=	-L./libft -lft

RM		=	rm -f

$(NAME)		:	makelib $(OBJS) 
				$(CC) $(CFLAGS) push_swap.c -o $(NAME) $(OBJS) $(LFLAGS)

$(BONUS)	:	makelib $(OBJS)
				$(CC) $(CFLAGS) checker.c -o $(BONUS) $(OBJS) $(LFLAGS)

all			:	$(NAME)

bonus		:	$(NAME) $(BONUS)

makelib		:
				make -C ./libft

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				make clean -C ./libft
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)
				$(RM) $(BONUS)
				make fclean -C ./libft

re			:	fclean all

.PHONY		:	all clean fclean re makelib