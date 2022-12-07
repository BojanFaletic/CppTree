#pragma once

#include <string>
#include <vector>

class Loader {
  std::vector<std::pair<std::string, int>> data;

public:
  Loader(std::string file_name);
  std::vector<std::pair<std::string, int>> get();
};