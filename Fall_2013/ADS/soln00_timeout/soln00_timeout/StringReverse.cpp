#include "StringReverse.h"

std::string StringReverse::reverse(std::string input)
{
  std::string ret = "";
  for(int i = input.size() - 1; i >= 0; --i){
    ret += input[i];
  }
  return ret;
}
