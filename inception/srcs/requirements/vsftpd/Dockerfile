FROM debian:buster
RUN apt-get update && apt-get -y install vsftpd vim ftp openssl

############# GENERA IL CERTIFICATO RSA
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.pem -out /etc/ssl/private/vsftpd.pem -subj "/C=US/ST=USA/L=Springfield/O=Dis/CN=www.example.com"

#############
COPY ["./conf/vsftpd.conf", "/"]
RUN mv vsftpd.conf /etc/

COPY ["./tools/start_vsftpd.sh", "/"]
ENTRYPOINT ./start_vsftpd.sh