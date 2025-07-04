CURRENT_DIR := $(shell pwd)

setup-dockerignore:
	@export DOCKER_BUILDKIT=1

build-cpp-dev-env: setup-dockerignore
	@docker build -t cpp_dev_env -f Dockerfile.cpp-dev-env .

run-cpp-dev-env: build-cpp-dev-env
	@docker run -it --rm --env-file ".env" -v $(CURRENT_DIR):/app cpp_dev_env bash

start-prod: setup-dockerignore
	@docker compose up -d

run-prod:
	@docker compose run -it --rm cpp_prod bash

clean-prod:
	@docker compose down

.PHONY: setup-dockerignore build-cpp-dev-env run-cpp-dev-env start-prod run-prod clean-prod
