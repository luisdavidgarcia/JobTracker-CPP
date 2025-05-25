#ifndef OLLAMAPICLIENT_HPP
#define OLLAMAPICLIENT_HPP

#include "data/JobApplication.hpp"

class OllamaAPIClient {
public:
  JobApplication generateJobDescriptionFromText(const std::string& jobDesc);

private:
  static constexpr int DEFAULT_PORT_NUMBER = 11434;

  int portNumber_ = DEFAULT_PORT_NUMBER;
};

#endif // OLLAMAPICLIENT_HPP
