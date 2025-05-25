#ifndef COMMANDLINEPARSER_HPP
#define COMMANDLINEPARSER_HPP

#include <vector>
#include <string_view>
#include <stdexcept>
#include <unordered_set>
#include <iostream>

static constexpr std::string DEFAULT_MODEL_NAME{"Ollama3.2"};

class CommandLineParser {
public:
  CommandLineParser(OllamaAPIClient ollama,
                    PostgresDatabaseManager db,
                    JobApplication job)
    :  ollamaLLM_(ollama), databaseManager_(db), jobApplication_(job) {}

  void parseModelName(int argc, const char* argv[]);

  std::string getModelName() const { return modelName_; }

  void submitJobApplication();

private:
  std::string modelName_ = DEFAULT_MODEL_NAME;
  static const std::unordered_set<std::string_view> acceptedModels_;
  OllamaAPIClient ollamaLLM_;
  PostgresDatabaseManager databaseManager_;
  JobApplication& jobApplication_;
};

#endif // COMMANDLINEPARSER_HPP
