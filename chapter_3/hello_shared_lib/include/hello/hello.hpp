#pragma once 

#include <string>
#include "hello/export_hello.hpp"


namespace hello{
    /// Example class that is explicitly exported into a dll
    class CH3_HELLO_SHARED_EXPORT Hello {
        public:
        Hello(const std::string& name) : name_{name} {}

        void greet() const; 
        private:
        const std::string name_;
    };
}