#include "loader.hpp"
#include "parser.hpp"
#include <gtest/gtest.h>

#include <string>
#include <vector>
using namespace std;

void load_parser(Loader &ld, Parser &pa) {
  for (auto &entry : ld.get()) {
    pa.add(entry.first, entry.second);
  }
}

TEST(Parser, add) {
  Parser pa;
  Loader ld{"/home/bojan/git/CppTree/test_cases/add_new.json"};

  load_parser(ld, pa);
  for (pair<string, int> item : ld.get()){
    EXPECT_EQ(pa.parse(item.first), item.second);
  }
}