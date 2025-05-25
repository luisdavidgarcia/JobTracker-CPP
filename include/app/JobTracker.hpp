#ifndef JOBTRACKER_HPP
#define JOBTRACKER_HPP

#include <iostream>
#include "cli/CommandLineParser.hpp"
#include "data/JobApplication.hpp"
#include "db/PostgresDatabaseManager.hpp"
#include "llm/OllamaAPIClient.hpp"

class JobTracker {
public:
  JobTracker(int argc, char* argv[]);

  static JobTracker create(int argc, char* argv[]);
  
  void run();

private:
  JobTracker(CommandLineParser parser,
             OllamaAPIClient ollama,
             PostgresDatabaseManager db,
             JobApplication job);

  CommandLineParser commandParser_;
  OllamaAPIClient ollamaLLM_;
  PostgresDatabaseManager databaseManager_;
  JobApplication jobApplication_;
};

#endif // JOBTRACKER_HPP
