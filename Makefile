CURRENT_DIR := $(shell pwd)

setup-dockerignore:
	@echo "Setting up Dockerignore"
	export DOCKER_BUILDKIT=1

build-cpp-dev-env: setup-dockerignore
	@docker build -t cpp_dev_env -f Dockerfile.cpp-dev-env .

run-cpp-dev-env: build-cpp-dev-env
	@docker run -it --rm --env-file ".env" -v $(CURRENT_DIR):/app cpp_dev_env bash

start-prod: setup-dockerignore
	@echo "Starting Production..."
	docker compose up -d
	@echo "Running JobTracker..."
	docker compose run -it --rm cpp_prod bash

clean-prod:
	@echo "Cleaning Production..."
	docker compose down

.PHONY: setup-dockerignore build-cpp-dev-env run-cpp-dev-env start-prod run-prod clean-prod
