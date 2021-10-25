# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 09:43:32 by aviolini          #+#    #+#              #
#    Updated: 2021/09/17 01:17:22 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	main

SRCS	=	main.cpp

INC		=	Array.hpp
	
OBJS	=	$(SRCS:.cpp=.o)

CXX		=	clang++

CXXFLAGS=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -rf

$(NAME)	:	$(OBJS) $(INC) 
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) -I.

all		:	$(NAME)

%.o		:	%.cpp
			$(CXX) $(CXXFLAGS) -c $< -I.

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all re clean flcean
