#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <assert.h>

#include "loader.hpp"
#include "parser.hpp"

using namespace std;

void load_parser(Loader &ld, Parser &pa) {
  assert(ld.get().size() > 0);
  for (auto &entry : ld.get()) {
    pa.add(entry.first, entry.second);
  }
}

TEST(Parser, add) {
  Parser pa;
  Loader ld{"./test_cases/add_new.json"};

  load_parser(ld, pa);
  for (pair<string, int> item : ld.get()){
    EXPECT_EQ(pa.parse(item.first), item.second);
  }
}

TEST(Parser, assign) {
  Parser pa;
  Loader ld{"./test_cases/assign.json"};

  load_parser(ld, pa);
  for (pair<string, int> item : ld.get()){
    EXPECT_EQ(pa.parse(item.first), item.second);
  }
}

TEST(Parser, branch) {
  Parser pa;
  Loader ld{"./test_cases/branch.json"};

  load_parser(ld, pa);
  for (pair<string, int> item : ld.get()){
    EXPECT_EQ(pa.parse(item.first), item.second);
  }
}

TEST(Parser, insert_new) {
  Parser pa;
  Loader ld{"./test_cases/insert_new.json"};

  load_parser(ld, pa);
  for (pair<string, int> item : ld.get()){
    EXPECT_EQ(pa.parse(item.first), item.second);
  }
}

TEST(Parser, full) {
  Parser pa;
  Loader ld{"./test_cases/full.json"};

  load_parser(ld, pa);
  for (pair<string, int> item : ld.get()){
    EXPECT_EQ(pa.parse(item.first), item.second);
  }
}

TEST(Parser, large) {
  Parser pa;
  Loader ld{"./test_cases/large.json"};

  load_parser(ld, pa);
  for (pair<string, int> item : ld.get()){
    EXPECT_EQ(pa.parse(item.first), item.second);
  }
}