FROM alpine:3.12.3
USER root

RUN apk update && apk upgrade
RUN apk add nginx openssl openrc bash

COPY nginx.conf /etc/nginx/conf.d/default.conf
COPY start.sh /

RUN chmod -R 777 ./start.sh
RUN mkdir -p /run/nginx

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -out nginx-selfsigned.crt \
    -keyout nginx-selfsigned.key \
     -subj "/C=RU/ST=-/L=-/O=-/OU=-/CN=ft_services"

#RUN ssh-keygen -A && adduser -D ssh_admin && echo "ssh_admin:1111" | chpasswd

EXPOSE 80 443

CMD ["sh", "start.sh"]
