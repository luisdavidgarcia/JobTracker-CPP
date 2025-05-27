#ifndef ENVIROMENTCONFIG_HPP
#define ENVIROMENTCONFIG_HPP

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

class EnvironmentConfig {
public:
  static void loadEnvFile(const std::filesystem::path& filePath);
};

#endif // ENVIROMENTCONFIG_HPP
