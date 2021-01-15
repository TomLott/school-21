FROM alpine:latest

#RUN apk update && apk upgrade
RUN apk add nginx openssl openssh supervisor

COPY ./srcs/nginx/nginx.conf /etc/nginx/conf.d/default.conf

RUN openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=RU/ST=-/L=-/O=-/OU=-/CN=ft_services"

COPY ./srcs/start.sh /tmp/
RUN     chmod +x /tmp/start.sh
RUN     mkdir -p /run/nginx
EXPOSE 80 443

CMD ["/tmp/start.sh"]
