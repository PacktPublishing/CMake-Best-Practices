#include <hello/hello.hpp>

#include "internal.hpp"

namespace hello{
    void Hello::greet() const {
        details::print_impl(name_);
    }
}