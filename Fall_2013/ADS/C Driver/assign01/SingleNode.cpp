#include "SingleNode.h"
#include <iostream>

void SingleNode::setValue (int value)
{
	std::cout << "Hello";

};

int SingleNode::getValue ()
{
	return m_value;
};

SingleNode *  SingleNode :: getNext ()
{
	return m_next;
};

void SingleNode :: setNext (ISingleNode *next)
{
    std::cout << "Hello";	
};