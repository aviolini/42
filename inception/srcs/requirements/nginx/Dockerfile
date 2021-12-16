FROM debian:10.10
RUN apt update && apt -y install nginx
EXPOSE 80 433
ENTRYPOINT service nginx start && /bin/bash
				# && /bin/bash togliere dal momento che
				# nel file init_mariaDB.sh c'è -it?