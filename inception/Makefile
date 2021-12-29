# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:54:54 by aviolini          #+#    #+#              #
#    Updated: 2021/12/29 12:35:22 by arrigo           ###   ########.fr        #
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

all		:	clean cleanvol install
# docker volume rm srcs_wordpress_data
# docker volume rm srcs_mariadb_data
			$(DC) --env-file $(SRCS)/.env -f $(SRCS)/$(DCY) up -d --build --force
#--force-recreate
#--build
stop	:
			$(DC) -f $(SRCS)/$(DCY) stop

start	:
			$(DC) -f $(SRCS)/$(DCY) start
#$(DC) -f $(SRCS)/$(DCY) up -d 
#con up se non sono creati li crea bypassando all

re		:	fclean cleanvol all

status	:
			@printf "$(GREEN)docker images\n$(NONE)"
			@$(D) images
			@printf "$(GREEN)docker containers\n$(NONE)"
			@$(D) ps -a
			@printf "$(BLUE)docker-compose images\n$(NONE)"
			@$(DC) -f $(SRCS)/$(DCY) images
			@printf "$(BLUE)docker-compose containers\n$(NONE)"
			@$(DC) -f $(SRCS)/$(DCY) ps
			@printf "$(YELLOW)disk usage\n$(NONE)"
			@$(D) system df
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

cleanvol:	
			rm -rf /home/root 							#////////////////////////////////////
			rm -rf /var/lib/docker/volumes/*			#///////////////////////////////////

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

.PHONY	: all stop re status clean fclean
