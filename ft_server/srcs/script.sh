#!/bin/bash


#attiva il servizio mysql, crea l'utente admin e il database wordpress
service mysql start
mariadb -e "CREATE DATABASE wordpress CHARACTER SET UTF8 COLLATE UTF8_BIN;"
mariadb -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';"
mariadb -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'admin'@'localhost';"

#imposta la password all'utente root
mysql < /var/www/html/phpmyadmin/sql/create_tables.sql
mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';"

#attiva i servizi installati
service nginx start
service php7.3-fpm start

/bin/bash
