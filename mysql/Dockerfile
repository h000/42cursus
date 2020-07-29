FROM alpine:latest
#ARG IP

RUN apk update
RUN apk add mysql mysql-client

RUN mkdir -p /run/mysqld
COPY my.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY createdb.sql /tmp/createdb.sql

# RUN echo $IP > ip.txt
# VOLUME ["/var/lib/mysql"]

EXPOSE 3306

COPY mysql.sh /tmp/mysql.sh
COPY createdb.sh /tmp/createdb.sh

CMD sh /tmp/mysql.sh