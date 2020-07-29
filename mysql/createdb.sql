CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER 'wp'@'%' IDENTIFIED by '00';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wp'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;

-- CREATE DATABASE wordpress;
-- -- CREATE USER 'user'@'%' IDENTIFIED BY 'password';" | mysql -u root --skip-password && \
-- echo "GRANT ALL ON *.* TO 'user'@'%' WITH GRANT OPTION;" | mysql -u root --skip-password && \
-- echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password