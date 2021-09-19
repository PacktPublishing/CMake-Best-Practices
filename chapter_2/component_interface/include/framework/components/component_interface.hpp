/**
 * ______________________________________________________
 * Abstrace component interface description
 * 
 * @file 	component_interface.hpp
 * @author 	Mustafa Kemal GILOR <mustafagilor@gmail.com>
 * @date 	19.09.2021
 * 
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#pragma once

namespace framework {
    namespace components {
        /**
         * @brief Component interface 
         */
        class component_interface {
        public:

            /**
             * @brief Destroy the component1 object
             */
            virtual ~component_interface() = default;

            /**
             * @brief Do some work
             * 
             * @return true on success, false on failure
             */
            virtual bool do_stuff() const = 0;

            /**
             * @brief Do other stuff
             * 
             * @param param Argument
             * @return int Stuffs completed
             */
            virtual int do_other_stuff(int param) = 0;
        }; // class component_interface
    } // namespace component1
} // namespace chapter2