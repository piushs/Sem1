#pragma once

#include "Interfaces00.h"

#include <string>

class StringReverse : public IStringReverse {
public:
  StringReverse() {}
  ~StringReverse() {}
  std::string reverse(std::string input);
};
