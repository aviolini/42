#!/bin/bash

tar -xzf /tmp/wordpress-5.8.2.tar.gz
mv /wordpress /var/www/html/

mv wp-config.php /var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress/

ln -s /var/www/html/wordpress/wp-login.php /var/www/html/wp-login.php 
chown -R www-data:www-data /var/www/html/wp-login.php 
