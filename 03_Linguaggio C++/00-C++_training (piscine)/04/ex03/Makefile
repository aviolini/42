# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 11:38:34 by aviolini          #+#    #+#              #
#    Updated: 2021/09/08 09:18:41 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	main

SRCS	=	main.cpp AMateria.cpp MateriaSource.cpp Ice.cpp Character.cpp Cure.cpp 

OBJS	=	$(SRCS:.cpp=.o)

CXX		=	clang++

CXXFLAGS=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -rf

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all		:	$(NAME)

%.o		:	%.cpp
			$(CXX) $(CXXFLAGS) -c $<

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)
			
re		:	fclean all

.PHONY	:	all re clean fclean