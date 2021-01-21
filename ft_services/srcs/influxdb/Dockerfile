FROM alpine:3.12.3


COPY start.sh ./

RUN apk add --no-cache influxdb wget supervisor ca-certificates

RUN		wget -q -O /etc/apk/keys/sgerrand.rsa.pub \
		https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.2_linux_amd64.tar.gz
RUN tar -zxf telegraf-1.15.2_linux_amd64.tar.gz
RUN mv telegraf-1.15.2 telegraf
RUN rm telegraf-1.15.2_linux_amd64.tar.gz
RUN cp -r telegraf/* /

EXPOSE 8086
CMD ./start.sh