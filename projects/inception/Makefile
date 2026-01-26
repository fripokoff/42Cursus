# Makefile

COMPOSE_FILE := srcs/docker-compose.yml
DC := docker compose -f $(COMPOSE_FILE)
DATA_DIR := /home/fripok/data

all: checkenv setup build up

checkenv:
	@echo "--- Checking .env file ---"
	@if [ ! -f srcs/.env ]; then \
		echo "Error: srcs/.env file not found!"; \
		exit 1; \
	fi
	@bash -c 'set -a; . srcs/.env; set +a; \
		missing=0; \
		for var in MYSQL_DATABASE MYSQL_USER MYSQL_PASSWORD MYSQL_ROOT_PASSWORD DOMAIN_NAME WP_ADMIN_USER WP_ADMIN_PASSWORD WP_ADMIN_EMAIL WP_USER WP_PASSWORD; do \
			if [ -z "$${!var}" ]; then \
				echo "Error: $$var is missing in .env"; \
				missing=1; \
			fi; \
		done; \
		exit $$missing'
	@echo "✓ .env validation passed"

setup:
	@echo "--- Creating data directories ---"
	mkdir -p $(DATA_DIR)/wordpress

build:
	@echo "--- Building Docker images ---"
	$(DC) build

rebuild:
	@echo "--- Rebuilding Docker images (no cache) ---"
	$(DC) build --no-cache

up:
	@echo "--- Starting containers ---"
	$(DC) up -d

down:
	@echo "--- Stopping and removing containers and network ---"
	$(DC) down

clean: down
	@echo "--- Removing images and persistent volumes ---"
	docker rmi $$(docker images -q) 2>/dev/null || true
	docker volume rm mariadb_volume wordpress_volume 2>/dev/null || true

mariadb-cli:
	$(DC) exec mariadb mariadb -u root -p$(MYSQL_ROOT_PASSWORD)

.PHONY: all setup build rebuild up down clean mariadb-cli
