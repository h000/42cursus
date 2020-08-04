until mysql
do
	echo -n "waiting"
done

mysql -u root mysql < /tmp/createdb.sql