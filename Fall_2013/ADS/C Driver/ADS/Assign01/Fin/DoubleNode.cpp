#include "DoubleNode.h"
#include <iostream>

void DoubleNode :: setValue(int value)
{
	m_value=value;
}
  
int DoubleNode :: getValue()
{
    return (m_value);
}

DoubleNode * DoubleNode :: getPrev()
{
	return(m_prev);
}


DoubleNode * DoubleNode :: getNext()
{
    return(m_next);
}

void DoubleNode :: setPrev(IDoubleNode * prev)
{
	m_prev=(DoubleNode*) prev;
}
 
void DoubleNode :: setNext(IDoubleNode * next)
{
	m_next=(DoubleNode *)next;
}