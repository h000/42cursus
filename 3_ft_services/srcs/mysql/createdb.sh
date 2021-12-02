until mysql
do
	echo -n "waiting"
done

IP=$(cat /ip.txt)
sed -i "s/192.168.99.106/$IP/g" /tmp/wordpress.sql

mysql -u root mysql < /tmp/createdb.sql