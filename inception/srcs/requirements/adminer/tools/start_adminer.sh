#!/bin/bash
#############
wget "https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql.php"
# mv ciao /var/www/html/
mv adminer-4.8.1-mysql.php /var/www/html/adminer.php
chown -R www-data:www-data /var/www/html/adminer.php

/bin/bash