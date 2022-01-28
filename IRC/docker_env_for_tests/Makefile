
D		=	docker
DC		=	$(D)-compose

help	:	test
			@printf "\nmake\n"
			@printf "  up\n"
			@printf "  down\n"
			@printf "  status\n"
			@printf "  clean\n"
			@printf "  fclean\n"
			@printf "  atts attc1 attc2..\n"

up		:	down
			$(DC) up -d --build --force
			@cat ~/.bashrc | grep 'alias atts' 1>/dev/null && echo -n ||\
			( echo "alias atts='docker-compose exec server /bin/bash'" >> ~/.bashrc &&\
			for i in 1 2 3 4; do\
				echo "alias attc$$i='docker-compose exec client$$i /bin/bash'" >> ~/.bashrc;\
			done &&\
			echo run 'source ~/.bashrc to reload bash' )

down	:	test
			$(DC) down -v

status	:	test
			$(DC) ps

clean	:	test
			$(DC) down -v --rmi all
			@sed -i '/alias atts/d' ~/.bashrc &&\
			for i in 1 2 3 4; do\
				sed -i '/alias attc$i/d' ~/.bashrc;\
			done

fclean	:	clean
			$(D) system prune -a

atts	:
			$(DC) exec server /bin/bash

attc1	:
			$(DC) exec client1 /bin/bash 

attc2	:
			$(DC) exec client2 /bin/bash

attc3	:
			$(DC) exec client3 /bin/bash

attc4	:
			$(DC) exec client4 /bin/bash

test	:
			pidof dockerd >/dev/null 2>&1 &&\
			$(D) version >/dev/null 2>&1 &&\
			$(DC) version >/dev/null 2>&1 ||\
			( printf "Install docker, \
			docker-compose and start docker service!\n" &&\
			exit 1 )