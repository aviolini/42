FROM debian:buster
RUN apt-get update && apt-get -y install nginx openssl less vim procps

#GENERA IL CERTIFICATO RSA
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"

#COPIA DEI FILE DI CONFIGURAZIONE
COPY ["./conf/default", "/"]
COPY ["./conf/index.nginx-debian.html","/"]
COPY ["./conf/nginx.conf","/"]

COPY ["./tools/start_nginx.sh", "/"]
ENTRYPOINT ./start_nginx.sh