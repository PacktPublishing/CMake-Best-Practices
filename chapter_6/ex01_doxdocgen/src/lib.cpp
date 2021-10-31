/**
 * ______________________________________________________
 * Calculator implementation
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <chapter6/ex06/lib.hpp>

namespace chapter6 {
namespace ex01 {

double calculator::sum(double augend, double addend) { 
    return augend + addend; 
}

double calculator::sub(double minuend, double subtrahend) {
  return minuend - subtrahend;
}

double calculator::mul(double multiplicand, double multiplier) {
  return multiplicand * multiplier;
}

double calculator::div(double dividend, double divisor) {
  return dividend / divisor;
}

} // namespace ex01
} // namespace chapter6