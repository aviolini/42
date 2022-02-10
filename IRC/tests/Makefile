
CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98


RM			=	rm -rf

help		:
				@printf "make ─┐\n"
				@printf "      ├─servSimple   -> simple server-client communication\n"
				@printf "      ├─serverSelect -> server multiclient communication with 'select'\n"
				@printf "      ├─serverPoll   -> server multiclient communication with 'poll'\n"
				@printf "      ├─client       -> client example (nc is better)\n"
				@printf "      └─clean        -> remove binaries\n"

serverSimple	:
				@rm -f serverSimple
				@$(CXX) $(CXXFLAGS) serverSimple.cpp utils.cpp -o serverSimple		
				./serverSimple

serverSelect	:
				@rm -f serverSelect
				@$(CXX) $(CXXFLAGS) serverSelect.cpp utils.cpp -o serverSelect

serverPoll	:
				@rm -f serverPoll
				@$(CXX) $(CXXFLAGS) serverPoll.cpp utils.cpp -o serverPoll
				./serverPoll

run			:	serverSelect
				./serverSelect

client		:
				@rm -rf client
				@$(CXX) $(CXXFLAGS) client.cpp utils.cpp -o client

clean	:
			@rm -f serverSimple
			@rm -f serverSelect	
			@rm -f serverPoll	
			@rm -f client

fclean	:	clean

.PHONY : all re clean fclean