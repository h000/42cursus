CREATE DATABASE wordpress;
CREATE USER 'wp'@'localhost' identified by '00';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wp'@'localhost' WITH GRANT OPTION;
FLUSH PRIVILEGES;
update mysql.user set plugin='' where user='wp';