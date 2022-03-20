#include <iostream>
#include "fibonacci.h"
#include "eratosthenes.h"

int main(int, char**)
{
    std::cout << "Welcome to chapter 14\n";
    std::cout << "Fibonacci(3) = " << Fibonacci(3) << "\n";
    std::cout << "Primes before 10:\n";
    const auto primes = eratosthenes(10);
    for (const auto& i : primes)
    {
     std::cout << i << " ";
    }
    std::cout << "\n";
}