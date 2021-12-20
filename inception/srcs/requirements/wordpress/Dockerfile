FROM debian:10.10
RUN apt update && apt -y install php-fpm wget
				#php-mysql php-mbstring
# RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.7/phpMyAdmin-4.9.7-all-languages.tar.gz
# RUN tar -zxf phpMyAdmin-4.9.7-all-languages.tar.gz
# RUN mv phpMyAdmin-4.9.7-all-languages /var/www/html/phpmyadmin

# RUN tar -zxf /tmp/phpMyAdmin-4.9.7-all-languages.tar.gz -C /var/www/html/phpmyadmin
# RUN mv /tmp/phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin

ENTRYPOINT service php7.3-fpm start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?