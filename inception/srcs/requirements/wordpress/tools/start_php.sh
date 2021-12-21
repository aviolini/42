#! /bin/bash

#conf phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.7/phpMyAdmin-4.9.7-all-languages.tar.gz -P /tmp







#conf wordpress
wget https://wordpress.org/wordpress-5.8.2.tar.gz -P /tmp




service php7.3-fpm start

/bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?
