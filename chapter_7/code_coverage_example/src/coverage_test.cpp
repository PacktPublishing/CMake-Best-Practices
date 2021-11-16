#include <iostream>

#include <coverage_example/coverage_example.h>
#include <cassert>

int main(int, char **) {

 auto result = coverage_example::check_for_divisibilty(15); 
 assert(result.find(2) != result.end());
 assert(result.find(3) != result.end());
 assert(result.find(5) != result.end());
 assert(result.find(7) == result.end());

  return 0;
}