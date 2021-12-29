FROM debian:buster
RUN apt-get update && apt-get -y install mariadb-server less vim

COPY ["conf/50-server.cnf", "/"]
RUN mv 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ["tools/start_mariadb.sh", "/"]
# ENTRYPOINT service mysql start
ENTRYPOINT ./start_mariadb.sh
