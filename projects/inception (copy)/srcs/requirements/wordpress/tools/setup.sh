#!/bin/bash

# Lire les secrets Docker (si présents) et exporter en variables d'environnement
if [ -f /run/secrets/mysql_password ] && [ -z "${MYSQL_PASSWORD}" ]; then
  export MYSQL_PASSWORD="$(cat /run/secrets/mysql_password)"
fi
if [ -f /run/secrets/wp_password ] && [ -z "${WP_PASSWORD}" ]; then
  export WP_PASSWORD="$(cat /run/secrets/wp_password)"
fi
if [ -f /run/secrets/wp_admin_password ] && [ -z "${WP_ADMIN_PASSWORD}" ]; then
  export WP_ADMIN_PASSWORD="$(cat /run/secrets/wp_admin_password)"
fi

# Install WordPress only if the volume is empty
if [ ! -f /var/www/html/index.php ]; then

    echo "Installation de WordPress..."
    
    # Download and extract WordPress core files
    wget https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    rm -f latest.tar.gz
    mv wordpress/* .
    rm -rf wordpress

    # Create wp-config.php and connect to MariaDB service
    wp config create --allow-root \
        --dbname=$MYSQL_DATABASE \
        --dbuser=$MYSQL_USER \
        --dbpass=$MYSQL_PASSWORD \
        --dbhost=mariadb \
        --path='/var/www/html'

    # Install WordPress and create administrator user
    wp core install --allow-root \
        --url=$DOMAIN_NAME \
        --title="Inception kpires" \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL

    # Create standard user
    wp user create --allow-root \
        $WP_USER $WP_ADMIN_EMAIL \
        --user_pass=$WP_PASSWORD \
        --role=author

    # Set file permissions for the webserver
    chown -R www-data:www-data /var/www/html
    
    echo "WordPress installé et configuré."
fi

# Start PHP-FPM in foreground (PID 1)
echo "Démarrage de PHP-FPM en foreground..."
/usr/sbin/php-fpm8.2 -F
