FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y vim
RUN apt-get install -y nginx 
RUN apt-get install -y php7.3-common php7.3-fpm php7.3-mysql php7.3-mbstring php7.3
RUN apt-get install -y wget
RUN apt-get install -y mariadb-server

COPY ./srcs/nginx.conf /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/

WORKDIR /
COPY ./srcs/ai.sh .

WORKDIR /var/www/server
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
RUN chown -R www-data:www-data /var/www/server/wordpress
WORKDIR /var/www/server/wordpress
COPY ./srcs/wp-config.php .



WORKDIR /
COPY ./srcs/website.html ./var/www/server


RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN tar -xzvf phpMyAdmin-5.0.4-english.tar.gz && rm -rf phpMyAdmin-5.0.4-english.tar.gz
RUN mv phpMyAdmin-5.0.4-english/ /var/www/server/phpmyadmin

COPY ./srcs/config.inc.php /var/www/server/phpmyadmin

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/nginx-selfsigned.key \
	-out /etc/ssl/certs/nginx-selfsigned.crt \
	-subj "/C=RU/ST=Tatarstan/L=Kazan/OU=School/CN=localhost"

RUN chown -R www-data:www-data /var/www
RUN chmod -R 755 /var/www/*
COPY ./srcs/init.sh ./

EXPOSE 80 443
CMD bash init.sh

