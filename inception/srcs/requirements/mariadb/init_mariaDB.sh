#!/bin/bash

docker build . --tag mariadb_image && \
docker run -itd --rm --name=mariadb_cont mariadb_image && \
printf "\e[0;32mmariaDB succesfully started\e[0m\n"
