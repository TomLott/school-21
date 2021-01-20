FROM alpine:3.12.3

RUN apk add --no-cache mysql mysql-client openrc

COPY start.sh /
RUN chmod -R 755 /start.sh

COPY my.cnf /etc/mysql

VOLUME ["/var/lib/"]
VOLUME ["/sys/fs/cgroup"]

EXPOSE 3306

CMD ["sh", "/start.sh"]