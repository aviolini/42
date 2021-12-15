FROM debian:10.10
RUN apt update && apt -y install nginx
EXPOSE 80 433
ENTRYPOINT service nginx start && /bin/bash
#oppure
#COPY ["run_nginx.sh", "/"]
#ENTRYPOINT ["./run_nginx.sh"]
