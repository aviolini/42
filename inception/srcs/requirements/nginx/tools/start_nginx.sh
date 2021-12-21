#! /bin/bash

mv default /etc/nginx/sites-available/default
mv index.nginx-debian.html /var/www/html/index.nginx-debian.html
chown -R www-data:www-data /var/www/html/
service nginx start
/bin/bash
