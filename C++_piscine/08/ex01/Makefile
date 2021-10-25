# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 09:43:32 by aviolini          #+#    #+#              #
#    Updated: 2021/09/22 00:14:15 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	main

SRCS	=	main.cpp span.cpp

INC		=	span.hpp
	
OBJS	=	$(SRCS:.cpp=.o)

CXX		=	clang++

CXXFLAGS=	 -Wall -Wextra -Werror -std=c++98

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
