#!/bin/bash
############# CREAZIONE UTENTE CON LE CREDENZIALI DELL'UTENTE ADMIN DI WORDPRESS
useradd -m -g www-data -p $(perl -e"print crypt($WP_ADMIN_PASSWORD, aa)") $WP_ADMIN

############# ISCRIZIONE UTENTE ALLA LISTA DI vsftpd
echo "$WP_ADMIN" >> /etc/vsftpd.userlist

############# ACCESSO GARANTITO ALL'UTENTE E AL GRUPPO www-data
chmod -R 775 /var/www/html/wordpress

############# AVVIO DEL SERVIZIO
mkdir -p /var/run/vsftpd/empty
vsftpd