#include "Interfaces01.h"
#include "DoubleNode.h"

#define ADDR_SIZE 10000

class DoubleList : public IDoubleList
{

public:
  int firsttime;
  DoubleNode *head, *tail,*node;
  DoubleNode *addr[ADDR_SIZE];
  DoubleList();
  ~DoubleList(){}
  IDoubleNode * getHead();
  IDoubleNode * getTail();
  void setHead(IDoubleNode * head);
  void setTail(IDoubleNode * tail);
  void addSorted(int value);
  void orderSort2();
  void orderSort3();
  void sequenceOrderSort();
  void reverse();
};
