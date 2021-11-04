/**
 * ______________________________________________________
 * @file main.cpp
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <iostream>
#include <string>

/**
 * @brief Main entry point of the application

  @startuml{system_interaction.png} "System Interaction Diagram"
  user -> executable : main()
  user -> stdin : input text
  executable -> stdin: read_stdin()
  stdin -> executable
  executable -> stdout: print_to_stdout()
  stdout -> user : visual feedback
  @enduml
 *
 * @return int Exit code
 */
int main(void) {
  std::cout << "Greetings from the echo application!" << std::endl;
  std::string input;
  while (std::getline(std::cin, input)) {
    std::cout << input;
  }
}