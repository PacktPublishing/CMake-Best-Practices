/**
 * ______________________________________________________
 * @file benchmarks.cpp
 *
 * Simple microbenchmarks
 *
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#include <benchmark/benchmark.h>
#include <string>

// Define a simple benchmark
static void string_append(::benchmark::State &st) {
  std::string s;
  for (auto _ : st) {
    s += "a";
  }
}

// Register benchmark function
BENCHMARK(string_append);

// Define a main function that executes all registered benchmarks
BENCHMARK_MAIN();
