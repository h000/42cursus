FROM alpine:latest

RUN apk update && apk add wget
RUN apk add php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

WORKDIR /etc
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz \
&& tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz \
&& mv phpMyAdmin-5.0.1-english phpmyadmin

COPY config.inc.php phpmyadmin

EXPOSE 5000
CMD php -S 0.0.0.0:5000 -t /etc/phpmyadmin/