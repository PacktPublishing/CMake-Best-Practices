/**
 * ______________________________________________________
 * URI helper interface declaration
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#pragma once

namespace chapter11 {
namespace ex02 {
/**
 * @brief The 'uri_helper' class interface
 */
class uri_helper {
public:
  /**
   * Decode URI in @p str
   *
   * @param [in] str URI to decode
   * @return Decoded URI
   */
  char *decode(const char *str);

}; // class uri_helper
} // namespace ex02
} // namespace chapter11