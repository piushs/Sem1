#pragma once

#include "ObjectFactory.h"

class Factory00 : public ObjectFactory {
public:
  Factory00();
  virtual ~Factory00();
  virtual void * create(std::string interface_name);
};
