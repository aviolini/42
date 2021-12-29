#!/bin/bash

tar -xzf /tmp/wordpress-5.8.2.tar.gz
mv /wordpress /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress/

# mv wp-config.php /var/www/html/wordpress/
