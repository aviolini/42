# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 09:43:32 by aviolini          #+#    #+#              #
#    Updated: 2021/09/15 14:44:26 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	converter

SRCS	=	main.cpp Converter.cpp
	
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

.PHONY	:	all re clean flcean