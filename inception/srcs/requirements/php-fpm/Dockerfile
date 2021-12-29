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
#conf wordpress #it will be managed later by the start_php.sh script
# COPY ["conf/wp-config.php", "/"]
# RUN wget https://wordpress.org/wordpress-5.8.2.tar.gz -P /tmp
# RUN tar -xzf /tmp/wordpress-5.8.2.tar.gz
# RUN mv /wordpress /var/www/html/
# # RUN rm -f latest.tar.gz
# RUN mv wp-config.php /var/www/html/wordpress/
# # RUN rm /var/www/html/index.*

#####################################################################################
COPY ["./tools/start_php.sh", "/"]
ENTRYPOINT ./start_php.sh
