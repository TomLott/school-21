FROM alpine:3.12.3

RUN apk add vsftpd openssl bash

COPY start.sh /
RUN chmod 755 /start.sh

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -out /etc/ssl/certs/vsftpd.pem \
    -keyout /etc/ssl/private/vsftpd.key \
     -subj "/C=RU/ST=-/L=-/O=-/OU=-/CN=ft_services"

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf

EXPOSE 212

CMD ["sh", "start.sh"]