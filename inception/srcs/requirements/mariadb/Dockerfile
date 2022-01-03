FROM debian:buster
RUN apt-get update && apt-get -y install mariadb-server less vim

############# COPIA DELLE IMPOSTAZIONI PERSONALIZZATE PRECEDENTEMENTE CONFIGURATE
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI '##ADDING SETTING'
RUN cp /etc/mysql/mariadb.conf.d/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf.original
COPY ["conf/50-server.cnf", "/etc/mysql/mariadb.conf.d/50-server.cnf"]

############# COPIA DEL BACKUP DELLA CONFIGURAZIONE INIZIALE DI WORDPRESS PRECEDENTEMENTE EFFETTUATA, VERRA' UTILIZZATA NELLO SCRIPT
COPY ["conf/wp_dump.sql", "/"]

COPY ["tools/start_mariadb.sh", "/"]
ENTRYPOINT ./start_mariadb.sh
