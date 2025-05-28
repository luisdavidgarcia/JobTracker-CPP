#ifndef POSTGRESDATABASEMANAGER_HPP
#define POSTGRESDATABASEMANAGER_HPP

#include "data/JobApplication.hpp"
#include <pqxx/pqxx>
#include <iostream>
#include <cstdlib>
#include <format>
#include <optional>

class PostgresDatabaseManager {
public:
  auto insertJobApplication(const JobApplication& job) -> void;

private:
  inline static constexpr int DEFAULT_PORT_NUMBER = 5432;

  int portNumber_ = DEFAULT_PORT_NUMBER;

  auto getEnvVar(std::string_view key) -> std::optional<std::string>;
};

#endif // POSTGRESDATABASEMANAGER_HPP
