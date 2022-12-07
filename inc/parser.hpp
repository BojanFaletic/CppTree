#pragma once

#include <string>
#include <vector>

struct Node {
  std::string key;
  int value;
  std::vector<Node> next;
};

class Parser {
  std::vector<Node> root;

public:
  Parser();
  Parser(std::string name, int value);

  void add(std::string name, int value);
  int parse(std::string name);
};
