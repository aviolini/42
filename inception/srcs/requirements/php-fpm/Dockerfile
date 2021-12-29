FROM debian:buster
RUN apt-get update && apt-get -y install php-fpm wget less vim procps php-mysql php-mbstring

#####################################################################################
#conf php-fpm pool directives
COPY ["conf/www.conf", "/"]
RUN cp /etc/php/7.3/fpm/pool.d/www.conf /etc/php/7.3/fpm/pool.d/www.conf.original
RUN mv www.conf /etc/php/7.3/fpm/pool.d/www.conf
#conf php-fpm
COPY ["conf/php-fpm.conf", "/"]
RUN cp /etc/php/7.3/fpm/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf.original
RUN mv php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf
#copy example file phpinfo() #it will be managed later by the start_php.sh script
COPY ["conf/info.php", "/"]

#####################################################################################
#only for phpmyadmin
# COPY ["phpmyadmin/conf/config.inc.php", "/"]
# COPY ["./phpmyadmin/tools/start_phpmyadmin.sh", "/"]

#####################################################################################
#only for wordpress
COPY ["wordpress/conf/wp-config.php", "/"]
RUN wget https://wordpress.org/wordpress-5.8.2.tar.gz -P /tmp
COPY ["./wordpress/tools/start_wordpress.sh", "/"]

#####################################################################################
COPY ["./tools/start_php.sh", "/"]
ENTRYPOINT ./start_php.sh
