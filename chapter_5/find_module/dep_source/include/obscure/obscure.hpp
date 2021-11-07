#pragma once 

#include <string>

namespace obscure{
    /// Example class that is explicitly exported into a dll
    class Obscure {
        public:
        Obscure(const std::string& name) : name_{name} {}

        void greet() const; 
        private:
        const std::string name_;
    };
}