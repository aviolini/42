
CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98


RM			=	rm -rf

help		:
				@printf "make ─┐\n"
				@printf "      ├─servSimple	-> simple server-client communication\n"
				@printf "      ├─servSelect	-> server multiclient communication with 'select'\n"
				@printf "      ├─servPoll	-> server multiclient communication with 'poll'\n"
				@printf "      └─client		-> client example (nc is better)\n"


servSimple	:
				@rm -f serverSimple
				@$(CXX) $(CXXFLAGS) serverSimple.cpp utils.cpp -o serverSimple		
				./serverSimple

servSelect	:
				@rm -f serverWithSelect
				@$(CXX) $(CXXFLAGS) serverWithSelect.cpp utils.cpp -o serverWithSelect
# ./ServerWithSelect

servPoll	:
				@rm -f serverWithPoll
				@$(CXX) $(CXXFLAGS) serverWithPoll.cpp utils.cpp -o serverWithPoll
				./serverWithPoll

run			:	servSelect
				./ServerWithSelect

client		:
				@rm -rf client
				@$(CXX) $(CXXFLAGS) client.cpp utils.cpp -o client

clean	:
			@rm -f serverSimple
			@rm -f serverWithSelect	
			@rm -f client

fclean	:	clean

.PHONY : all re clean fclean