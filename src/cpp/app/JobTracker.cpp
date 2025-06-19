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
  std::cout << "Enter the job description.\n";
  std::cout << "When you are finished, type '" << SENTINEL; 
  std::cout << "' on a new line and press Enter.\n\n";

  std::string jobDescription{};
  std::string line{};
  
  while (std::getline(std::cin, line)) {
    if (line == SENTINEL) break;
    
    jobDescription += line + "\n";
  }

  return jobDescription;
}

[[nodiscard]]
auto JobTracker::askTOContinue() -> bool {
  for (std::string response; ;) {
    std::cout << "\nDo you wish to continue? (y/n): ";
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


