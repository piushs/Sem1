#pragma once

#include "Interfaces03.h"

class LinkedListSort : public ILinkedListSort
{
public:
	//LinkedListNode *head_three;
	LinkedListSort(){
	
	};
	~LinkedListSort(){};
	LinkedListNode *sort(LinkedListNode * list);

};