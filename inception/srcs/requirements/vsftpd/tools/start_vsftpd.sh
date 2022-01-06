#!/bin/bash
#############

useradd -m tin #METTERE LE VARAIBILI AMBIENTE E LA PASSWORD
mkdir /home/tin/ftp
chmod a-w /home/tin/ftp
# chown -R tin:tin /home/tin/
mkdir /home/tin/ftp/files

echo "test file" >> /home/tin/ftp/files/test.txt
chown nobody:nogroup -R /home/tin/ftp

echo "tin" >> /etc/vsftpd.userlist
service vsftpd start

/bin/bash