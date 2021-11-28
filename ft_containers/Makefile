# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 09:43:32 by aviolini          #+#    #+#              #
#    Updated: 2021/11/28 23:53:11 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTDIR		= 	tests/

FTNAME		=	ftTest
	
STLNAME		=	stlTest
	
SRCS		=	vectorTests.cpp stackTests.cpp mapTests.cpp
	
FTINC		=	vector.hpp vectorIterators.hpp stack.hpp utils.hpp map.hpp mapIterators.hpp
	
OBJS		=	$(SRCS:.cpp=.o)

MAIN		=	./tests/main.cpp
	
CXX			=	clang++
	
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
	
RM			=	rm -rf

$(FTNAME)	:	$(addprefix $(TESTDIR), $(OBJS)) $(FTINC)
				$(CXX) $(CXXFLAGS) $(MAIN) -o $(FTNAME) $(OBJS)

$(STLNAME)	:	$(addprefix $(TESTDIR), $(OBJS))
				$(CXX) $(CXXFLAGS) -D STD $(MAIN) -o $(STLNAME) $(OBJS)

%.o			:	%.cpp
				$(CXX) $(CXXFLAGS) -c $<

#MAKE
all			:	stl ft

ft			:	$(FTNAME)

stl			:	$(STLNAME)

#TEST
test		:	teststl testft

testft		:	$(FTNAME)
				@printf "\033[1;33m\n_FT_\n\033[0m"
				@./ftTest

teststl		:	$(STLNAME)
				@printf "\033[1;32m\n_STL_\n\033[0m"
				@./stlTest

#LOG
log			:	all
				@./ftTest > ftLog
				@./stlTest > stlLog
				@printf "\033[1;34m\n_DIFF_\n\033[0m"
				@diff ftLog stlLog || printf "ERROR DIFF"

#TIME
time		:	all
				@printf "\033[1;32m\n_STL_TIME\033[0m"
				@time ./stlTest > /dev/null
				@printf "\033[1;33m\n_FT_TIME\033[0m"
				@time ./ftTest > /dev/null

allall		:	cl re all clean test log time
				@$(RM) $(OBJS)
				@$(RM) ftLog stlLog ftTest stlTest

leaks		:	cl fclean ft
				leaks --atExit -- ./$(FTNAME)

valgrind	:	cl fclean ft
				valgrind -s --leak-check=full ./$(FTNAME) 

#CLEAN
clean		:	
				@$(RM) $(OBJS)

cleanft		:
				@$(RM) $(OBJS)

cleanstl	:
				@$(RM) $(OBJS)

cl			:	
				clear

#FCLEAN
fclean		:	clean
				@$(RM) $(FTNAME) $(STLNAME)
				@$(RM) ftLog stlLog

fcleanft	:	cleanft
				$(RM) $(FTNAME)
				$(RM) ftLog	

fcleanstl	:	cleanstl
				$(RM) $(STLNAME)
				$(RM) stlLog

#RE
re			:	fclean all

reft		:	fcleanft ft

restl		:	fcleanstl stl

#.PHONY	
.PHONY		:	all re clean fclean
