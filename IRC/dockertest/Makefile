
help	:
			@printf "\nmake\n"
			@printf "  up\n"
			@printf "  down\n"
			@printf "  status\n"
			@printf "  attc1 attc2 atts\n"

up		:	down
			docker-compose up -d --build --force

down	:
			docker-compose down -v

status	:
			docker-compose ps

attc1	:
			docker-compose exec client1 /bin/bash

attc2	:
			docker-compose exec client2 /bin/bash

atts	:
			docker-compose exec server /bin/bash