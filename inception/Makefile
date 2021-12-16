# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:54:54 by aviolini          #+#    #+#              #
#    Updated: 2021/12/16 11:45:01 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs
D		=	docker
DC		=	docker-compose
DCY		=	docker-compose.yml

NONE	=	\e[0m
GREEN	=	\e[0;32m
YELLOW	=	\e[1;33m
BLUE	=	\e[0;36m
RED		=	\e[0;31m

all		:	
			$(DC) -f $(SRCS)/$(DCY) up -d --build
#--force-recreate
#--build
stop	:
			$(DC) -f $(SRCS)/$(DCY) stop
			
start	:
			$(DC) -f $(SRCS)/$(DCY) start  
#$(DC) -f $(SRCS)/$(DCY) up -d 
#con up se non sono creati li crea bypassando all

re		:	fclean all

status	:
			@printf "$(BLUE)docker-compose images\n$(NONE)"
			@$(DC) -f $(SRCS)/$(DCY) images
			@printf "$(BLUE)docker-compose containers\n$(NONE)"
			@$(DC) -f $(SRCS)/$(DCY) ps
			@printf "$(GREEN)docker images\n$(NONE)"
			@$(D) images
			@printf "$(GREEN)docker containers\n$(NONE)"
			@$(D) ps -a		

clean	:
			$(DC) -f $(SRCS)/$(DCY) rm --stop --force -v
# $(D) system prune

fclean	:	clean
			$(D) system prune -a --force

.PHONY	: all stop re status clean fclean
