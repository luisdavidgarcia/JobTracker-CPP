#include "app/JobTracker.hpp"
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[]) 
{
  try {
    JobTracker jobTracker(argc, argv);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }
  
  return 0;
}
