/**
 * ______________________________________________________
 * Chapter-2 example framework driver application
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <framework/components/component1.hpp>
#include <framework/components/component2.hpp>

#include <cstdint>   // for std::uint8_t
#include <iostream>  // for std::cout, std::endl
#include <memory>    // for std::unique_ptr
#include <stdexcept> // for std::runtime_error

/**
 * @brief Component type
 */
enum class component_type : std::uint8_t { component1, component2 };

/**
 * @brief Make component
 *
 * @param [in] ct Component type
 * @return Component
 *
 * @exception Can throw when @p ct is undefined or if component constructor
 * throws.
 */
std::unique_ptr<framework::components::component_interface>
component_factory(component_type ct) noexcept(false) {
  switch (ct) {
  case component_type::component1:
    return std::unique_ptr<framework::components::component1>(
        new framework::components::component1());
  case component_type::component2:
    return std::unique_ptr<framework::components::component2>(
        new framework::components::component2());
  }
  throw std::runtime_error{"Invalid component type"};
}

/**
 * @brief Main entry point of the application
 *
 * @return int Application exit code
 */
int main(void) {

  auto component_1 = component_factory(component_type::component1);
  auto component_2 = component_factory(component_type::component2);

  if (component_1->do_stuff() || component_2->do_stuff()) {
    std::cout << "One of the component(s) did stuff" << std::endl;
  }

  return component_1->do_other_stuff(1) + component_2->do_other_stuff(3);
}