#include "Factory00.h"
#include "StringEcho.h"
#include "StringReverse.h"

Factory00::Factory00()
{
}

Factory00::~Factory00()
{
}
 
void * Factory00::create(std::string name)
{
  if(name == "IStringEcho"){
    return new StringEcho();
  } else if(name == "IStringReverse"){
    return new StringReverse();
  } else {
    return NULL;
  }
}

extern "C" {

ObjectFactory * createObjectFactory(){
  return new Factory00();  
}

}
