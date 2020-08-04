FROM alpine:latest

#php 설치
RUN apk update \
&& apk add wget php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

#wordpress 설치 및 설정
WORKDIR /etc
RUN wget https://wordpress.org/latest.tar.gz \
&& tar -zxvf latest.tar.gz
COPY wp-config.php wordpress

EXPOSE 5050

CMD php -S 0.0.0.0:5050 -t /etc/wordpress/