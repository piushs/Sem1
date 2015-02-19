#pragma once

#include "Interfaces00.h"

#include <string>

class StringEcho : public IStringEcho {
public:
  StringEcho() {}
  ~StringEcho() {}
  std::string echo(std::string input);
};
