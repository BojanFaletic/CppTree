#include "loader.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

Loader::Loader(string file_name) {
  ifstream file(file_name);
  if (file.is_open()) {

    string word;
    int parser_state = 0;

    // extract JSON entry (name, value)
    regex pattern("\\s+\"(\\w+)\"\\s*\\:\\s*(\\d+).*");
    smatch match;

    while (getline(file, word)) {
      if (regex_match(word, match, pattern)) {
        string name = match[1];
        string value = match[2];
        data.push_back({name, stoi(value)});
      }
    }
  }
}

vector<pair<string, int>> Loader::get() { return data; }
