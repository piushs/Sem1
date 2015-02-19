#include "Factory03.h"
Factory03::Factory03()
{
}

Factory03::~Factory03()
{
}
 
void * Factory03::create(std::string name)
{
  if(name == "IVectorDoubleSort1"){
    return NULL;
  } else if(name == "IVectorDoubleSort2"){
    return NULL;
  } else if(name == "ISmoothSort"){
    return NULL;
  } else if(name == "ILinkedListSort"){
    return NULL;
  } else if(name == "IRunningMedian"){
    return NULL;
  } else if(name == "IRecordsSearch"){
    return NULL;
  } else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory03();  
}

}
