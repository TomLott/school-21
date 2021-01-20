#!/bin/bash

minikube start --vm-driver=virtualbox
eval $(minikube docker-env)
minikube addons enable metallb

kubectl apply -f configmap.yaml
kubectl apply -f volume.yaml

docker build -t nginx_image nginx/
kubectl apply -f nginx.yaml

docker build -t mysql_image mysql/
kubectl apply -f mysql.yaml

docker build -t wordpress_image wordpress/
kubectl apply -f wordpress.yaml

docker build -t phpmyadmin_image phpmyadmin/
kubectl apply -f phpmyadmin.yaml

docker build -t grafana_image grafana/
kubectl apply -f grafana.yaml

docker build -t influxdb_image influxdb/
kubectl apply -f influxdb.yaml

docker build -t ftps_image ftps/
kubectl apply -f ftps.yaml

minikube dashboard
