/**
 * ______________________________________________________
 * @file tests.cpp
 *
 * Simple unit tests
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

// Example taken from
// https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

unsigned int Factorial(unsigned int number) {
  return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
  REQUIRE(Factorial(10) == 3628800);
}