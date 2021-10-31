/**
 * ______________________________________________________
 * Calculator implementation
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <chapter6/ex06/lib.hpp>
#include <iostream>

int main(void){
    // Aliases for shortcut
    using namespace chapter6::ex01;

    constexpr auto sum = &calculator::sum;
    constexpr auto div = &calculator::div;
    constexpr auto mul = &calculator::mul;
    constexpr auto sub = &calculator::sub;

    std::cout << "5 + 6: " << sum(5, 6) << std::endl;
    std::cout << "5 - 6: " << sub(5, 6) << std::endl;
    std::cout << "5 * 6: " << mul(5, 6) << std::endl;
    std::cout << "5 / 6: " << div(5, 6) << std::endl;
}