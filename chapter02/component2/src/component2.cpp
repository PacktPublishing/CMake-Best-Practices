/**
 * ______________________________________________________
 * Component-2 implementation
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <framework/components/component2.hpp>

#include <cmath>
#include <iostream>

namespace framework {
namespace components {

component2::component2() {
  std::cout << "Component 2 is constructed" << std::endl;
}

component2::~component2() {
  std::cout << "Component 2 is destructed" << std::endl;
}

bool component2::do_stuff() const { return true; }

int component2::do_other_stuff(int param) { return std::sqrt(param) * 2; }
} // namespace components
} // namespace framework