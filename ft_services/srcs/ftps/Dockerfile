FROM alpine:3.12.3

RUN apk add vsftpd openssl bash

#COPY start.sh /
#RUN chmod 755 /start.sh

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -out /etc/ssl/certs/ftps.crt \
    -keyout /etc/ssl/private/ftps.key \
     -subj "/C=RU/ST=-/L=-/O=-/OU=-/CN=ft_services"

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf

RUN mkdir -p /var/log/ftp
RUN touch /var/log/ftp/xferlog

EXPOSE 21

RUN echo 'root:root' | chpasswd

ENTRYPOINT vsftpd /etc/vsftpd/vsftpd.conf