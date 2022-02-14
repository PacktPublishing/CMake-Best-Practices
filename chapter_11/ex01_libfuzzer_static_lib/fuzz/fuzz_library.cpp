#include <cstdint>
#include <library/library.hpp>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t *data,
                                      std::size_t size) {
  chapter11::ex01::message_printer printer;
  printer.print(reinterpret_cast<const char *>(data), size);

  return 0;
}

// extern "C" int LLVMFuzzerInitialize(const int* argc, char*** argv) {
//   filepath = std::string(*argv[0]);
//   return 0;
// }


