#include <hello/hello.hpp>
#include <hello_header_only/hello_header_only.hpp>
#include <hello_object/hello_object.hpp>

int main(int, char **) {
  hello_header_only::print_hello("John Doe");
  hello::Hello hello("Jane Doe");
  hello.greet();
  return 0;
}