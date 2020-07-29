FROM alpine:latest
ARG IP

RUN apk update
RUN apk add wget php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

WORKDIR /etc

RUN wget https://wordpress.org/latest.tar.gz \
&& tar -zxvf latest.tar.gz

COPY wp-config.php wordpress

# RUN echo $IP > ip.txt
# RUN export IP=$(cat /etc/ip.txt)
# RUN sed -i "s/MINIKUBE_IP/$IP/g" /etc/wordpress/wp-config.php

EXPOSE 5050
CMD php -S 0.0.0.0:5050 -t /etc/wordpress/