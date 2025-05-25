#include "cli/CommandLineParser.hpp"

const std::unordered_set<std::string_view> CommandLineParser::acceptedModels_{
  "Ollama3.2", "Ollama3.3"
};

void CommandLineParser::parseModelName(int argc, const char* argv[]) {
  const std::vector<std::string_view> args(argv + 1, argv + argc);

  // Will accept the default modelName_
  if (args.empty()) {
    return;
  }

  if (args.size() != 2) {
    throw std::runtime_error(
      "Usage: --model <model_name> or -m <model_name>\n"
      "       Example: --model MyModel or -m MyModel\n"
      "You must specify a model name after --model or -m.\n"
    );
  }

  if (args.at(0) != "--model" && args.at(0) != "-m") {
    throw std::runtime_error(
      "Invalid argument: " + std::string(args.at(0)) + "\n"
      "Usage: --model <model_name> or -m <model_name>\n"
      "       Example: --model MyModel or -m MyModel\n"
      "You can only use --model or -m to specify the model.");
  }

  // TODO: Verify with a set that modelName_ is valid
  modelName_ = std::string(args.at(1));
}
