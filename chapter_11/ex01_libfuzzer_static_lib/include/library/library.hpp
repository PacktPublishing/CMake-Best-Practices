/**
 * ______________________________________________________
 * Message printer interface declaration
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#pragma once

#include <cstdint>

namespace chapter11 {
namespace ex01 {
/**
 * @brief The 'message_printer' class interface
 */
class message_printer {
public:
  /**
   * Print a message to stdout
   *
   * @param [in] msg Message to print
   * @param [in] len Length of the message
   */
  void print(const char *msg, std::uint32_t len);
}; // class message_printer
} // namespace ex01
} // namespace chapter11