#include "cli/CommandLineParser.hpp"

const std::unordered_set<std::string_view> CommandLineParser::acceptedModels_{
  "Ollama3.2", "Ollama3.3"
};

void CommandLineParser::parseModelName(int argc, const char* argv[]) {
  const std::vector<std::string_view> args(argv + 1, argv + argc);

  if (args.size() != 2) {
    throw std::runtime_error("Usage: --model <model_name>");

  }

  if (args.at(0) != "--model" && args.at(0) != "-m") {
    throw std::runtime_error("Only --model/-m are allowed arguments");
  }

  // TODO: Verify with a set that modelName_ is valid
  modelName_ = std::string(args.at(1));
}
