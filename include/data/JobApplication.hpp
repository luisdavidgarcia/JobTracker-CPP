#ifndef JOBAPPLICATION_HPP
#define JOBAPPLICATION_HPP

#include <string>
#include <vector>
#include <chrono>

struct JobApplication {
  int id = -1;
  std::string companyName;
  std::string positionTitle;
  std::chrono::year_month_day appliedDate;
  int maxSalary = 0;
  std::string companyChallenge;
  std::string requiredSkills;
  std::string jobRequirements;
};

#endif // JOBAPPLICATION_HPP
