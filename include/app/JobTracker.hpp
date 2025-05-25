#ifndef JOBTRACKER_HPP
#define JOBTRACKER_HPP

#include <iostream>

#include "cli/CommandLineParser.hpp"
#include "db/PostgresDatabaseManager.hpp"
#include "llm/OllamaAPIClient.hpp"

class JobTracker {
public:
  JobTracker(int argc, char* argv[]);

  void run();

private:
  CommandLineParser commandParser_;
  OllamaAPIClient ollamaLLM_;
  PostgresDatabaseManager databaseManager_;
};

#endif // JOBTRACKER_HPP
