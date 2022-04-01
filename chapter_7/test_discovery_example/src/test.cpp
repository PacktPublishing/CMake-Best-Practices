#define CATCH_CONFIG_MAIN /* This tells Catch to provide a main() - only do */

#include <catch2/catch.hpp>

std::uint64_t Fibonacci(std::uint64_t number) {
  return number < 2 ? 1 : Fibonacci(number - 1) + Fibonacci(number - 2);
}

TEST_CASE("Fibonacci(0) returns 1") { REQUIRE(Fibonacci(0) == 1); }
TEST_CASE("Fibonacci(1) returns 1") { REQUIRE(Fibonacci(1) == 1); }
TEST_CASE("Fibonacci(2) returns 2") { REQUIRE(Fibonacci(2) == 2); }
TEST_CASE("Fibonacci(5) returns 8") { REQUIRE(Fibonacci(5) == 8); }
