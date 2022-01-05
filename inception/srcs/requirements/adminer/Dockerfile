FROM debian:buster
RUN apt-get update && apt-get -y install wget

#############
# RUN wget "https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1-mysql.php"
# RUN touch ciao
# RUN mkdir -p var/www/html
# RUN ls /var/www/html
# RUN mv ciao /var/www/html/
# RUN mv adminer-4.8.1-mysql.php /var/www/html/adminer.php
# RUN chown -R www-data:www-data /var/www/html/adminer.php

COPY ["./tools/start_adminer.sh", "/"]

ENTRYPOINT ./start_adminer.sh