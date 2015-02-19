#include "Interfaces01.h"
#include "DoubleNode.h"

class DoubleList : public IDoubleList
{

public:
  int firsttime;
  DoubleNode *head, *tail,*node;
  DoubleList() 
  {
	  firsttime =0;
  }
  ~DoubleList() {}
  IDoubleNode * getHead();
  IDoubleNode * getTail();
  void setHead(DoubleNode * head);
  void setTail(DoubleNode * tail);
  void addSorted(int value);
  void orderSort2();
  void orderSort3();
  void sequenceOrderSort();
  void reverse();
};
