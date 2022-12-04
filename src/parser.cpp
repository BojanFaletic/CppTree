#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

class Parser {
  pair<string, int> value;
  vector<unique_ptr<Parser>> next;

public:
  Parser(string name, int value){
    this->value = {name, value};
  }

  void add(string name, int value) {
    auto pt = make_unique<Parser>(Parser(name, value));
    next.push_back(move(pt));
  }

  int parse(string name) {
    for (auto const &p : next){
      Parser const *pt = p.get();
      if (pt->value.first == name){
        return pt->value.second;
      }
    }
    return -1;
  }
};