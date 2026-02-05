#!/bin/bash

# Generate self-signed SSL certificate if not exists
if [ ! -f /etc/nginx/ssl/nginx.crt ]; then
    echo "Generating SSL certificate..."
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/nginx.key \
        -out /etc/nginx/ssl/nginx.crt \
        -subj "/C=FR/ST=France/L=Paris/O=42/OU=42/CN=${DOMAIN_NAME}"
fi

# Start NGINX in foreground
echo "Starting NGINX..."
exec nginx -g 'daemon off;'