FROM alpine

RUN apk update && apk upgrade
RUN apk add openssh
RUN apk add openssl
RUN apk add nginx
#RUN apk add letegraf (ссылка)

# creating user for web server
RUN adduser -D -g 'www' www

RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www
RUN mkdir -p /run/nginx

COPY nginx.conf /etc/nginx/
COPY index.html /www/
#COPY script.js /www/

RUN adduser -D user
RUN echo "user:password" | chpasswd
RUN ssh-keygen -A
RUN yes "" | openssl req -x509 -nodes -day 365 -newkey rsa:2048\
	-keyout /etc/ssl/private/server.key \
	-out /etc/ssl/certs/server.crt

RUN mkdir -p /etc/telegraf
COPY ./telegraf.conf /etc/telegraf/

RUN echo '--SSH--' > /etc/motd

COPY start.sh ./
RUN chmod +x /start.sh
CMD sh ./start.sh
EXPOSE 80 443 22