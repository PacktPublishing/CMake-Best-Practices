/**
 * ______________________________________________________
 * URI helper fuzzing driver application
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <library/uri_helper.hpp>
#include <iostream>

int main() {
	 const auto input = std::string(
		std::istreambuf_iterator<char>(std::cin),
		std::istreambuf_iterator<char>()
	);
	chapter11::ex02::uri_helper uut{};
	std::cout << uut.decode(input.c_str());
}