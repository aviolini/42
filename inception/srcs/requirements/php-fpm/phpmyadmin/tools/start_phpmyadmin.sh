#!/bin/bash


#####################################################################################
#conf phpmyadmin #it will be managed later by the start_php.sh script

wget https://files.phpmyadmin.net/phpMyAdmin/4.9.7/phpMyAdmin-4.9.7-all-languages.tar.gz -P /tmp
tar -zxf /tmp/phpMyAdmin-4.9.7-all-languages.tar.gz

# RUN mv phpMyAdmin-4.9.7-all-languages /var/www/html/phpmyadmin
# RUN rm -f /tmp/phpMyAdmin-4.9.7-all-languages.tar.gz
# # RUN mkdir /etc/phpmyadmin/upload -p
# # RUN mkdir /etc/phpmyadmin/save
# # RUN mkdir /etc/phpmyadmin/tmpls
# # RUN mkdir /var/www/html/phpmyadmin/tmp
# # RUN chown www-data.www-data /var/www/html/phpmyadmin -R
# # RUN chown www-data.www-data /etc/phpmyadmin -R
# # RUN chmod 660  /etc/phpmyadmin -R
# # RUN chmod 777 /var/www/html/phpmyadmin/tmp -R
# RUN mv config.inc.php /var/www/html/phpmyadmin/config.inc.php
#########################################################

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
