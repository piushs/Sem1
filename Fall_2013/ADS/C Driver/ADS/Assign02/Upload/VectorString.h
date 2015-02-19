#pragma once

#include "Interfaces02.h"
#include <string>



class VectorString : public IVectorString 
{
public:
  std::string value[5];
  int vssize;
    
  VectorString() 
  {
      vssize=0;
  }
  ~VectorString() {}
  void push_back(std::string item);
  void pop_back();
  std::string get(int index);
  void set(int index, std::string item);
  size_t size();
};
