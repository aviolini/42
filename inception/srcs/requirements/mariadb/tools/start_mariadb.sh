#!/bin/bash

service mysql start

mysql -u root -e "CREATE DATABASE $MYSQL_DATABASE;"
# mysql -u root -e "GRANT USAGE ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'localhost' IDENTIFIED BY '$MYSQL_USER_PASSWORD';"
# mysql -u root -e "GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'localhost';"
mysql -u root -e "GRANT USAGE ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';"
mysql -u root -e "GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';"
mysql -u root -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MYSQL_ROOT_PASSWORD');"


mysql -u $MYSQL_USER -p$MYSQL_USER_PASSWORD $MYSQL_DATABASE < wp_dump.sql
mysql -u $MYSQL_USER -p$MYSQL_USER_PASSWORD $MYSQL_DATABASE -e "update wp_users set user_login = '$WP_ADMIN', user_pass = MD5('$WP_ADMIN_PASSWORD'), user_nicename = '$WP_ADMIN', user_email = '$WP_ADMIN@test.com', display_name = '$WP_ADMIN' where id = 1;"
mysql -u $MYSQL_USER -p$MYSQL_USER_PASSWORD $MYSQL_DATABASE -e "update wp_users set user_login = '$WP_USER', user_pass = MD5('$WP_USER_PASSWORD'), user_nicename = '$WP_USER', user_email = '$WP_USER@test.com', display_name = '$WP_USER' where id = 2;"

ln -s /var/lib/mysql/* /mariadb

#https://serverfault.com/questions/634277/installing-configuring-and-running-mariadb-in-foreground-on-centos-7-via-docker
# mysqladmin -u root password "$MYSQL_ROOT_PASSWORD"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "UPDATE mysql.user SET Password=PASSWORD('$MYSQL_ROOT_PASSWORD') WHERE User='root'"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1')"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.user WHERE User=''"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\_%'"
# mysql -u root -p"$MYSQL_ROOT_PASSWORD" -e "FLUSH PRIVILEGES"

mysqld_safe
# /bin/bash

#