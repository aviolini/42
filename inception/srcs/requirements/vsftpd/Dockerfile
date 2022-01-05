FROM debian:buster
RUN apt-get update && apt-get -y install vsftpd

#############

COPY ["./tools/start_vsftpd.sh", "/"]

ENTRYPOINT ./start_vsftpd.sh