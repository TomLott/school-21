#!/bin/bash

minikube start --vm-driver=virtualbox
eval $(minikube docker-env)
minikube addons enable metallb
kubectl apply -f configmap.yaml
kubectl apply -f volume.yaml

docker build -t nginx_image /nginx/
kubectl apply -f nginx.yaml

minikube dashboard
