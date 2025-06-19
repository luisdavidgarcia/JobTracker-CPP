#include <iostream>
#include <string>

int main() {
  std::string line{}, text{};

  std::cout << "Please press ctrl + d to denote you are done inputting job\n";

  while (std::getline(std::cin, line)) {
    text += line + '\n';
  }

  std::cout << "You entered: \n" << text << "\n";

  std::cout << "Goudabye\n";
  
  return 0;
}
