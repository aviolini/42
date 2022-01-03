#!/bin/bash

# #COPIA DEI FILE WORDPRESS
# tar -xzf /tmp/wordpress-5.8.2.tar.gz
# mv /wordpress /var/www/html/

# #COPIA FILE DI CONFIGURAZIONE WORDPRESS
# mv wp-config.php /var/www/html/wordpress/
# chown -R www-data:www-data /var/www/html/wordpress/

# #COLLEGAMENTO SIMBOLICO PER AVERE LA PAGINA DI LOGIN NELLA PAGINA INIZIALE
# ln -s /var/www/html/wordpress/wp-login.php /var/www/html/wp-login.php 
# chown -R www-data:www-data /var/www/html/wp-login.php 

#NEL FILE wp-config.php //ADDING SETTING sono i parametri modificati