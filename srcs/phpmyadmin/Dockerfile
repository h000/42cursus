FROM alpine:latest

#php 및 wget 설치
RUN apk update && apk add wget \
&& apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

#phpmyadmin 설치 및 설정
WORKDIR /etc
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz \
&& tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz \
&& mv phpMyAdmin-5.0.1-english phpmyadmin
COPY config.inc.php phpmyadmin

EXPOSE 5000

CMD php -S 0.0.0.0:5000 -t /etc/phpmyadmin/