# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 17:06:49 by aviolini          #+#    #+#              #
#    Updated: 2021/08/24 13:16:41 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	karenFilter

SRCS	=	main.cpp \
			Karen.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC		=	clang++ 

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM 		=	rm -f

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.cpp.o	:
			$(CC) -c $(CFLAGS) $< -o $@

all 	:	$(NAME)

clean 	: 
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re 		: 	fclean all

.PHONY	:	all clean fclean re