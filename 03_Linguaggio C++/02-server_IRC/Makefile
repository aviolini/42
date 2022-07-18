NAME	=	ircserv

HOSTNAME	=	'"$(shell hostname)"'
CONF	=	irc.conf

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCL_DIR	=	include/
INCL	=	Client.hpp \
			Channel.hpp \
			Server.hpp \
			Reply.hpp \
			Flag.hpp \
			Time_ko.hpp

SRCS_DIR	=	srcs/
SRCS	=	main.cpp \
			Channel.cpp \
			Client.cpp \
			Server.cpp \
			utils.cpp \
			cmds_reg.cpp \
			cmds_ch.cpp \
			cmds_misc.cpp \
			cmds_serv.cpp \
			cmd_help.cpp

OBJS	=	$(SRCS:.cpp=.o)
DEPENDS	=	$(SRCS:.cpp=.d)


all	:	$(NAME)

$(NAME)	:	$(OBJS)
	clang++ @$(CONF) -D HOSTNAME=$(HOSTNAME) -I$(INCL_DIR) $(CXXFLAGS) $(OBJS) -o $@

-include $(DEPENDS)

%.o :	$(SRCS_DIR)%.cpp
	clang++  @$(CONF) -MMD -MP -D HOSTNAME=$(HOSTNAME) -I$(INCL_DIR) -c $(CXXFLAGS) $< -o $@

run	:	all
	clear && ./ircserv 6666 psw

clean	:
	rm -rf $(OBJS) $(DEPENDS)

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all

PHONY	:	all run	clean fclean re 