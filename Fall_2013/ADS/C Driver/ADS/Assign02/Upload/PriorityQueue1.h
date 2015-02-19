#pragma once

#include "Interfaces02.h"
#include "KeyValue.h"
#include "VectorKeyValue.h"
#include "VectorString.h"


class PriorityQueue1 : public IPriorityQueue
{

public :
	KeyValue *head,*tail;
	size_t queue_size;
	VectorString *track;
	int firsttime,start,end;
	VectorKeyValue *sort;
	PriorityQueue1() 
	{ 
		queue_size =0; 
		head=NULL;
		start=0;
		firsttime=0;
		sort=new VectorKeyValue();
		track=new VectorString();
	};
    ~PriorityQueue1() {};

	void enqueue(IKeyValue * key_value);
	void merge(IPriorityQueue * input_queue);
    IVectorKeyValue* returnSorted();
	int lowestKey();
	IVectorString * lowestValues();
    void dequeue();
	size_t size();
};