#ifndef FASTAPICLIENT_HPP
#define FASTAPICLIENT_HPP

#include "data/JobApplication.hpp"

class FastAPIClient {
public:
  void sendJobDescription(const std::string& jobDescription);
  void recvJobDescriptionJson();

private:
  static  constexpr int DEFAULT_PORT_NUMBER = 8000;
  int portNumber_ = DEFAULT_PORT_NUMBER;
};

#endif // FASTAPICLIENT_HPP
