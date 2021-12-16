FROM debian:10.10
RUN apt update && apt -y install mariadb-server
ENTRYPOINT service mysql start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?