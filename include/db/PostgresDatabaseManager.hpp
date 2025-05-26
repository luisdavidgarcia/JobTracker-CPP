#ifndef POSTGRESDATABASEMANAGER_HPP
#define POSTGRESDATABASEMANAGER_HPP

#include "data/JobApplication.hpp"
#include <pqxx/pqxx>

class PostgresDatabaseManager {
public:
  void insertJobApplication(const JobApplication& job);

private:
  static constexpr int DEFAULT_PORT_NUMBER = 5432;

  int portNumber_ = DEFAULT_PORT_NUMBER;

  void craftQuery();
};

#endif // POSTGRESDATABASEMANAGER_HPP
