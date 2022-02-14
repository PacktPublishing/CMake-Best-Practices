/**
 * ______________________________________________________
 * URI helper implementation
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <library/uri_helper.hpp>

namespace chapter11 {
namespace ex02 {

char *uri_helper::decode(const char *str) {
  thread_local char result[100];
  for (auto *p = result; *str; ++str) {
    if (*str == '%') {
      const auto a = *++str;
      const auto b = *++str;
      *p++ = (a <= '9' ? a - '0' : a - 'a') * 16 + (b <= '9' ? b - '0' : b - 'a');
    } else if (*str == '+') {
      // replace + with space
      *p++ = ' ';
    } else {
      // copy as-is
      *p++ = *str;
    }
  }
  return result;
}

} // namespace ex02
} // namespace chapter11