FROM alpine:latest
ARG IP

RUN apk update
RUN apk add pure-ftpd --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

#ssl 설정
RUN apk add --no-cache openssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=KR/ST=Korea/L=Seoul/O=innoaca/OU=42seoul/CN=hpark' -keyout /etc/ssl/private/pure-ftpd.pem -out /etc/ssl/private/pure-ftpd.pem
RUN chmod 600 /etc/ssl/private/pure-ftpd.pem

EXPOSE 20 21 30020 30021 

RUN adduser -D "admin"
RUN echo "admin:admin" | chpasswd

RUN echo $IP > ip.txt
CMD pure-ftpd -j -Y 2 -p 30020:30020 -p 30021:30021 -P $(cat ip.txt)