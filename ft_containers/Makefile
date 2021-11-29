# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 09:43:32 by aviolini          #+#    #+#              #
#    Updated: 2021/11/29 01:26:17 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTDIR		= 	tests/

FTNAME		=	ftTest
	
STLNAME		=	stlTest

FTPRINT	    =	printTest
	
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

$(FTPRINT)	:	$(addprefix $(TESTDIR), $(OBJS)) $(FTINC)
				$(CXX) $(CXXFLAGS) -D PRINT_TREE $(MAIN) -o $(FTPRINT) $(OBJS)

%.o			:	%.cpp
				$(CXX) $(CXXFLAGS) -c $<

#MAKE
all			:	stl ft
ft			:	$(FTNAME)
stl			:	$(STLNAME)

#TEST
run			:	runstl runft
runft		:	$(FTNAME)
				@printf "\033[1;33m\n_FT_\n\033[0m"
				@./ftTest
runstl		:	$(STLNAME)
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
				
#TEST, LOG, TIME
allall		:	cl re all clean run log time
				@$(RM) $(OBJS)
				# @$(RM) ftLog stlLog ftTest stlTest
				
#PRINT TREE
print		:	$(FTPRINT)
				@./printTest
				
#LEAKS CHECK MAC
leaks		:	cl fclean ft
				leaks --atExit -- ./$(FTNAME)
				
#LEAKS CHECK LINUX
valgrind	:	cl fclean ft
				valgrind -s --leak-check=full ./$(FTNAME)

#CLEAN
clean		:	
				@$(RM) $(OBJS)

#FCLEAN
fclean		:	clean
				$(RM) $(FTNAME)
				$(RM) ftLog	
				$(RM) $(STLNAME)
				$(RM) stlLog
				@$(RM) printTest

#RE
re			:	fclean all

#CLEAR
cl			:	
				clear

#.PHONY	
.PHONY		:	all re clean fclean
