#! /bin/bash

#IMPOSTAZIONI WORDPRESS
# ./start_wordpress.sh

#FILE ESEMPIO info.php
# mv info.php /var/www/html/
# chown www-data:www-data /var/www/html/info.php

# mkdir /run/php		#e' richiesta da php-fpm7.3
php-fpm7.3

#NEI FILES php-fpm.conf e www.conf ;ADDING SETTING sono i parametri modificati
