#include "internal.hpp"

#include <iostream>

namespace hello::details{ 
    void print_impl(const std::string& name)
    {
        std::cout << "Hello " << name << " from a shared library\n";
    }
}