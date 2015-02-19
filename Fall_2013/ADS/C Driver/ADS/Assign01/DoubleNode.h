#pragma once

#include "Interfaces01.h"

class DoubleNode : public IDoubleNode
{

public :
  int m_value;
  DoubleNode *m_next;
  DoubleNode *m_prev;
  int firsttime;

  DoubleNode() 
  {
	  firsttime =0;
  }
  ~DoubleNode() {}
  void setValue(int value);
  int getValue();
  DoubleNode * getPrev();
  DoubleNode * getNext();
  void setPrev(IDoubleNode * prev);
  void setNext(IDoubleNode * next);
};


