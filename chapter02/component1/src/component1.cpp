/**
 * ______________________________________________________
 * Component-1 implementation
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <framework/components/component1.hpp>

#include <iostream>

namespace framework {
namespace components {

component1::component1() {
  std::cout << "Component 1 is constructed" << std::endl;
}

component1::~component1() {
  std::cout << "Component 1 is destructed" << std::endl;
}

bool component1::do_stuff() const { return false; }

int component1::do_other_stuff(int param) { return param; }
} // namespace components
} // namespace framework