#!/bin/bash

set -e

# Valider les variables requises (viennent du .env via docker-compose)
: "${MYSQL_ROOT_PASSWORD:?missing MYSQL_ROOT_PASSWORD}"
: "${MYSQL_PASSWORD:?missing MYSQL_PASSWORD}"
: "${MYSQL_DATABASE:?missing MYSQL_DATABASE}"
: "${MYSQL_USER:?missing MYSQL_USER}"

# Créer le socket directory
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

# Initialiser SEULEMENT au premier démarrage
if [ ! -f /var/lib/mysql/.initialized ]; then
	echo "Initializing MariaDB..."
	
	# Initialiser la structure de la base
	mysql_install_db --user=mysql --datadir=/var/lib/mysql
	
	# Démarrer temporairement MariaDB en arrière-plan
	mysqld --user=mysql --datadir=/var/lib/mysql &
	pid=$!
	
	# Attendre que MariaDB soit prêt
	echo "Waiting for MariaDB to start..."
	for i in {1..30}; do
		if mysqladmin ping --silent; then
			echo "MariaDB is ready!"
			break
		fi
		sleep 1
	done
	
	# Exécuter les commandes SQL
	mysql -u root << EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
FLUSH PRIVILEGES;
EOF
	
	# Arrêter proprement MariaDB
	mysqladmin -u root -p"$MYSQL_ROOT_PASSWORD" shutdown
	wait $pid
	
	# Marquer comme initialisé
	touch /var/lib/mysql/.initialized
	echo "MariaDB initialized successfully."
fi

# Lancer MariaDB en foreground
exec "$@"