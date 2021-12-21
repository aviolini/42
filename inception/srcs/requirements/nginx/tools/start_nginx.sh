#! /bin/bash

cp /etc/nginx/sites-available/default /etc/nginx/sites-available/default.copy
mv default /etc/nginx/sites-available/default

cp /var/www/html/index.nginx-debian.html /var/www/html/index.nginx-debian.html.copy
mv index.nginx-debian.html /var/www/html/index.nginx-debian.html

cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf.copy
mv nginx.conf /etc/nginx/

chown -R www-data:www-data /var/www/html/

service nginx start								#grazie all'aggiunta di "daemon off;" in nginx.conf nginx funziona in modalità foreground
												#senza il bisogno di avviare /bin/bash per non far uscire il container 
# nginx -g 'daemon off;'						# altro parametro giusto senza il bisogno di aggiungere "daemon off;" in nginx.conf
# nginx											# equivale a "service nginx start"		
# /bin/bash"			