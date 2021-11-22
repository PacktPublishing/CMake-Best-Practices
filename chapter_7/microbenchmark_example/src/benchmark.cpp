#define CATCH_CONFIG_MAIN /* This tells Catch to provide a main() - only do    */

#include <catch2/catch.hpp>

std::uint64_t Fibonacci(std::uint64_t number) {
    return number < 2 ? 1 : Fibonacci(number - 1) + Fibonacci(number - 2);
}

TEST_CASE("Fibonacci") {
    CHECK(Fibonacci(0) == 1);
    // some more asserts..
    CHECK(Fibonacci(5) == 8);
    // some more asserts..

    // now let's benchmark:
    BENCHMARK("Fibonacci 5") {
        return Fibonacci(5);
    };

    BENCHMARK("Fibonacci 10") {
        return Fibonacci(10);
    };

    BENCHMARK("Fibonacci 15") {
        return Fibonacci(15);
    };

}