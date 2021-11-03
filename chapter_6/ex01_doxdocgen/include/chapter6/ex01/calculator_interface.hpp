/**
 * ______________________________________________________
 * @file calculator_interface.hpp
 *
 * Calculator interface declaration
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#pragma once

namespace chapter6 {
namespace ex01 {
/**
 * @brief The 'calculator' class interface
 *
 * Contains the minimum set of functions that a calculator class must implement.
 */
class calculator_interface {
public:
  /**
   * Calculate the sum of two numbers, @p augend lhs and @p addend
   *
   * @param [in] augend The number to which @p addend is added
   * @param [in] addend The number which is added to @p augend
   *
   * @return double Sum of two numbers, @p lhs and @p rhs
   */
  virtual double sum(double augend, double addend) = 0;

  /**
   * Calculate the difference of @p rhs from @p lhs
   *
   * @param [in] minuend    The number to which @p subtrahend is subtracted
   * @param [in] subtrahend The number which is to be subtracted from @p minuend
   *
   * @return double Difference of two numbers, @p minuend and @p subtrahend
   */
  virtual double sub(double minuend, double subtrahend) = 0;

  /**
   * Multiply @p multiplicand with @p multiplier
   *
   * @param [in] multiplicand The number which is to be multiplied by @p
   * multiplier
   * @param [in] multiplier   The number which is to multiply @p multiplicand
   *
   * @return double Product of two numbers, @p multiplicand and @p multiplier
   */
  virtual double mul(double multiplicand, double multiplier) = 0;

  /**
   * Divide @p dividend with @p divisor
   *
   * @param [in] dividend The number to be divided by @p divisor
   * @param [in] divisor  The number by which @p divisor is to be divided
   *
   * @return double Quotient of two numbers, @p dividend and @p divisor
   */
  virtual double div(double dividend, double divisor) = 0;

  /**
   * Destructor
   */
  virtual ~calculator_interface() = default;
}; // class calculator_interface
} // namespace ex01
} // namespace chapter6