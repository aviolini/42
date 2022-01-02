# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:54:54 by aviolini          #+#    #+#              #
#    Updated: 2022/01/02 19:54:18 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./srcs/.env

SRCS	=	./srcs
D		=	docker
DC		=	docker-compose
DCY		=	docker-compose.yml

NONE	=	\e[0m
GREEN	=	\e[0;32m
YELLOW	=	\e[1;33m
BLUE	=	\e[0;36m
RED		=	\e[0;31m

EXPR	=	127.0.0.1 $(DOMAIN_NAME)

all		:	clean cleanvol install
			$(DC) --env-file $(SRCS)/.env -f $(SRCS)/$(DCY) up -d --build --force &&\
			cat /etc/hosts | grep "$(EXPR)" && echo -n ||\
			echo "$(EXPR)" >> /etc/hosts

stop	:
			$(DC) -f $(SRCS)/$(DCY) stop

start	:
			$(DC) -f $(SRCS)/$(DCY) start

re		:	fclean cleanvol all

status	:
			@printf "$(GREEN)docker images\n$(NONE)"
			@$(D) images
			@printf "\n$(GREEN)docker containers\n$(NONE)"
			@$(D) ps -a
			@printf "\n$(BLUE)docker-compose images\n$(NONE)"
			@2>/dev/null $(DC) -f $(SRCS)/$(DCY) images 
			@printf "\n$(BLUE)docker-compose containers\n$(NONE)"
			@2>/dev/null $(DC) -f $(SRCS)/$(DCY) ps
			@printf "\n$(YELLOW)disk usage\n$(NONE)"
			@$(D) system df
# @printf "\n$(YELLOW)docker volumes\n$(NONE)"
# @$(D) volume ls
# @printf "\n$(YELLOW)docker bind mounts\n$(NONE)"
# @2>/dev/null $(DC) -f $(SRCS)/$(DCY) config | grep -e ':rw' -e '_name'

install	:
			@apt list docker | grep installed && echo "" || apt install -y docker
			@systemctl start docker
			@apt list docker-compose | grep installed && echo "" || apt install -y docker-compose
			
remove	:
			@apt remove -y docker docker-compose

clean	:
			$(DC) -f $(SRCS)/$(DCY) rm --stop --force
			@sed -i '/$(EXPR)/d' /etc/hosts

fclean	:	clean
			$(DC) -f $(SRCS)/$(DCY) down -v --rmi all

cleanvol:	
			rm -rf /home/root 							#CLEAN BIND MOUNTS
			rm -rf /var/lib/docker/volumes/*			#CLEAN VOLUMES

prune	:	fclean cleanvol
			$(D) system prune -a --force

help	:	
			@printf "make all\t -> $(GREEN)to build containers\n$(NONE)"
			@printf "make status\t -> $(GREEN)to view the status of containers\n$(NONE)"
			@printf "make start\t -> $(GREEN)to start containers\n$(NONE)"
			@printf "make stop\t -> $(GREEN)to stop containers\n$(NONE)"
			@printf "make re\t\t -> $(GREEN)to clean containers and volumes and rebuild containers\n$(NONE)"
			@printf "make clean\t -> $(GREEN)to stop and clean containers\n$(NONE)"
			@printf "make fclean\t -> $(GREEN)to stop and clean containers and volumes\n$(NONE)"
			@printf "make cleanvol\t -> $(GREEN)to clean volumes\n$(NONE)"
			@printf "make prune\t -> $(GREEN)to clean all\n$(NONE)"
			@printf "make install\t -> $(GREEN)to install docker and docker-compose pkgs\n$(NONE)"
			@printf "make remove\t -> $(GREEN)to remove docker and docker-compose pkgs\n$(NONE)"
			@printf "make help\t -> $(GREEN)to view this\n$(NONE)"

.PHONY	: all stop re status install remove clean fclean cleanvol prune help
