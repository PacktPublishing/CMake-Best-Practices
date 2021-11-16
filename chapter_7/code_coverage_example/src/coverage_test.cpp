#include <vector>
#include <algorithm>

#include <coverage_example/coverage_example.h>
#include <cassert>

int main(int, char **) {

 auto result = coverage_example::check_for_divisibilty(15); 
 assert(std::find(result.begin(), result.end(), 2) == result.end());
 assert(std::find(result.begin(), result.end(), 3) != result.end());
 assert(std::find(result.begin(), result.end(), 5) != result.end());
 assert(std::find(result.begin(), result.end(), 7) == result.end());

  return 0;
}