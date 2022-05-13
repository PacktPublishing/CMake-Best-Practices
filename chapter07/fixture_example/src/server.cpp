#include <iostream>

int main(int argc, char **argv) {
  if (argc > 1) {
    std::cout << "Teardown\n";
  } else {
    std::cout << "setup\n";
  }

  return 0;
}