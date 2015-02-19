#include "SingleNode.h"
#include <iostream>

void SingleNode::setValue (int value)
{
	m_value=value;
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
    m_next=(SingleNode*)next;	
};