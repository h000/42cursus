FROM alpine

#telegraf 설치 및 설정
RUN apk update
RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.14.0-static_linux_amd64.tar.gz \
&& tar -xzf telegraf-1.14.0-static_linux_amd64.tar.gz \
&& mv /telegraf /etc/ \
&& rm -rf telegraf-1.14.0-static_linux_amd64.tar.gz
COPY ./telegraf.conf /etc/telegraf/

CMD /etc/telegraf/telegraf