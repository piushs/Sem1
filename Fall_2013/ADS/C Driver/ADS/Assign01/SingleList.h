#pragma once 

#include "Interfaces01.h"
#include "SingleNode.h"
class SingleList : public ISingleList
{
	
public:
	int firsttime;
	int addr_ind;
	SingleList()
	{ 
		firsttime=0;
	    addr_ind=0;
	}
	~SingleList() {}
    SingleNode *node,*head;
    SingleNode * getHead();
    void setHead(ISingleNode * head);
    void addHead(int value);
    void orderSort2();
    void orderSort3();
    void sequenceOrderSort();
    void reverse();
};