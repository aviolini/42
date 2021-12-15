#!/bin/bash

docker build . --tag nginx_image && \
docker run -itd --rm --name=nginx_cont -p 80:80 -p 443:443 nginx_image && \
printf "\e[0;32mnginx succesfully started\e[0m\n"
