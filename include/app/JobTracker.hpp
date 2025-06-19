#ifndef JOBTRACKER_HPP
#define JOBTRACKER_HPP

#include <iostream>
#include <limits>
#include <boost/asio/io_context.hpp>
#include <boost/json.hpp>
#include <optional>
#include <string_view>

#include "llm/FastAPIClient.hpp"
#include "db/PostgresDatabaseManager.hpp"

class JobTracker {
public:
  auto run() -> void;

private:
  boost::asio::io_context ioc_;
  FastAPIClient fastAPI_{ioc_};
  PostgresDatabaseManager databaseManager_;

  [[nodiscard]] auto inputJobDescription() -> std::string;
  [[nodiscard]] auto askTOContinue() -> bool; 

  static constexpr std::string_view SENTINEL{"__DONE__"};
};

#endif // JOBTRACKER_HPP
