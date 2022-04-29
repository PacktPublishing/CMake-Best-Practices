#include <iostream>

#include "version.h"

int main() {
  std::cout << "This file was built on the git revision: "
            << CMAKE_BEST_PRACTICES_VERSION << std::endl;
}