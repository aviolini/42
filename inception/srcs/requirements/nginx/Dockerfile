FROM debian:10.10
RUN apt update && apt -y install nginx openssl less vim
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"
COPY ["./conf/default", "/"]
RUN mv default /etc/nginx/sites-available/default
# COPY ["./conf/default", "/etc/nginx/sistes-available/default"]
ENTRYPOINT service nginx start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?