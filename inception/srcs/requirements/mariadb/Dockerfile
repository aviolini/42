FROM debian:buster
RUN apt-get update && apt-get -y install mariadb-server less vim

COPY ["conf/50-server.cnf", "/"]
RUN mv 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf


ENTRYPOINT service mysql start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?