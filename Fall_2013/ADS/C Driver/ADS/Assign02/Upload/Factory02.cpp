#include "Factory02.h"
#include "PriorityQueue1.h"
#include "KeyValue.h"
#include "PriorityQueue3.h"

Factory02::Factory02()
{
}

Factory02::~Factory02()
{
}
 
void * Factory02::create(std::string name)
{
  if(name == "IKeyValue"){
    return new KeyValue();
  } else if(name == "IPriorityQueue1"){
    return new PriorityQueue1();
  } else if(name == "IPriorityQueue2"){
    return new PriorityQueue1();
  } else if(name == "IPriorityQueue3"){
    return new PriorityQueue3();
  } else if(name == "IPriorityQueue4"){
    return new PriorityQueue3();
  } else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory02();  
}

}
