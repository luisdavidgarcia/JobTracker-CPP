# JobTracker-CPP

In effort to leverage modern C++20 features and understand how to build
REST API's with Boost. I have opted to replicate my 
[JobTracker](https://github.com/luisdavidgarcia/JobTracker) application in
C++20. 

I will be leveraging CMake for our build system, Docker for housing
our PostgreSQL container and Ollama, and Clang for formatting and linting
our project.

## Structure

1. `main.cpp`: Here is where the command line parse will be activated so 
  that our program can start processing job applicaitons with Ollama and
  saving them to the Database

3. `FASTAPIClient.cpp`: Here is the REST API to interact with FASTAPI python
    service housing the spacy model

4. `PostgresDatabaseManager.cpp`: Contains the interface between Ollama output
    to database

5. `JobApplication.hpp`: contains the strucutre of a job application

6. `JobTrackerApp.cpp`: houses the core loop and state machince for processing
    requests

## Resources

1. [Boost Unit Testing](https://www.boost.org/doc/libs/latest/libs/test/doc/html/index.html)
2. [spaCy](https://spacy.io/)
3. [FastAPI](https://github.com/fastapi/fastapi)
4. [libpqxx](https://github.com/jtv/libpqxx)
