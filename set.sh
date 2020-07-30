export MINIKUBE_HOME=~/goinfre

#minikube 시작 (virtualbox에서, nodeport 1-35000으로)
minikube --vm-driver=virtualbox start --extra-config=apiserver.service-node-port-range=1-35000

#minikube 웹 대시보드
minikube dashboard &

#docker 이미지와 minikube에서 사용할 수 있게?
eval $(minikube docker-env)

export IP=$(kubectl get node -o=custom-columns='DATA:status.addresses[0].address' | sed -n 2p)
printf "Minikube IP: ${IP}\n"

docker build -t nginx-image ./nginx
docker build -t mysql-image ./mysql --build-arg IP=${IP}
docker build -t phpmyadmin-image ./phpmyadmin
docker build -t wordpress-image ./wordpress --build-arg IP=${IP}
docker build -t influxdb-image ./influxdb
docker build -t telegraph-image ./telegraph
docker build -t grafana-image ./grafana

# kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.3/manifests/metallb.yaml
kubectl apply -f meatallb-config.yaml

kubectl create -f nginx.yaml
kubectl create -f mysql.yaml
kubectl create -f phpmyadmin.yaml
kubectl create -f wordpress.yaml
kubectl create -f influxdb.yaml
kubectl create -f telegraph.yaml
kubectl create -f grafana.yaml

minikube service list