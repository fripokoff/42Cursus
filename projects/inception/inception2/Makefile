# Makefile

COMPOSE_FILE := srcs/docker-compose.yml

DC := docker compose -f $(COMPOSE_FILE)
DATA_DIR := /home/fripok/data

all: setup build up

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
