#include "db/PostgresDatabaseManager.hpp"

auto PostgresDatabaseManager::insertJobApplication(const JobApplication& job) 
  -> void 
{
  auto dbURL = getEnvVar("DATABASE_URL");
  if (!dbURL) {
    throw std::runtime_error("Enviroment variable DATABASE_URL is not set!");
  }
  pqxx::connection cx(*dbURL);
  pqxx::work tx(cx);

  auto formattedDate = std::format("{:04}-{:02}-{:02}",
    static_cast<int>(job.appliedDate.year()),
    static_cast<unsigned int>(job.appliedDate.month()),
    static_cast<unsigned int>(job.appliedDate.day()));

  std::string sql = "INSERT INTO jobs (company_name, position_title," 
                    " applied_date, max_salary, company_challenge,"
                    " required_skills, job_requirements)"
                    " VALUES ($1, $2, $3, $4, $5, $6, $7)";

  tx.exec(sql, {job.companyName, job.positionTitle, formattedDate, 
                job.maxSalary, job.companyChallenge, job.requiredSkills, 
                job.jobRequirements});
  
  tx.commit();

  std::cout << "New job entry added successfully!" << std::endl;
}

auto PostgresDatabaseManager::getEnvVar(std::string_view key) 
  -> std::optional<std::string> 
{
  if (const char* val = std::getenv(key.data())) {
    return std::string{val};
  }
  return std::nullopt;
}
