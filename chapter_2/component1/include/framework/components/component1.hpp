/**
 * ______________________________________________________
 * Component-1 interface description
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#pragma once

#include <framework/components/component_interface.hpp>

namespace framework {
namespace components {

/**
 * @brief Component 1 interface
 */
class component1 : public component_interface {
public:
  /**
   * @brief Construct a new component1 object
   */
  component1();

  /**
   * @brief Destroy the component1 object
   */
  virtual ~component1() override;

  /**
   * @brief Do some work
   *
   * @return true on success, false on failure
   */
  virtual bool do_stuff() const override;

  /**
   * @brief Do other stuff
   *
   * @param param Argument
   * @return int Stuffs completed
   */
  virtual int do_other_stuff(int param) override;
}; // class component1
} // namespace components
} // namespace framework