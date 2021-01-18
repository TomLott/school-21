FROM alpine:3.12.3

COPY init_file my.cnf telegraf.conf start.sh wordpress.sql ./

RUN apk add --no-cache mysql mysql-client

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.2_linux_amd64.tar.gz
RUN tar -zxf telegraf-1.15.2_linux_amd64.tar.gz
RUN  mv telegraf-1.15.2 telegraf
RUN  rm telegraf-1.15.2_linux_amd64.tar.gz
RUN cp -r telegraf/* /

EXPOSE 3306

CMD ./start.sh