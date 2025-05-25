#ifndef JOBAPPLICATION_HPP
#define JOBAPPLICATION_HPP

#include <string>
#include <vector>
#include <chrono>

struct JobApplication;

struct JobApplication {
  int id = -1;
  std::string company_name;
  std::string position_title;
  std::chrono::year_month_day applied_date;
  std::string salary_range;
  std::string company_challenge;
  std::vector<std::string> required_skills;
};

#endif // JOBAPPLICATION_HPP
