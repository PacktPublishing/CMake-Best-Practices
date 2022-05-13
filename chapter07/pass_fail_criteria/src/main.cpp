#include <iostream>

int main(int argc, char **) {

  if (argc == 1) {
    std::cout << "Error: No arguments passed\n";
  } else if (argc % 2 == 0) {
    std::cout << "Success: Odd number of arguments" << std::endl;
  } else {
    std::cout << "Warning: Even number of arguments" << std::endl;
  }

  return argc % 2;
}