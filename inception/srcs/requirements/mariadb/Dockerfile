FROM debian:10.10
RUN apt update && apt -y install mariadb-server mariadb-client
ENTRYPOINT service mysql start && /bin/bash
#oppure
#COPY ["run_nginx.sh", "/"]
#ENTRYPOINT ["./run_nginx.sh"]
