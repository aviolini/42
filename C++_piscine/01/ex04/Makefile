# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 17:06:49 by aviolini          #+#    #+#              #
#    Updated: 2021/08/23 11:23:45 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	replace

SRCS	=	main.cpp \
			sed.cpp

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

test	:	all
			./$(NAME) test1 ciao hello
			./$(NAME) test2 ciao hello
			./$(NAME) test3 i e

test_cl	:	
			$(RM) test1.replace test2.replace test3.replace


re 		: 	fclean all

.PHONY	:	all clean fclean re