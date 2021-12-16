# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:54:54 by aviolini          #+#    #+#              #
#    Updated: 2021/12/16 17:55:06 by aviolini         ###   ########.fr        #
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

all		:	install
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
			@printf "$(GREEN)docker images\n$(NONE)"
			@$(D) images
			@printf "$(GREEN)docker containers\n$(NONE)"
			@$(D) ps -a
			@printf "$(BLUE)docker-compose images\n$(NONE)"
			@$(DC) -f $(SRCS)/$(DCY) images
			@printf "$(BLUE)docker-compose containers\n$(NONE)"
			@$(DC) -f $(SRCS)/$(DCY) ps
# @printf "$(YELLOW)docker volumes\n$(NONE)"
# @$(DC) -f $(SRCS)/$(DCY) config | grep volumes -A1 --color='auto'

install	:
			@apt list docker | grep installed && echo "" || apt install -y docker
			@systemctl start docker
			@apt list docker-compose | grep installed && echo "" || apt install -y docker-compose
			
remove	:
			@apt remove -y docker docker-compose

clean	:
			$(DC) -f $(SRCS)/$(DCY) rm --stop --force
# $(D) system prune

fclean	:	clean
			$(DC) -f $(SRCS)/$(DCY) down -v --rmi all
#$(D) system prune -a --force
			
.PHONY	: all stop re status clean fclean
