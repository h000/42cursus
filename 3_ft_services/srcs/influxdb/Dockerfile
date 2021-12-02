FROM alpine

#influxDB 설치
RUN apk update
RUN apk add influxdb --no-cache 

VOLUME ["/var/lib/influxdb"]

EXPOSE 8086

RUN mkdir -p /run/influxd
ENTRYPOINT ["influxd"]