#include <cstdint>
#include <library/library.hpp>

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t *data,
                                      std::size_t size) {
                                          chapter11::ex01::message_printer printer;
  printer.print(reinterpret_cast<const char *>(data), size);

  return 0;
}