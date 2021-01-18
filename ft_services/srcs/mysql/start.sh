/usr/bin/telegraf &
/usr/bin/mysql_install_db --datadir=/var/lib/mysql_install_db
/usr/bin/mysql --user=root --init_file=/init_file & sleep 5

#Создаем датабазу
mysql wordpress -u root < wordpress.sql

#Поддерживаем контенер рабочим
tail -f /dev/null