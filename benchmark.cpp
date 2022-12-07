#include <benchmark/benchmark.h>

#include "loader.hpp"
#include "parser.hpp"
#include <random>

using namespace std;

static void Parse_10_000_elements(benchmark::State &state) {
  // Perform setup here
  Parser pa;
  Loader ld{"./test_cases/large.json"};

  auto data = ld.get();
  if (data.size() == 0) {
    assert(false && "unable to load file\n");
  }

  for (auto &it : data) {
    pa.add(it.first, it.second);
  }

  size_t idx = rand() % data.size();
  string search_item = data[idx].first;
  for (auto _ : state) {
    volatile int status = pa.parse(search_item);
  }
}

static void Parse_10_000_elements_naive(benchmark::State &state) {
  // Perform setup here
  Parser pa;
  Loader ld{"./test_cases/large.json"};

  auto data = ld.get();
  if (data.size() == 0) {
    assert(false && "unable to load file\n");
  }

  size_t idx = rand() % data.size();
  string search_item = data[idx].first;
  for (auto _ : state) {
    for (auto &it : data) {
      if (search_item == it.first) {
        volatile int status = it.second;
        break;
      }
    }
  }
}

// Register the function as a benchmark
BENCHMARK(Parse_10_000_elements);
BENCHMARK(Parse_10_000_elements_naive);

// Run the benchmark
BENCHMARK_MAIN();