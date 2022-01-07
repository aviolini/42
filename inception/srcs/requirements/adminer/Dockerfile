FROM debian:buster
RUN apt-get update && apt-get -y install wget

#############
RUN wget "https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql.php"

ENTRYPOINT mv adminer-4.8.1-mysql.php /var/www/html/adminer.php