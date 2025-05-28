#include "app/JobTracker.hpp"

auto JobTracker::run() -> void {
  fastAPI_.connect();
  
  while (true) {
    const std::string jobDescription = inputJobDescription();
    fastAPI_.sendJobDescription(jobDescription);
    
    if (!askTOContinue()) break; 
    
    std::cout << '\n';
  }
   
  std::cout << "Exiting JobTracker, Goodbye!\n";
  fastAPI_.close();
}

[[nodiscard]]
auto JobTracker::inputJobDescription() -> std::string {
  std::cout << "Enter you job description:\n";

  std::string jobDescription;
  std::getline(std::cin, jobDescription);
  return jobDescription;
}

[[nodiscard]]
auto JobTracker::askTOContinue() -> bool {
  for (std::string response; ;) {
    std::cout << "Do you wish to continue? (y/n): ";
    std::cin >> response;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (response.size() == 1) {
      switch (std::tolower(response.front())) {
      case 'y':  return true;
      case 'n':  return false;
      }
    }

    std::cout << "Only input (y/n)! Try again.\n"; 
  }
}


