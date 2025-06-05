#include "data/JobApplication.hpp"

std::string JobApplication::formatDate() const {
  auto formattedDate = std::format("{:04}-{:02}-{:02}",
    static_cast<int>(appliedDate.year()),
    static_cast<unsigned int>(appliedDate.month()),
    static_cast<unsigned int>(appliedDate.day()));

  return formattedDate;
}

namespace boost {
namespace json {

std::chrono::year_month_day tag_invoke(
  const value_to_tag<std::chrono::year_month_day>&, value const& jv)
{
  std::chrono::year_month_day date;
  std::istringstream iss{jv.as_string().c_str()};
  iss >> std::chrono::parse("%Y-%m-%d", date);

  if (iss.fail()) {
    throw std::runtime_error("Invalid date format, expected YYYY-MM-DD");
  }

  return date;
}

JobApplication tag_invoke(const value_to_tag<JobApplication>&, value const& jv)
{
  object const& jobDetails = jv.as_object();
  JobApplication job;

  if (jobDetails.contains("company_name")) {
    job.companyName = value_to<std::string>(jobDetails.at("company_name"));
  }

  if (jobDetails.contains("position_title")) {
    job.positionTitle = value_to<std::string>(jobDetails.at("position_title"));
  }

  if (jobDetails.contains("applied_date")) {
    job.appliedDate = value_to<std::chrono::year_month_day>(
      jobDetails.at("applied_date"));
  }

  if (jobDetails.contains("max_salary")) {
    job.maxSalary = value_to<int>(jobDetails.at("max_salary"));
  }

  if (jobDetails.contains("required_skills")) {
    job.requiredSkills = value_to<std::string>(jobDetails.at("required_skills"));
  }

  if (jobDetails.contains("responsibilities")) {
    job.responsibilities = value_to<std::string>(jobDetails.at("responsibilities"));
  }

  return job;
}

} // namespace json
} // namespace boost

