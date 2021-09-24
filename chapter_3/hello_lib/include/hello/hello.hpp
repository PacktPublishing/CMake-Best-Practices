#pragma once 

#include <string>

namespace hello{
    class Hello {
        public:
        Hello(const std::string& name) : name_{name} {}

        void greet() const; 
        private:
        const std::string name_;
    };
}