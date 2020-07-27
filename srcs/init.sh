service php7.3-fpm start
service nginx start
service mysql start && mysql -u root mysql < /createdb.sql

bash