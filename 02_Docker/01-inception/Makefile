# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:54:54 by aviolini          #+#    #+#              #
#    Updated: 2022/01/11 23:43:53 by arrigo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./srcs/.env

SRCS	=	./srcs
D		=	docker
DC		=	docker-compose
DCY		=	docker-compose.yml

TEST	=	pidof dockerd >/dev/null 2>&1 && $(D) version >/dev/null 2>&1 && $(DC) version >/dev/null 2>&1 ||\
			( printf "\n$(YELLOW)Install docker, docker-compose and start docker service!$(NONE)\n" && exit 1 )

HOST	=	127.0.0.1 $(DOMAIN_NAME)

NONE	=	\e[0m
GREY	=	\e[0;37m
GREEN	=	\e[0;32m
YELLOW	=	\e[1;33m
BLUE	=	\e[0;36m
RED		=	\e[0;35m

help	:
			@$(TEST)
			@printf "\nmake\n"
			@printf "  all\t\t -> $(GREEN)build a Linux (E)nginx Mysql Php stack \n$(NONE)"
			@printf "  bonus\t\t -> $(GREEN)build LEMP stack + adminer and vsftpd server\n$(NONE)"
			@printf "  status\t -> $(GREEN)view the status of containers\n$(NONE)"
			@printf "  start\t\t -> $(GREEN)start containers\n$(NONE)"
			@printf "  stop\t\t -> $(GREEN)stop containers\n$(NONE)"
			@printf "  att<container> -> $(GREEN)attach to container\n$(NONE)"
			@printf "  re\t\t -> $(GREEN)clean containers, volumes and rebuild containers\n$(NONE)"
			@printf "  clean\t\t -> $(GREEN)stop and clean containers, volumes\n$(NONE)"
			@printf "  fclean\t -> $(GREEN)stop and clean containers, volumes, images\n$(NONE)"
			@printf "  prune\t\t -> $(GREEN)clean all containers, volumes, images in docker\n$(NONE)"
			@printf "  help\t\t -> $(GREEN)show help\n$(NONE)"


all		:	clean
			@mkdir -p /home/$(LOGIN)/data/wordpress										#CREATE DIR FOR BIND MOUNT
			@mkdir -p /home/$(LOGIN)/data/mariadb										#CREATE DIR FOR BIND MOUNT
			@$(DC) --env-file $(SRCS)/.env -f $(SRCS)/$(DCY) up -d --build --force mariadb php-fpm nginx &&\
			cat /etc/hosts | grep "$(HOST)" && echo -n ||\
			echo "$(HOST)" >> /etc/hosts												#DOCKER-COMPOSE UP
																						@#SEARCH DOMAIN_NAME IN THE HOSTS
																						@#ADD DOMAIN_NAME TO HOSTS

bonus	:	clean
			@mkdir -p /home/$(LOGIN)/data/wordpress										#CREATE DIR FOR BIND MOUNT
			@mkdir -p /home/$(LOGIN)/data/mariadb										#CREATE DIR FOR BIND MOUNT
			@$(DC) --env-file $(SRCS)/.env -f $(SRCS)/$(DCY) up -d --build --force &&\
			cat /etc/hosts | grep "$(HOST)" && echo -n ||\
			echo "$(HOST)" >> /etc/hosts
			@$(DC) -f $(SRCS)/$(DCY) exec nginx mv /tmp/index.html /var/www/html/		#ADD index.html
			@$(DC) -f $(SRCS)/$(DCY) exec nginx mv /tmp/ftp-instr.html /var/www/html/	#ADD ftp-instr.html


stop	:
			@$(TEST)
			@$(DC) -f $(SRCS)/$(DCY) stop												#DOCKER-COMPOSE STOP

start	:
			@$(TEST)
			@$(DC) -f $(SRCS)/$(DCY) start												#DOCKER-COMPOSE START

re		:	fclean all

status	:
			@$(TEST)
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
				2>/dev/null $(D) volume inspect $$volume_name | grep -e 'Mountpoint' | awk -F: '{print $$2}';\
				printf "\t  Bind mount: ";\
				2>/dev/null $(D) volume inspect $$volume_name | grep -e 'device' | awk -F: '{print $$2}';\
			done
			@printf "\n$(GREY)$(D) network\n$(NONE)"									#NETWORK LIST
			@$(D) network ls | grep lemp || echo -n

attmariadb :
			@$(TEST)
			$(DC) -f $(SRCS)/$(DCY) exec mariadb /bin/bash								#ATTACH TO MARIADB

attnginx :
			@$(TEST)
			$(DC) -f $(SRCS)/$(DCY) exec nginx /bin/bash								#ATTACH TO NGINX

attphp-fpm :
			@$(TEST)
			$(DC) -f $(SRCS)/$(DCY) exec php-fpm /bin/bash								#ATTACH TO PHP-FPM

clean	:
			@$(TEST)
			@printf "cleaning..."
			@2>/dev/null $(DC) -f $(SRCS)/$(DCY) down -v								#STOP AND REMOVE CONTAINERS AND NETWORKS				
			@sed -i '/$(HOST)/d' /etc/hosts												#DELETE HOST
			@rm -rf /home/$(LOGIN)/data/mariadb											#RM BIND MOUNT
			@rm -rf /home/$(LOGIN)/data/wordpress										#RM BIND MOUNT
			@printf "$(GREEN) done$(NONE)\n"

fclean	:	clean
			@2>/dev/null $(DC) -f $(SRCS)/$(DCY) down --rmi all							#RM IMAGES

prune	:	fclean
			@2>/dev/null $(D) stop $$($(D) ps -qa) || echo -n							#STOP ALL CONTAINERS
			@2>/dev/null $(D) rm $$($(D) ps -qa) || echo -n								#RM ALL CONTAINERS
			@2>/dev/null $(D) rmi -f $$($(D) images -qa) || echo -n						#RM ALL IMAGES
			@2>/dev/null $(D) volume rm $$($(D) volume ls -q) || echo -n				#RM ALL VOLUMES
			@2>/dev/null $(D) network rm $$($(D) network ls -q) || echo -n				#RM ALL NETWORKS
			@$(D) system prune -a --force												#DELETE ALL

.PHONY	: all stop re status install remove clean fclean prune help
