#!/bin/bash

rc default
/etc/init.d/mariadb setup
rc-service mariadb start

echo "CREATE DATABASE server;" | mysql
echo "CREATE USER 'root' WITH PASSWORD 'root';" | mysql
echo "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'root' WITH GRANT OPTIONS;" | mysql
echo "FLUSH PRIVILEGES;"

rc-service mariadb stop

/usr/bin/mysqld_safe
sh