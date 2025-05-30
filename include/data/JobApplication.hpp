#ifndef JOBAPPLICATION_HPP
#define JOBAPPLICATION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <format>
#include <sstream>
#include <boost/json.hpp>

class JobApplication {
public:
  std::string companyName;
  std::string positionTitle;
  std::chrono::year_month_day appliedDate;
  int maxSalary = 0;
  std::string requiredSkills;
  std::string responsibilities;

  std::string formatDate() const;
};

#endif // JOBAPPLICATION_HPP
