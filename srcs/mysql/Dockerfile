FROM alpine:latest
ARG IP

#mysql 설치 및 설정
RUN apk update \
&& apk add mysql mysql-client \
&& mkdir -p /run/mysqld

COPY my.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY createdb.sql /tmp/createdb.sql

RUN echo $IP > ip.txt

EXPOSE 3306

COPY mysql.sh /tmp/mysql.sh
COPY createdb.sh /tmp/createdb.sh

CMD sh /tmp/mysql.sh