#pragma once

#include <string>

namespace hello_object {
/// Example class that is explicitly exported into a dll
class HelloObject {
public:
  HelloObject(const std::string &name) : name_{name} {}

  void greet() const;

private:
  const std::string name_;
};
} // namespace hello_object