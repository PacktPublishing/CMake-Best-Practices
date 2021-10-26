#include "internal.hpp"

#include <iostream>

namespace obscure::details{ 
    void print_impl(const std::string& name)
    {
        std::cout << "Hello " << name << " from an obscure library\n";
    }
}