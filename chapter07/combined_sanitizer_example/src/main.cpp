#include <iostream>
#include <limits>

void somefunc(){
    int x = std::numeric_limits<int>::max();
    x += 1; // Integer overflow here
    std::cout << "X is " << x << "\n";
    
}

int main(int, char **) {
  int *i = new int[10];
  delete[] i;
  std::cout << i[0] << "\n";
  somefunc();
  return 0;
}