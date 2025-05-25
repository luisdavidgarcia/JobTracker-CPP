#ifndef COMMANDLINEPARSER_HPP
#define COMMANDLINEPARSER_HPP

#include <vector>
#include <string_view>
#include <stdexcept>
#include <unordered_set>
#include <iostream>

static constexpr std::string DEFAULT_MODEL_NAME{"llama3.2"};

class CommandLineParser {
public:
  void parseModelName(int argc, const char* argv[]);

  std::string promptJobDescriptionORExit();

  std::string getModelName() const { return modelName_; }

private:
  std::string modelName_ = DEFAULT_MODEL_NAME;
  static const std::unordered_set<std::string_view> acceptedModels_;
};

#endif // COMMANDLINEPARSER_HPP
