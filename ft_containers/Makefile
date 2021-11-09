# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 09:43:32 by aviolini          #+#    #+#              #
#    Updated: 2021/11/09 17:41:05 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTDIR		= 	tests/

FTNAME		=	ftTest
	
STLNAME		=	stlTest
	
FTSRCS		=	mainFT.cpp vectorTests.cpp stackTests.cpp
	
FTINC		=	vector.hpp vectorIterators.hpp stack.hpp utils.hpp map.hpp mapIterators.hpp
	
STLSRCS		=	mainSTL.cpp vectorTests.cpp stackTests.cpp mapTests.cpp
	
FTOBJS		=	$(FTSRCS:.cpp=.o)
	
STLOBJS		=	$(STLSRCS:.cpp=.o)
	
CXX			=	clang++
	
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
	
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
				@$(RM) $(FTOBJS) $(STLOBJS)
				@$(RM) ftLog stlLog ftTest stlTest
#CLEAN
clean		:	
				@$(RM) $(FTOBJS) $(STLOBJS)

cleanft		:
				@$(RM) $(FTOBJS)

cleanstl	:
				@$(RM) $(STLOBJS)

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
.PHONY		:	all re clean flcean
