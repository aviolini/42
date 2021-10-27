# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 09:43:32 by aviolini          #+#    #+#              #
#    Updated: 2021/10/27 08:44:12 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTDIR		= 	tests/

FTNAME		=	ftTest
	
STLNAME		=	stlTest
	
FTSRCS		=	mainFT.cpp vectorTests.cpp stackTests.cpp
	
FTINC		=	vector.hpp vectorIterators.hpp stack.hpp utils.hpp
	
STLSRCS		=	mainSTL.cpp vectorTests.cpp stackTests.cpp
	
FTOBJS		=	$(FTSRCS:.cpp=.o)
	
STLOBJS		=	$(STLSRCS:.cpp=.o)
	
CXX			=	clang++
	
CXXFLAGS	=	 -Wall -Wextra -Werror -std=c++98
	
RM			=	rm -rf

$(FTNAME)	:	$(addprefix $(TESTDIR), $(FTOBJS)) $(FTINC)
				$(CXX) $(CXXFLAGS) -o $(FTNAME) $(FTOBJS)

$(STLNAME)	:	$(addprefix $(TESTDIR), $(STLOBJS))
				$(CXX) $(CXXFLAGS) -o $(STLNAME) $(STLOBJS)

%.o			:	%.cpp
				$(CXX) $(CXXFLAGS) -c $<

#MAKE
all			:	stl ft

ft			:	$(FTNAME)

stl			:	$(STLNAME)

#TEST
test		:	teststl testft

testft		:	$(FTNAME)
				@echo "\033[1;33m\n_FT_\033[0m"
				./ftTest

teststl		:	$(STLNAME)
				@echo "\033[1;32m\n_STL_\033[0m"
				./stlTest

#LOG
log			:	all
				./ftTest > ftLog
				./stlTest > stlLog
				@echo "\033[1;34m\n_DIFF_\033[0m"
				diff ftLog stllog

#TIME
time		:	all
				@echo "\033[1;32m\n_STL_TIME\033[0m"
				time ./stlTest > /dev/null
				@echo "\033[1;33m\n_FT_TIME\033[0m"
				time ./ftTest > /dev/null

allall		:	cl re all clean test log time
				$(RM) $(FTOBJS) $(STLOBJS)
				$(RM) ftLog stlLog
#CLEAN
clean		:	
				$(RM) $(FTOBJS) $(STLOBJS)

cleanft		:
				$(RM) $(FTOBJS)

cleanstl	:
				$(RM) $(STLOBJS)

cl			:	
				clear

#FCLEAN
fclean		:	clean
				$(RM) $(FTNAME) $(STLNAME)
				$(RM) ftLog stlLog

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
.PHONY		:	all re clean flcean
