#include "utils/EnvironmentConfig.hpp"

void EnvironmentConfig::loadEnvFile(const std::filesystem::path& filePath) {
  if (!std::filesystem::exists(filePath)) {
    throw std::runtime_error("Could not find .env file: " + filePath.string());
  }

  if (!std::filesystem::is_regular_file(filePath)) {
    throw std::runtime_error(filePath.string() + " is not a regular file");
  }

  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Could not find .env file: " + filePath.string());
  }

  std::string line;
  while (std::getline(file,  line)) {
    if (line.empty() || line[0] == '#') continue;

    size_t equalPos = line.find('=');
    if (equalPos == std::string::npos) continue;

    std::string key = line.substr(0, equalPos);
    std::string value = line.substr(equalPos+1);

    // Removal of white space
    key.erase(0, key.find_first_not_of(" \t"));
    key.erase(key.find_last_not_of(" \t") + 1);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);

    // Remove any extra quotation marks
    value.erase(0, value.find_first_not_of("\""));
    value.erase(value.find_last_not_of("\"") + 1);

    setenv(key.c_str(), value.c_str(), 1);
    std::fill(value.begin(), value.end(), '\0');
  }
}
