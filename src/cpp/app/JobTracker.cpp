#include "app/JobTracker.hpp"

auto JobTracker::run() -> void {
  fastAPI_.connect();
  
  while (true) {
    const auto description = inputJobDescription();

    if (const std::optional<JobApplication> response = 
        fastAPI_.sendJobDescription(description)) 
    {
      databaseManager_.insertJobApplication(response.value());
    } else {
      std::cerr << "Empty result received.\n";
    }
    
    if (!askTOContinue()) break; 
    
    std::cout << '\n';
  }
   
  std::cout << "Exiting JobTracker, Goodbye!\n";
  fastAPI_.close();
}

[[nodiscard]]
auto JobTracker::inputJobDescription() -> std::string {
  std::cout << "Enter you job description and press CTRL+D after:\n\n";

  std::string jobDescription{};
  std::string line{};
  
  while (std::getline(std::cin, line)) {
    jobDescription += line + "\n";
  }

  return jobDescription;
}

[[nodiscard]]
auto JobTracker::askTOContinue() -> bool {
  for (std::string response; ;) {
    std::cout << "Do you wish to continue? (y/n): ";
    std::cin >> response;

    if (response.size() == 1) {
      switch (std::tolower(response.front())) {
      case 'y':  return true;
      case 'n':  return false;
      }
    }

    std::cout << "Only input (y/n)! Try again.\n"; 
  }
}


