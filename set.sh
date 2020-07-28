export MINIKUBE_HOME=~/goinfre

#minikube 시작 (virtualbox에서, nodeport 1-35000으로)
minikube --vm-driver=virtualbox start --extra-config=apiserver.service-node-port-range=1-35000

#minikube 웹 대시보드
minikube dashboard &

#docker 이미지와 minikube에서 사용할 수 있게?
eval $(minikube docker-env)

docker build -t nginx-image ./nginx

kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.3/manifests/metallb.yaml
kubectl apply -f config.yaml

kubectl create -f nginx.yaml

minikube service list