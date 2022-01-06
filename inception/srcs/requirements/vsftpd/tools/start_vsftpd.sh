#!/bin/bash
#############
useradd -m -p $(perl -e"print crypt($WP_ADMIN_PASSWORD, aa)") $WP_ADMIN
echo "$WP_ADMIN" >> /etc/vsftpd.userlist
service vsftpd start

/bin/bash