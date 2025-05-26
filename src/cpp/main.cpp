#include "app/JobTracker.hpp"
#include <stdexcept>
#include <iostream>

int main() 
{
  try {
    JobTracker jobTracker;
    jobTracker.run();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }
  
  return 0;
}
