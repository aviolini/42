# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:54:54 by aviolini          #+#    #+#              #
#    Updated: 2022/01/05 16:50:55 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./srcs/.env

SRCS	=	./srcs
D		=	docker
DC		=	docker-compose
DCY		=	docker-compose.yml

HOST	=	127.0.0.1 $(DOMAIN_NAME)

NONE	=	\e[0m
GREY	=	\e[0;37m
GREEN	=	\e[0;32m
YELLOW	=	\e[1;33m
BLUE	=	\e[0;36m
RED		=	\e[0;35m

help	:	
			@printf "make all\t -> $(GREEN)build containers\n$(NONE)"
			@printf "make status\t -> $(GREEN)view the status of containers\n$(NONE)"
			@printf "make start\t -> $(GREEN)start containers\n$(NONE)"
			@printf "make stop\t -> $(GREEN)stop containers\n$(NONE)"
			@printf "make re\t\t -> $(GREEN)clean containers, volumes and rebuild containers\n$(NONE)"
			@printf "make clean\t -> $(GREEN)stop and clean containers, volumes\n$(NONE)"
			@printf "make fclean\t -> $(GREEN)stop and clean containers, volumes, images\n$(NONE)"
			@printf "make prune\t -> $(GREEN)clean all containers, volumes, images in docker\n$(NONE)"
			@printf "make help\t -> $(GREEN)show help\n$(NONE)"

all		:	clean
			@mkdir -p /home/$(LOGIN)/data/wordpress										#CREATE DIR FOR BIND MOUNT
			@mkdir -p /home/$(LOGIN)/data/mariadb										#CREATE DIR FOR BIND MOUNT
			@$(DC) --env-file $(SRCS)/.env -f $(SRCS)/$(DCY) up -d --build --force &&\
			cat /etc/hosts | grep "$(HOST)" && echo -n ||\
			echo "$(HOST)" >> /etc/hosts												#DOCKER-COMPOSE UP
																						@#SEARCH DOMAIN_NAME IN THE HOSTS
																						@#ADD DOMAIN_NAME TO HOSTS

stop	:
			$(DC) -f $(SRCS)/$(DCY) stop												#DOCKER-COMPOSE STOP

start	:
			$(DC) -f $(SRCS)/$(DCY) start												#DOCKER-COMPOSE START

re		:	fclean all

status	:
			@printf "\n$(BLUE)$(DC) images\n$(NONE)"									#IMAGES LIST 
			@2>/dev/null $(DC) -f $(SRCS)/$(DCY) images
			@printf "\n$(RED)$(DC) containers\n$(NONE)"									#CONTAINERS LIST
			@2>/dev/null $(DC) -f $(SRCS)/$(DCY) ps
			@printf "\n$(YELLOW)disk usage\n$(NONE)"									#DISK USAGE
			@$(D) system df
			@printf "\n$(GREEN)$(D) volumes\n$(NONE)"									#VOLUMES LIST
			@for i in mariadb wordpress; do\
				volume_name=$$i"_data";\
				$(D) volume ls | grep $$i;\
				printf "\t  Mountpoint: ";\
				2>/dev/null $(D) volume inspect $$volume_name || echo -n | grep -e 'Mountpoint' | awk -F: '{print $$2}';\
				printf "\t  Bind mount: ";\
				2>/dev/null $(D) volume inspect $$volume_name || echo -n | grep -e 'device' | awk -F: '{print $$2}';\
			done
			@printf "\n$(GREY)$(D) network\n$(NONE)"									#NETWORK LIST
			@$(D) network ls | grep lemp || echo -n

clean	:
			@2>/dev/null $(DC) -f $(SRCS)/$(DCY) down -v								#STOP AND REMOVE CONTAINERS AND NETWORKS				
			@sed -i '/$(HOST)/d' /etc/hosts												#DELETE HOST
			@rm -rf /home/$(LOGIN)/data/mariadb											#RM BIND MOUNT
			@rm -rf /home/$(LOGIN)/data/wordpress										#RM BIND MOUNT

fclean	:	clean
			@2>/dev/null $(DC) -f $(SRCS)/$(DCY) down --rmi all							#RM IMAGES

prune	:	fclean
			@2>/dev/null $(D) stop $$($(D) ps -qa) || echo -n							#STOP ALL CONTAINERS
			@2>/dev/null $(D) rm $$($(D) ps -qa) || echo -n								#RM ALL CONTAINERS
			@2>/dev/null $(D) rmi -f $$($(D) images -qa) || echo -n						#RM ALL IMAGES
			@2>/dev/null $(D) volume rm $$($(D) volume ls -q) || echo -n				#RM ALL VOLUMES
			@2>/dev/null $(D) network rm $$($(D) network ls -q) || echo -n				#RM ALL NETWORKS
			$(D) system prune -a --force												#DELETE ALL

.PHONY	: all stop re status install remove clean fclean prune help
