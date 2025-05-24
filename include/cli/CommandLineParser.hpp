#ifndef COMMANDLINEPARSER_HPP
#define COMMANDLINEPARSER_HPP

#include <vector>
#include <string_view>
#include <stdexcept>

class CommandLineParser {
private:
  std::string modelName_;

public:
  void parseModelName(int argc, const char* argv[]);
  std::string getModelName() const { return modelName_; }
};

#endif // COMMANDLINEPARSER_HPP
