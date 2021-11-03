/**
 * ______________________________________________________
 * @file calculator.cpp
 *
 * Calculator implementation
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <chapter6/ex01/calculator.hpp>

namespace chapter6 {
namespace ex01 {

double calculator::sum(double augend, double addend) {
  return last_result = augend + addend;
}

double calculator::sub(double minuend, double subtrahend) {
  return last_result = minuend - subtrahend;
}

double calculator::mul(double multiplicand, double multiplier) {
  return last_result = multiplicand * multiplier;
}

double calculator::div(double dividend, double divisor) {
  return last_result = dividend / divisor;
}

} // namespace ex01
} // namespace chapter6