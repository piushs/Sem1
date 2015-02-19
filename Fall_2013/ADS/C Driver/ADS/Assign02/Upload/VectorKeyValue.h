#pragma once

#include "Interfaces02.h"
#include "KeyValue.h"
#include "VectorString.h"

class VectorKeyValue:public IVectorKeyValue {
public:
  size_t vksize;
  KeyValue *vkvalue;
  int init;
  VectorKeyValue() 
  {
     vksize=0;
	 init=0;
  }
  ~VectorKeyValue() {}
  void push_back(IKeyValue * item);
  void pop_back();
  IKeyValue * get(int index);
  void set(int index, IKeyValue * item);
  size_t size();
};
