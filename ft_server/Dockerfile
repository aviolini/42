FROM debian:buster
RUN apt-get update 
RUN apt-get -y upgrade
RUN apt-get -y install nginx mariadb-server mariadb-client php-fpm php-mysql nano vim openssl wget php-mbstring 
#config nginx
COPY ["srcs/default", "/"]
RUN mv default /etc/nginx/sites-available/default
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"
#config phpMyAdmin
COPY ["srcs/config.inc.php", "/"]
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
RUN tar -zxf phpMyAdmin-5.0.4-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin
RUN rm -f phpMyAdmin-5.0.4-all-languages.tar.gz
RUN mkdir /etc/phpmyadmin/upload -p
RUN mkdir /etc/phpmyadmin/save
RUN mkdir /etc/phpmyadmin/tmp
RUN mkdir /var/www/html/phpmyadmin/tmp
RUN chown www-data.www-data /var/www/html/phpmyadmin -R
RUN chown www-data.www-data /etc/phpmyadmin -R
RUN chmod 660  /etc/phpmyadmin -R
RUN chmod 777 /var/www/html/phpmyadmin/tmp -R
RUN mv config.inc.php /var/www/html/phpmyadmin/config.inc.php
#config wordpress
COPY ["srcs/wp-config.php", "/"]
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzf latest.tar.gz
RUN mv /wordpress/ /var/www/html/
RUN rm -f latest.tar.gz
RUN mv wp-config.php /var/www/html/wordpress/
RUN rm /var/www/html/index.*


COPY ["srcs/script.sh", "/"]
COPY ["srcs/autoindex", "/bin/"]
ENTRYPOINT ["./script.sh"]
EXPOSE 80 443
