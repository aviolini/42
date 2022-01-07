FROM debian:buster
RUN apt-get update && apt-get -y install vsftpd vim ftp openssl

############# ARG PERMETTE DI AVERE VARIABILI IN INGRESSO
ARG WP_ADMIN
ARG WP_ADMIN_PASSWORD

############# GENERA IL CERTIFICATO RSA
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.pem -out /etc/ssl/private/vsftpd.pem -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"

############# COPIA DEL FILE DI CONFIGURAZIONE
COPY ["./conf/vsftpd.conf", "/etc/vsftpd.conf"]

############# CREAZIONE UTENTE CON LE CREDENZIALI DELL'UTENTE ADMIN DI WORDPRESS
RUN useradd -m -g www-data -p $(perl -e"print crypt(${WP_ADMIN_PASSWORD}, aa)") ${WP_ADMIN}

############# ISCRIZIONE UTENTE ALLA LISTA DI vsftpd
RUN echo "${WP_ADMIN}" >> /etc/vsftpd.userlist

RUN mkdir -p /var/run/vsftpd/empty

ENTRYPOINT vsftpd
