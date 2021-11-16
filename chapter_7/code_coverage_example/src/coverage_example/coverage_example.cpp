#include <coverage_example/coverage_example.h>
#include <vector>

namespace coverage_example {
std::vector<int> check_for_divisibilty(int i) {

  std::vector<int> result;

  if (i % 2 == 0) {
    result.push_back(2);
  }
  if (i % 3 == 0) {
    result.push_back(3);
  }
  if (i % 5 == 0) {
    result.push_back(5);
  }
  if (i % 7 == 0) {
    result.push_back(7);
  }

  return result;
}

} // namespace coverage_example