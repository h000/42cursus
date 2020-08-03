FROM alpine

RUN apk update && apk upgrade

RUN apk add grafana --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
RUN mkdir -p /etc/grafana/provisioning/dashboards

COPY ./dashboards /var/lib/grafana/dashboards/
COPY ./provisioning/dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/
COPY ./provisioning/datasources.yaml /usr/share/grafana/conf/provisioning/datasources/


EXPOSE 3000

CMD /usr/sbin/grafana-server --config=/usr/share/grafana/conf/defaults.ini --homepath=/usr/share/grafana