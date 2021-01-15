#!/bin/sh

ssh-keygen -A

nginx -g 'daemon off;'
/usr/sbin/sshd -D