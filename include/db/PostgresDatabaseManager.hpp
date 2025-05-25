#ifndef JOBAPPLICATION_HPP
#define JOBAPPLICATION_HPP

#include "data/JobApplication.hpp"

struct JobApplication;

class PostgresDatabaseManager {
public:
  void insertJobApplication(const JobApplication& job);

private:
  static constexpr int DEFAULT_PORT_NUMBER = 5432;

  int portNumber_ = DEFAULT_PORT_NUMBER;

  void craftQuery();
};

#endif // JOBAPPLICATION_HPP
