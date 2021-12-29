#! /bin/bash

./conf_phpmyadmin.sh


#move example file phpinfo in volume /var/www/html/
mv info.php /var/www/html/
chown www-data:www-data /var/www/html/info.php

mkdir /run/php		#e' richiesta da php-fpm7.3
php-fpm7.3
