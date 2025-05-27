#ifndef POSTGRESDATABASEMANAGER_HPP
#define POSTGRESDATABASEMANAGER_HPP

#include "data/JobApplication.hpp"
#include <pqxx/pqxx>
#include <iostream>
#include <cstdlib>

class PostgresDatabaseManager {
public:
  void insertJobApplication(const JobApplication& job);

private:
  static constexpr int DEFAULT_PORT_NUMBER = 5432;

  int portNumber_ = DEFAULT_PORT_NUMBER;
};

#endif // POSTGRESDATABASEMANAGER_HPP
