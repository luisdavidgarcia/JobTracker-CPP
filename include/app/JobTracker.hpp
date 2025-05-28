#ifndef JOBTRACKER_HPP
#define JOBTRACKER_HPP

#include <iostream>
#include <limits>
#include <boost/asio/io_context.hpp>
#include <boost/json.hpp>
#include <optional>

#include "llm/FastAPIClient.hpp"
#include "db/PostgresDatabaseManager.hpp"


class JobTracker {
public:
  JobTracker() : ioc_(), fastAPI_(ioc_), databaseManager_() {}
  auto run() -> void;

private:
  boost::asio::io_context ioc_;
  FastAPIClient fastAPI_;
  PostgresDatabaseManager databaseManager_;

  [[nodiscard]] auto inputJobDescription() -> std::string;
  [[nodiscard]] auto askTOContinue() -> bool; 
};

#endif // JOBTRACKER_HPP
