#include "Factory01.h"
#include "SingleList.h"

Factory01::Factory01()
{
}

Factory01::~Factory01()
{
}
 
void * Factory01::create(std::string name)
{
  if(name == "ISingleNode"){
    return NULL;
  } else if(name == "ISingleList"){
    return new SingleList();
  } else if(name == "IDoubleNode"){
    return NULL;
  } else if(name == "IDoubleList"){
    return NULL;
  } else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory01();  
}

}
