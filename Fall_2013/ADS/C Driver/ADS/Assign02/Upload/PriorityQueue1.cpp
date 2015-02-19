#include "PriorityQueue1.h"
#include "VectorKeyValue.h"
#include "KeyValue.h"
#include "VectorString.h"
#include <iostream>

void PriorityQueue1 :: merge (IPriorityQueue * input_queue)
{
	std :: cout << "";
}

void PriorityQueue1 :: enqueue (IKeyValue  * key_value)
{
	int found=0;
	KeyValue *temp_ptr;
	
	KeyValue *node = new KeyValue();
	KeyValue *prev = new KeyValue();
		
	temp_ptr=(KeyValue*) key_value;
	node->key=temp_ptr->getKey();
	node->value=temp_ptr->getValue();
	prev=head;	
	if (firsttime == 0)
	{
		node->nextelement=NULL;
		node->prevelement=NULL;
		
		head=node;

		firsttime=1;
		sort->push_back(node);
		track->push_back(key_value->getValue());
		queue_size ++;
	}
	else
	{
		sort->push_back(node);
		temp_ptr=head;
		while (temp_ptr != NULL)
		{
			if (temp_ptr->getKey() == key_value->getKey())
			{
				found=1;
				if (temp_ptr == head)
				{
					track->push_back(key_value->getValue());
				}
				break;
			}
			if (temp_ptr->getKey() > key_value->getKey())
			{
				break;
			}
			prev=temp_ptr;
			temp_ptr=temp_ptr->nextelement;
		}
		if (found == 0)
		{
			if (temp_ptr != NULL)
			{
				if (temp_ptr != head)
				{
					node->nextelement=prev->nextelement;
					prev->nextelement=node;
					node->prevelement=prev;
				}
				else
				{
					node->nextelement=prev;
					node->prevelement=NULL;
					prev->prevelement=node;
					head=node;
					delete [] track;
					track->vssize=0;
					track=new VectorString();
					track->push_back(key_value->getValue());
				}
			}
			else
			{
				node->nextelement=prev->nextelement;
				prev->nextelement=node;
				node->prevelement=prev;
			}
			queue_size ++;
		}
	}
}


IVectorKeyValue * PriorityQueue1 :: returnSorted()
{
	return sort;
}

int  PriorityQueue1 :: lowestKey ()
{
	return head->getKey();
}

IVectorString * PriorityQueue1 :: lowestValues()
{
	return(track);
}

void PriorityQueue1 :: dequeue ()
{
	head=head->nextelement;
	delete track;
	track=new VectorString();
    int tempvar=0;
	int i=0;
	track->vssize=0;
	KeyValue *temp=new KeyValue();
	temp=sort->vkvalue;
	while (temp != NULL && temp->getKey() == start)
	{
		i++;
		temp=temp->nextelement;
	}
	if (temp != NULL)
	{
		start=temp->getKey();
		tempvar=i;
		KeyValue *temp1 = new KeyValue();
		temp1=temp;
		while (temp1 != NULL && temp1->getKey() == start)
		{
			track->push_back(temp1->getValue());
			temp1=temp1->nextelement;
			i++;
		}
	}	
	queue_size--;
	
	sort->vkvalue=temp;
	
	for (int j=0; j< tempvar ;j++)
		sort->pop_back();
}

size_t PriorityQueue1 :: size ()
{
	return queue_size;
}