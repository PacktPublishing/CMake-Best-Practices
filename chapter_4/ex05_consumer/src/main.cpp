/**
 * ______________________________________________________
 * Chapter-4 example application
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

// Here we can see consumer can easily include and use our package.

#include <chapter4/ex05/lib.hpp>

int main(void){
    chapter4::ex05::greeter g;
    g.greet();
}