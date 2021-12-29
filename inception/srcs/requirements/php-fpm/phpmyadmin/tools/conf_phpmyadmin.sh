#!/bin/bash

#move phpMyAdmin dir in volume /var/www/html/
mv -f phpMyAdmin-4.9.7-all-languages /var/www/html/phpmyadmin

mv config.inc.php /var/www/html/phpmyadmin/config.inc.php
chmod 660 /var/www/html/phpmyadmin/config.inc.php
chown -R www-data:www-data /var/www/html/phpmyadmin


# mkdir /etc/phpmyadmin/upload -p
# mkdir /etc/phpmyadmin/save
# mkdir /etc/phpmyadmin/tmp
# mkdir /var/www/html/phpmyadmin/tmp
# chown www-data:www-data /var/www/html/phpmyadmin -R
# chown www-data:www-data /etc/phpmyadmin -R
# chmod 660  /etc/phpmyadmin -R
# chmod 777 /var/www/html/phpmyadmin/tmp -R


# mv wordpress /var/www/html/
# mv wp-config.php /var/www/html/wordpress/wp-config.php
