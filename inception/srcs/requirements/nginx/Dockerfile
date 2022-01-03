FROM debian:buster
RUN apt-get update && apt-get -y install nginx openssl less vim procps

#GENERA IL CERTIFICATO RSA
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"

#COPIA DEI FILE DI CONFIGURAZIONE
COPY ["./conf/default", "/"]
COPY ["./conf/index.nginx-debian.html","/"]
COPY ["./conf/nginx.conf","/"]

#COPIA FILE CONFIGURAZIONE SERVER
RUN cp /etc/nginx/sites-available/default /etc/nginx/sites-available/default.copy
RUN mv default /etc/nginx/sites-available/default

#COPIA DELLA PAGINA INIZIALE MODIFICATA
RUN mv index.nginx-debian.html /var/www/html/index.nginx-debian.html

#COPIA DEL FILE DELLE IMPOSTAZIONI DI NGINX
RUN cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf.copy
RUN mv nginx.conf /etc/nginx/

#ACCESSO GARANTITO ALL'UTENTE www-data
RUN chown -R www-data:www-data /var/www/html/



COPY ["./tools/start_nginx.sh", "/"]
ENTRYPOINT ./start_nginx.sh