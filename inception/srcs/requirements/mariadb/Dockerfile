FROM debian:10.10
RUN apt-get update && apt-get -y install mariadb-server less vim
ENTRYPOINT service mysql start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?