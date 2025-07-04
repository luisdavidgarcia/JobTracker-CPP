#include "db/PostgresDatabaseManager.hpp"

auto PostgresDatabaseManager::insertJobApplication(const JobApplication& job) 
  -> void 
{
  // Docker container will set this environment variable
  auto dbURL = std::getenv("DATABASE_URL");
  if (!dbURL) {
    throw std::runtime_error("Enviroment variable DATABASE_URL is not set!");
  }
  pqxx::connection cx(dbURL);
  pqxx::work tx(cx);

  std::string sql = "INSERT INTO jobs (company_name, position_title," 
                    " applied_date, max_salary, required_skills,"
                    " responsibilities)"
                    " VALUES ($1, $2, $3, $4, $5, $6)";

  tx.exec(sql, {job.companyName, job.positionTitle, job.formatDate(), 
                job.maxSalary, job.requiredSkills, 
                job.responsibilities});
  
  tx.commit();

  std::cout << "New job entry added successfully!" << std::endl;
}
