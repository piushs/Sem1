#include "VectorString.h"
#include <iostream>

void VectorString :: push_back (std :: string item)
{
	set(vssize,item);
	vssize++;
}

void VectorString :: pop_back()
{
	vssize--;
}

std :: string VectorString :: get (int index)
{
	return value[index];
}

void VectorString :: set (int index, std :: string item)
{
	value[index]=item;
}

size_t VectorString :: size()
{
	return vssize;
}

