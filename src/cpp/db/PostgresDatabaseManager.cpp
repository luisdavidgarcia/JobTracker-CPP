#include "db/PostgresDatabaseManager.hpp"

auto PostgresDatabaseManager::getEnvVar(std::string_view key) 
  -> std::optional<std::string> 
{
  if (const char* val = std::getenv(key.data())) {
    return std::string{val};
  }
  return std::nullopt;
}
