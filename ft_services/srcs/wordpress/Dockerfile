FROM alpine:3.12.3

RUN apk add --no-cache wget php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session
RUN apk add --no-cache bash nginx wget supervisor openrc

RUN adduser -D -g 'www' www
RUN rc-update add php-fpm7 default

RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www
RUN rm -rf /etc/nginx/conf.d/default.conf

RUN mkdir -p /var/run/nginx
RUN mkdir -p /var/run/php
RUN touch /var/run/nginx/nginx.pid

COPY start.sh /
RUN chmod 755 /start.sh

COPY nginx.conf /etc/nginx/nginx.conf
COPY supervisord.conf /etc/supervisord.conf
COPY wp-config.php /var/www/wordpress/wp-config.php

ADD https://wordpress.org/latest.tar.gz .
RUN tar -xvzf latest.tar.gz -C /var/www && rm -f latest.tar.gz

EXPOSE 5050

CMD ["sh", "start.sh"]