FROM alpine:latest

RUN apk update
RUN apk add mariadb-server

RUN service mysql start && mysql -u root mysql < /createdb.sql