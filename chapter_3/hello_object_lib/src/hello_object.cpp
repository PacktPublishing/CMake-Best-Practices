#include <hello_object/hello_object.hpp>

#include <iostream>

namespace hello_object {
void HelloObject::greet() const {
  std::cout << "Hello " << name_ << " From an object library\n";
}
} // namespace hello_object