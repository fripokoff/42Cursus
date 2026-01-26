FROM debian:bookworm

# 1. Installation des dépendances
RUN apt-get update && \
    apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

# 2. Copie de la configuration et des scripts
COPY ./tools/setup.sh /usr/local/bin/
COPY ./conf/default.conf /etc/nginx/conf.d/

# 3. Création des dossiers du certificat et permission d'exécution
RUN mkdir -p /etc/nginx/ssl
RUN chmod +x /usr/local/bin/setup.sh

# 4. Port HTTPS par défaut
EXPOSE 443

# 5. Lance le script d'initialisation (génération SSL) et démarre NGINX en foreground
CMD ["/usr/local/bin/setup.sh"]
