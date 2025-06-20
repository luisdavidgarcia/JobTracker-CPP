# JobTracker-CPP 💼

![JobTracker-Logo](logo.jpeg)

In effort to leverage modern C++20 features and understand how to build
REST API's with Boost. I have opted to replicate my 
[JobTracker](https://github.com/luisdavidgarcia/JobTracker) application in
C++20. 

I will be leveraging CMake for our build system, Docker for housing
our PostgreSQL container and Ollama, and Clang for formatting and linting
our project.

## Getting Started

### Prerequisites

1.First and foremost install `Docker` on your system. Follow Docker's [instructions](https://docs.docker.com/engine/install/)
- Docker
- Docker Compose
- Within these containers the following software will be included:
  - C++20
  - PostgreSQL
  - Python 3.11+
    - fastapi
    - spacy
    - uvicorn
  - libpqxx
  - clang
  - cmake
  - boost-devel
  - libpq-devel
  - gdb
  - valgrind

2.  Create a `.env` file in the project root with the following variables:

```sh
POSTGRES_USER=your_username
POSTGRES_PASSWORD=your_password
POSTGRES_DB=your_database_name
DB_HOST=localhost
DB_PORT=5432
DATABASE_URL="postgresql://${POSTGRES_USER}:${POSTGRES_PASSWORD}@${DB_HOST}:${DB_PORT}/${POSTGRES_DB}"
```

### Running

To run JobTracker in Linux/MacOS run the following commands in your terminal:

```sh
docker compose up -d \
# To ensure none of the containers have "Exited"
docker compose ps -a \

# Permits us to run the C++ Env in a Bash Shell
docker exec -it cpp_dev_env /bin/bash \

mkdir build \
cd build \
cmake .. \
cmake --build . \

./JobTracker

# Turn off and clean up all of the containers
docker compose down
```

## Structure

### System Architecture

```mermaid
graph TD
    subgraph "C++ Client & CLI"
        C[C++ Client App]
    end

    subgraph "FastAPI Spacy Backend"
        F[FastAPI Spacy App]
    end

    subgraph "Postgres Database"
        P[(Postgres DB)]
    end

    C-- 1.Connect (libpqxx) -->P
    C-- 2.POST /process_job -->F
    F-- 3.JSON Response -->C
    C-- 4.INSERT Query -->P
```

1. Internally C++ Client of JobTracker establishes a connection with the
   Database and FastAPI backend
2. Obtain the pasted Job Application from C++ Command Line Component and
   submit post request to FastAPI backend to process it
3. Retrieve the process Job Application as JSON in the C++ Client
4. Submit the JSON Job Application into the Database

### Directory and File Structure

```
.
├── CMakeLists.txt
├── compose.yaml
├── Dockerfile.cpp-dev-env
├── Dockerfile.spacy-ner
├── include
│   ├── app
│   │   └── JobTracker.hpp
│   ├── data
│   │   └── JobApplication.hpp
│   ├── db
│   │   └── PostgresDatabaseManager.hpp
│   ├── llm
│   │   └── FastAPIClient.hpp
│   └── utils
│       └── EnvironmentConfig.hpp
├── init.sql
├── README.md
├── requirements.txt
├── src
│   ├── cpp
│   │   ├── app
│   │   │   └── JobTracker.cpp
│   │   ├── data
│   │   │   └── JobApplication.cpp
│   │   ├── db
│   │   │   └── PostgresDatabaseManager.cpp
│   │   ├── llm
│   │   │   └── FastAPIClient.cpp
│   │   ├── main.cpp
│   │   └── utils
│   │       └── EnviromentConfig.cpp
│   └── python
│       ├── main.py
│       └── nlp_utils.py
└── tests
    ├── CMakeLists.txt
    └── pasteJobDescription_test.cpp
```

#### Core Files Explained Simply

1. `src/cpp/app/JobTracker.cpp`: This is the main program which contains the core logic for
    accepting pasted Job Applications, requesting the FastAPI backend to process it with Spacy,
    and saving the returned parsed JSON data to the Postgres database.
2. `src/cpp/data/JobApplication.cpp`: Contains the data structure that encapsulates a Job
   Application with fields specified in `init.sql`
3. `src/cpp/db/PostgresDatabaseManager.cpp`: Contains the libpqxx interface and logic to submit
   parsed, JSON applications to the database
4. `src/cpp/llm/FastAPIClient.cpp`: Serves as the backbone for creating POST requests to the
   FastAPI backend to process raw plain text Job Application
5. `src/cpp/utils/EnvrionmentConfig.cpp`: Parses your `.env` file for enviroment variables which
   are used for interacting and setting up the database
6. `src/python/main.py`: Creates the FastAPI backend which accepts POST requests and processes
    them into formatted JSON Job Application objects with the Natural Language Processing (NLP)
    utility `JobProcessor`
7. `src/python/nlp_utils.py`: Homes the `JobProcessor` class that executes the parsing logic to
    parse the raw plain text Job Application into a JSON format   

## Resources

1. [Boost Unit Testing](https://www.boost.org/doc/libs/latest/libs/test/doc/html/index.html)
2. [spaCy](https://spacy.io/)
3. [FastAPI](https://github.com/fastapi/fastapi)
4. [libpqxx](https://github.com/jtv/libpqxx)
5. [Docker Networking](https://www.netmaker.io/resources/docker-compose-network)
6. [Boost Json Conversions](https://www.boost.org/doc/libs/latest/libs/json/doc/html/json/conversion/custom_conversions.html)
7. [Boost Json Overloads](https://www.boost.org/doc/libs/latest/libs/json/doc/html/json/conversion/custom_conversions.html)
8. [Boost Json](https://www.boost.org/doc/libs/latest/libs/json/doc/html/index.html)
9. [Boost Beast](https://www.boost.org/doc/libs/latest/libs/beast/doc/html/index.html)
10. [Boost Asio](https://www.boost.org/doc/libs/1_73_0/doc/html/boost_asio/overview.html)
