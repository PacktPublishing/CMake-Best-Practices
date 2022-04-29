#include <obscure/obscure.hpp>

#include "internal.hpp"

namespace obscure{
    void Obscure::greet() const {
        details::print_impl(name_);
    }
}