FROM debian:10.10
RUN apt update && apt -y install php-fpm wget
				#php-mysql php-mbstring

#conf phpmyadmin
COPY ["conf/config.inc.php", "/"]
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.7/phpMyAdmin-4.9.7-all-languages.tar.gz -P /tmp
RUN mkdir -p /var/www/html
RUN tar -zxf /tmp/phpMyAdmin-4.9.7-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.7-all-languages /var/www/html/phpmyadmin
RUN rm -f /tmp/phpMyAdmin-4.9.7-all-languages.tar.gz
# RUN mkdir /etc/phpmyadmin/upload -p
# RUN mkdir /etc/phpmyadmin/save
# RUN mkdir /etc/phpmyadmin/tmp
# RUN mkdir /var/www/html/phpmyadmin/tmp
# RUN chown www-data.www-data /var/www/html/phpmyadmin -R
# RUN chown www-data.www-data /etc/phpmyadmin -R
# RUN chmod 660  /etc/phpmyadmin -R
# RUN chmod 777 /var/www/html/phpmyadmin/tmp -R
RUN mv config.inc.php /var/www/html/phpmyadmin/config.inc.php

#conf wordpress
COPY ["conf/wp-config.php", "/"]
RUN wget https://wordpress.org/wordpress-5.8.2.tar.gz -P /tmp
RUN tar -xzf /tmp/wordpress-5.8.2.tar.gz
RUN mv /wordpress /var/www/html/
# RUN rm -f latest.tar.gz
RUN mv wp-config.php /var/www/html/wordpress/
# RUN rm /var/www/html/index.*


ENTRYPOINT service php7.3-fpm start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?