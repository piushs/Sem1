#include "AbstractGrader.h"
#include "ObjectFactory.h"
#ifdef linux
#include <dlfcn.h>
#endif

AbstractGrader::AbstractGrader()
  : m_dllHandle(NULL)
{
}

AbstractGrader::~AbstractGrader()
{
}

void AbstractGrader::setDllHandle(void * dll_handle){
  m_dllHandle = dll_handle;
}

TestCase * AbstractGrader::nullObject(std::string iface)
{
  TestCase * ret = new TestCase();
  ret->passed = false;
  ret->error_message = std::string("null object returned for interface: ")+iface;
  ret->time = 0;
  return ret;
}

TestCase * AbstractGrader::failed(std::string error_message)
{
  TestCase * ret = new TestCase();
  ret->passed = false;
  ret->error_message = error_message;
  ret->time = 0;
  return ret;
}

void * AbstractGrader::createObject(std::string name){
#ifdef GRADE_SERVER
  void *(*fptr)() = (void *(*)()) dlsym(m_dllHandle, "createObjectFactory");
#else
  void *(*fptr)() = (void *(*)()) &createObjectFactory;
#endif
    
  void * ret = (*fptr)();
  ObjectFactory * fact = (ObjectFactory *) ret;
  return fact->create(name);
}
