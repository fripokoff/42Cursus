#!/bin/bash

# Create the run directory for mysqld socket
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

# Ensure the data directory belongs to the mysql user
chown -R mysql:mysql /var/lib/mysql

usermod -u $(stat -c '%u' /var/lib/mysql) mysql 2>/dev/null || true
groupmod -g $(stat -c '%g' /var/lib/mysql) mysql 2>/dev/null || true

# Lire les secrets Docker (si présents) et exporter en variables d'environnement
if [ -f /run/secrets/mysql_root_password ] && [ -z "${MYSQL_ROOT_PASSWORD}" ]; then
  export MYSQL_ROOT_PASSWORD="$(cat /run/secrets/mysql_root_password)"
fi
if [ -f /run/secrets/mysql_password ] && [ -z "${MYSQL_PASSWORD}" ]; then
  export MYSQL_PASSWORD="$(cat /run/secrets/mysql_password)"
fi
if [ -f /run/secrets/wp_password ] && [ -z "${WP_PASSWORD}" ]; then
  export WP_PASSWORD="$(cat /run/secrets/wp_password)"
fi
if [ -f /run/secrets/wp_admin_password ] && [ -z "${WP_ADMIN_PASSWORD}" ]; then
  export WP_ADMIN_PASSWORD="$(cat /run/secrets/wp_admin_password)"
fi

# Force cleanup and initialization (use marker file to detect first run)
echo "Checking database state..."
if [ ! -f "/var/lib/mysql/.initialized" ]; then
    
    echo "Initializing database..."
    
    # Clean ALL pre-existing files (even from package install)
    rm -rf /var/lib/mysql/*
    rm -rf /var/lib/mysql/.[!.]*
    
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    tfile=`mktemp`
    
    cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES;

-- Update 'root' user password
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

-- Create WordPress database
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE} CHARACTER SET utf8 COLLATE utf8_general_ci;

-- Create WordPress user and grant all privileges
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';

FLUSH PRIVILEGES;
EOF

    # Start the server in a secure, bootstrap mode to execute the script
    /usr/sbin/mariadbd --user=mysql --bootstrap < $tfile
    rm -f $tfile
    
    # Create marker file to indicate successful initialization
    touch /var/lib/mysql/.initialized
    
    echo "Database initialized."
fi

# Launch in Foreground (PID 1)
echo "Starting MariaDB in foreground..."
exec /usr/sbin/mariadbd --user=mysql --console