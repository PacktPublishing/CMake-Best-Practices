#include "fibonacci.h"

uint64_t Fibonacci(uint64_t number) {
    return number < 2 ? 1 : Fibonacci(number - 1) + Fibonacci(number - 2);
}