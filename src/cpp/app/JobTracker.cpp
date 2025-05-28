#include "app/JobTracker.hpp"

[[nodiscard]]
auto JobTracker::inputJobDescription() -> std::string {
  std::cout << "Enter you job description:\n";

  std::string jobDescription;
  std::getline(std::cin, jobDescription);
  return jobDescription;
}

