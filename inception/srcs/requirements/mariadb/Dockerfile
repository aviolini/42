FROM debian:buster
RUN apt-get update && apt-get -y install mariadb-server less vim

#COPIA DELLE IMPOSTAZIONI PERSONALIZZATE PRECEDENTEMENTE CONFIGURATE
COPY ["conf/50-server.cnf", "/"]
RUN cp /etc/mysql/mariadb.conf.d/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf.original
RUN mv 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

#COPIA DEL BACKUP DELLA CONFIGURAZIONE INIZIALE DI WORDPRESS PRECEDENTEMENTE EFFETTUATA
COPY ["conf/wp_dump.sql", "/"]

COPY ["tools/start_mariadb.sh", "/tmp/"]
ENTRYPOINT /tmp/start_mariadb.sh
