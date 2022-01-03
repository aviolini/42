#! /bin/bash

# #COPIA FILE CONFIGURAZIONE SERVER
# cp /etc/nginx/sites-available/default /etc/nginx/sites-available/default.copy
# mv default /etc/nginx/sites-available/default

# #COPIA DELLA PAGINA INIZIALE MODIFICATA
# mv index.nginx-debian.html /var/www/html/index.nginx-debian.html

# #COPIA DEL FILE DELLE IMPOSTAZIONI DI NGINX
# cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf.copy
# mv nginx.conf /etc/nginx/

# #ACCESSO GARANTITO ALL'UTENTE www-data
# chown -R www-data:www-data /var/www/html/

service nginx start

#NEI FILES default e nginx.conf #ADDING SETTING sono i parametri modificati
