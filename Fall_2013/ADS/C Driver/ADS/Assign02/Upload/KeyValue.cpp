#include "KeyValue.h"
#include <iostream>

void KeyValue :: setKey(int key)
{
	KeyValue :: key=key;
}

void KeyValue ::setValue(std::string value)
{
	KeyValue::value=value;
}
  
int KeyValue :: getKey()
{
	return key;
}
  
std::string KeyValue :: getValue()
{
	return value;
}