#pragma once

#include "Interfaces02.h"
#include "KeyValue.h"
#include "VectorKeyValue.h"
#include "VectorString.h"


class PriorityQueue3 : public IPriorityQueue
{

public :

	Node *stk[500000];
	PriorityQueue3 *temp;
	int count;

	int stack_size;
	VectorString *strvalue;
	int queue_size;
	int pos;
	PriorityQueue3() 
	{ 
		stack_size=0;
		queue_size=0;
		strvalue=new VectorString();
		count=0;
	};
    ~PriorityQueue3() {};

	void enqueue(IKeyValue * key_value);
	void merge(IPriorityQueue * input_queue);
    IVectorKeyValue* returnSorted();
	int lowestKey();
	IVectorString * lowestValues();
    void dequeue();
	size_t size();
	void sort();
};