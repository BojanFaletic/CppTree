#include "parser.hpp"
#include <iostream>

#include "loader.hpp"
using namespace std;

int main() {
  Parser pa;

  pa.add("Hello", 1);
  pa.add("Az", 8);
  pa.add("Azz", 4);
  pa.add("Hi", 2);

  cout << pa.parse("Hi") << "\n";
  return 0;
}