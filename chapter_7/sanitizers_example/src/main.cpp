#include <iostream>

int main(int, char **) {
  int *i = new int[10];
  delete[] i;
  std::cout << i[0] << "\n";
  return 0;
}