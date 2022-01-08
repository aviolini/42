FROM debian:buster
RUN apt-get update && apt-get -y install mariadb-server less vim

############# ARG PERMETTE DI AVERE VARIABILI IN INGRESSO
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_USER_PASSWORD
ARG MYSQL_ROOT_PASSWORD
ARG WP_ADMIN
ARG WP_ADMIN_PASSWORD
ARG WP_USER
ARG WP_USER_PASSWORD
############# COPIA DELLE IMPOSTAZIONI PERSONALIZZATE PRECEDENTEMENTE CONFIGURATE
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI '##ADDING SETTING'
RUN cp /etc/mysql/mariadb.conf.d/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf.original
COPY ["conf/50-server.cnf", "/etc/mysql/mariadb.conf.d/50-server.cnf"]

############# COPIA DEL BACKUP DELLA CONFIGURAZIONE INIZIALE DI WORDPRESS PRECEDENTEMENTE EFFETTUATA, VERRA' UTILIZZATA NELLO SCRIPT
COPY ["conf/wp_dump.sql", "/"]

RUN service mysql start &&\
############### CREAZIONE DATABASE
2>/dev/null mysql -u root -e "CREATE DATABASE ${MYSQL_DATABASE};" &&\
############################ SETUP CONNESSIONE DA LOCALHOST
mysql -u root -e "GRANT USAGE ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_USER_PASSWORD}';" &&\
mysql -u root -e "GRANT ALL ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'localhost';" &&\
############### METTENDO '%' L'UTENTE $MYSQL_USER PUO' ACCEDERE DA QUALSIASI HOST REMOTO AL DATABASE $MYSQL_DATABASE
mysql -u root -e "GRANT USAGE ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_USER_PASSWORD}';" &&\
mysql -u root -e "GRANT ALL ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';" &&\
mysql -u root -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('${MYSQL_ROOT_PASSWORD}');"&&\
############################
############### RESTORE DEL BACKUP DELLA CONFIGURAZIONE INIZIALE DI WP FATTA IN PRECEDENZA ALL'INTERNO DEL DATABASE $MYSQL_DATABASE
mysql -u $MYSQL_USER -p$MYSQL_USER_PASSWORD $MYSQL_DATABASE < wp_dump.sql &&\
############### AGGIORNAMENTO NOME USERS E PASSWORDS
mysql -u $MYSQL_USER -p$MYSQL_USER_PASSWORD $MYSQL_DATABASE -e "update wp_users set user_login = '${WP_ADMIN}', user_pass = MD5('${WP_ADMIN_PASSWORD}'), user_nicename = '${WP_ADMIN}', user_email = '${WP_ADMIN}@test.com', display_name = '${WP_ADMIN}' where id = 1;" &&\
mysql -u $MYSQL_USER -p$MYSQL_USER_PASSWORD $MYSQL_DATABASE -e "update wp_users set user_login = '${WP_USER}', user_pass = MD5('${WP_USER_PASSWORD}'), user_nicename = '${WP_USER}', user_email = '${WP_USER}@test.com', display_name = '${WP_USER}' where id = 2;" 

#IMPOSTAZIONI TIPICHE PER UN MIGLIOR LIVELLO DI SICUREZZA
#https://serverfault.com/questions/634277/installing-configuring-and-running-mariadb-in-foreground-on-centos-7-via-docker
# mysqladmin -u root password "$MYSQL_ROOT_PASSWORD"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "UPDATE mysql.user SET Password=PASSWORD('$MYSQL_ROOT_PASSWORD') WHERE User='root'"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1')"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.user WHERE User=''"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\_%'"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "FLUSH PRIVILEGES"

############### mysql IN FOREGROUND
ENTRYPOINT mysqld_safe