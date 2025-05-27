#include "app/JobTracker.hpp"
#include "utils/EnvironmentConfig.hpp"
#include <stdexcept>
#include <iostream>
#include <filesystem>

int main() 
{
  try {
    std::filesystem::path envPath("../.env");
    EnvironmentConfig::loadEnvFile(envPath);
    
    JobTracker jobTracker;
    jobTracker.run();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }
  
  return 0;
}
