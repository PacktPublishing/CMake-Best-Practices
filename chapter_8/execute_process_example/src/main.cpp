#include <iostream>

#ifndef VERSION
#define VERSION unknown
#endif

const char git_rev[] = VERSION;

int main() {
  std::cout << "This file was built on the git revision: " << git_rev
            << std::endl;
}