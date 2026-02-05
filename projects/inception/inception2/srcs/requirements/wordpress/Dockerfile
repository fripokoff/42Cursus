FROM debian:bookworm

# 1. Installation des dépendances (PHP, PHP-FPM, WP-CLI)
RUN apt-get update && \
    apt-get install -y php-fpm php-mysqli php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip wget curl && \
    rm -rf /var/lib/apt/lists/* && \
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# 2. Configuration de PHP-FPM
# Change FPM listener from UNIX socket to TCP port 9000
RUN sed -i 's|listen = /run/php/php8.2-fpm.sock|listen = 9000|g' /etc/php/8.2/fpm/pool.d/www.conf && \
    sed -i 's|;listen.owner = www-data|listen.owner = www-data|g' /etc/php/8.2/fpm/pool.d/www.conf && \
    sed -i 's|;listen.group = www-data|listen.group = www-data|g' /etc/php/8.2/fpm/pool.d/www.conf

# 3. Preparation website directory
RUN mkdir -p /var/www/html
WORKDIR /var/www/html

# 4. Copy and set permissions for setup script
COPY ./tools/setup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup.sh

# 5. Internal PHP-FPM port
EXPOSE 9000

# 6. Launch setup script then PHP-FPM in foreground
CMD ["setup.sh"]
