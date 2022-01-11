FROM debian:buster
RUN apt-get update && apt-get -y install nginx openssl

############# ARG PERMETTE DI AVERE VARIABILI IN INGRESSO
ARG NGINX_PRIVATE_CERT

############# COPIA FILE CONFIGURAZIONE SERVER
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI '##ADDING SETTING'
RUN cp /etc/nginx/sites-available/default /etc/nginx/sites-available/default.copy
COPY ["./conf/default", "/etc/nginx/sites-available/default"]

############# COPIA DEL FILE DELLE IMPOSTAZIONI DI NGINX
#LE IMPOSTAZIONI MODIFICATE SI TROVANO IN CORRISPONDENZA DEI COMMENTI '##ADDING SETTING'
RUN cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf.copy
COPY ["./conf/nginx.conf","/etc/nginx/nginx.conf"]

############# COPIA PAGINE html
COPY ["conf/index.html", "/tmp/index.html"]
RUN chown www-data:www-data /tmp/index.html
COPY ["conf/ftp-instr.html", "/tmp/ftp-instr.html"]
RUN chown www-data:www-data /tmp/ftp-instr.html

############# GENERA IL CERTIFICATO RSA
RUN mkdir -p ${NGINX_PRIVATE_CERT}
RUN chmod 700 ${NGINX_PRIVATE_CERT}
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout ${NGINX_PRIVATE_CERT}/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"
RUN chmod 640 ${NGINX_PRIVATE_CERT}/nginx-selfsigned.key
RUN sed -i --expression "s@ssl_certificate_key.*@ssl_certificate_key ${NGINX_PRIVATE_CERT}/nginx-selfsigned.key;@" /etc/nginx/sites-available/default

ENTRYPOINT nginx