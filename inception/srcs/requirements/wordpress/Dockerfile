FROM debian:10.10
RUN apt update && apt -y install php-fpm 
				#php-mysql php-mbstring
ENTRYPOINT service php7.3-fpm start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?