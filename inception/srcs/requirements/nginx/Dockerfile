FROM debian:10.10
RUN apt-get update && apt-get -y install nginx openssl less vim procps
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"
COPY ["./conf/default", "/"]
COPY ["./conf/index.nginx-debian.html","/"]
COPY ["./conf/nginx.conf","/"]
# RUN mv default /etc/nginx/sites-available/default
# COPY ["./conf/default", "/etc/nginx/sistes-available/default"]
COPY ["./tools/start_nginx.sh", "/"]
ENTRYPOINT ./start_nginx.sh
# ENTRYPOINT service nginx start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?