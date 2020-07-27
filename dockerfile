From debian:buster

#업데이트 & wget 설치 (phpmyadmin, wordpress 받을 때 사용)
RUN apt-get update && apt-get install -y wget
#nginx, mysql, php 설치
RUN apt-get install -y nginx
RUN apt-get install -y mariadb-server
RUN apt-get install -y php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring
#wordpress, phpmyadmin 설치
WORKDIR /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -zxvf latest.tar.gz 
#설정 파일
COPY ./src/config.inc.php phpmyadmin
COPY ./src/wp-config.php wordpress
COPY ./src/nginx.conf /etc/nginx/sites-available/default
COPY ./src/createdb.sql /
#SSL
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=KR/ST=Korea/L=Seoul/O=innoaca/OU=42seoul/CN=hpark' -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt
RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*
#php, nginx, mysql 실행 및 mysql db/유저 생성
COPY ./src/init.sh .
CMD bash init.sh