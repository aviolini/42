FROM debian:buster
RUN apt-get update && apt-get -y install php-fpm wget less vim procps php-mysql php-mbstring

############# CONFIGURAZIONE DI php-fpm pool directives
COPY ["conf/www.conf", "/"]
RUN cp /etc/php/7.3/fpm/pool.d/www.conf /etc/php/7.3/fpm/pool.d/www.conf.original
RUN mv www.conf /etc/php/7.3/fpm/pool.d/www.conf

############# CONFIGURAZIONE DI php-fpm
COPY ["conf/php-fpm.conf", "/"]
RUN cp /etc/php/7.3/fpm/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf.original
RUN mv php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf

############# COPIA DEL FILE DI ESEMPIO info.php
COPY ["conf/info.php", "/"]

############# COPIA DEI FILE DI WORDPRESS
COPY ["wordpress/conf/wp-config.php", "/"]
RUN wget https://wordpress.org/wordpress-5.8.2.tar.gz -P /tmp
COPY ["./wordpress/tools/start_wordpress.sh", "/"]





#COPIA DEI FILE WORDPRESS
RUN tar -xzf /tmp/wordpress-5.8.2.tar.gz
RUN mkdir -p var/www/html
RUN mv /wordpress /var/www/html/

#COPIA FILE DI CONFIGURAZIONE WORDPRESS
RUN mv wp-config.php /var/www/html/wordpress/
RUN chown -R www-data:www-data /var/www/html/wordpress/

#COLLEGAMENTO SIMBOLICO PER AVERE LA PAGINA DI LOGIN NELLA PAGINA INIZIALE
RUN ln -s /var/www/html/wordpress/wp-login.php /var/www/html/wp-login.php 
RUN chown -R www-data:www-data /var/www/html/wp-login.php 


RUN mv info.php /var/www/html/
RUN chown www-data:www-data /var/www/html/info.php

RUN mkdir /run/php		
#e' richiesta da php-fpm7.3


COPY ["./tools/start_php.sh", "/"]
ENTRYPOINT ./start_php.sh
