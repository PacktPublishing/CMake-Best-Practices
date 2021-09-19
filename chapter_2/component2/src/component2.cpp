/**
 * ______________________________________________________
 * Component-2 implementation
 * 
 * @file 	component2.cpp
 * @author 	Mustafa Kemal GILOR <mustafagilor@gmail.com>
 * @date 	19.09.2021
 * 
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <framework/components/component2.hpp>

#include <iostream>
#include <cmath>

namespace framework{
    namespace components {

        component2::component2(){
            std::cout << "Component 2 is constructed" << std::endl;
        }

        component2::~component2(){
            std::cout << "Component 2 is destructed" << std::endl;
        }

        bool component2::do_stuff() const  {
            return true;
        }

        int component2::do_other_stuff(int param) {
            return std::sqrt(param) * 2;
        }
    }
}