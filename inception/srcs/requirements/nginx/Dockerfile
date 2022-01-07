FROM debian:buster
RUN apt-get update && apt-get -y install nginx openssl less vim procps

############# GENERA IL CERTIFICATO RSA
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"

############# COPIA FILE CONFIGURAZIONE SERVER
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI '##ADDING SETTING'
RUN cp /etc/nginx/sites-available/default /etc/nginx/sites-available/default.copy
COPY ["./conf/default", "/etc/nginx/sites-available/default"]

############# COPIA DEL FILE DELLE IMPOSTAZIONI DI NGINX
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI '##ADDING SETTING'
RUN cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf.copy
COPY ["./conf/nginx.conf","/etc/nginx/nginx.conf"]

############# ACCESSO GARANTITO ALL'UTENTE E AL GRUPPO www-data
RUN chown -R www-data:www-data /var/www/html/
RUN chmod -R 775 /var/www/html/

ENTRYPOINT service nginx start