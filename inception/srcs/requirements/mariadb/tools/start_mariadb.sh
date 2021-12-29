#!/bin/bash


service mysql start

mysql -u root -e "CREATE DATABASE wordpress;"
mysql -u root -e "GRANT USAGE ON wordpress.* TO '$MYSQL_USER'@'localhost' IDENTIFIED BY '$MYSQL_USER_PASSWORD';"
mysql -u root -e "GRANT ALL ON wordpress.* TO '$MYSQL_USER'@'localhost';"
# mysql -u root -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MYSQL_ROOT_PASSWORD');"

#https://serverfault.com/questions/634277/installing-configuring-and-running-mariadb-in-foreground-on-centos-7-via-docker
mysqladmin -u root password "$MYSQL_ROOT_PASSWORD"
mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "UPDATE mysql.user SET Password=PASSWORD('$MYSQL_ROOT_PASSWORD') WHERE User='root'"
mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1')"
mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.user WHERE User=''"
mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\_%'"
mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "FLUSH PRIVILEGES"

#tu run mariadb in foreground
mysqld_safe

#