FROM debian:buster
RUN apt-get update && apt-get -y install php-fpm wget less vim procps php-mysql php-mbstring

############# CONFIGURAZIONE DI php-fpm pool directives
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI ';ADDING SETTING'
COPY ["conf/www.conf", "/"]
RUN cp /etc/php/7.3/fpm/pool.d/www.conf /etc/php/7.3/fpm/pool.d/www.conf.original
RUN mv www.conf /etc/php/7.3/fpm/pool.d/www.conf

############# CONFIGURAZIONE DI php-fpm
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI ';ADDING SETTING'
COPY ["conf/php-fpm.conf", "/"]
RUN cp /etc/php/7.3/fpm/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf.original
RUN mv php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf

############# COPIA DEI FILE DI WORDPRESS
RUN wget https://wordpress.org/wordpress-5.8.2.tar.gz -P /tmp && tar -xzf /tmp/wordpress-5.8.2.tar.gz
RUN mkdir -p var/www/html
RUN mv /wordpress /var/www/html/wordpress

############# COPIA FILE DI CONFIGURAZIONE WORDPRESS
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI '##ADDING SETTING'
COPY ["conf/wordpress_conf/wp-config.php", "/var/www/html/wordpress/wp-config.php"]
RUN chown -R www-data:www-data /var/www/html/wordpress/

############# COPIA DEL FILE DI ESEMPIO info.php
COPY ["conf/info.php", "/var/www/html/info.php"]
RUN chown www-data:www-data /var/www/html/info.php

############# e' richiesta da php-fpm7.3
RUN mkdir /run/php

ENTRYPOINT php-fpm7.3
