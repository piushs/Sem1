#include "PriorityQueue3.h"
#include "VectorKeyValue.h"
#include "KeyValue.h"
#include "VectorString.h"
#include <iostream>

void PriorityQueue3::sort ()
{
	for (int i=0;i<stack_size-1;i++)
	{
		for (int j=i+1;j<stack_size;j++)
		{
			if (stk[i]->linkno < stk[j]->linkno)
			{
				Node *temp=new Node ();
				temp=stk[i];
				stk[i]=stk[j];
				stk[j]=temp;
			}
			else if (stk[i]->linkno == stk[j]->linkno)
			{
				if (stk[i]->key < stk[j]->key)
				{
					Node *temp=new Node ();
					temp=stk[i];
					stk[i]=stk[j];
					stk[j]=temp;
				}
			}

		}
	}
}

void PriorityQueue3 :: merge (IPriorityQueue * input_queue)
{
	PriorityQueue3 *temp_ptr=new PriorityQueue3();
	temp_ptr=(PriorityQueue3*) input_queue;

	for (int k=0; k<temp_ptr->stack_size; k++)
	{
		stk[stack_size++]=temp_ptr->stk[k];
	}

	sort();

	Node *save[20];
	int save_size=0;
	int i=stack_size-1;
	while ( i>=0 )
	{
		if (stk[i]->linkno==stk[i-1]->linkno)
		{
			stk[i]->link[stk[i]->linkno++]=stk[i-1];
			save[save_size++]=stk[i];
			i=i-2;
		}
		else
		{
			save[save_size++]=stk[i];
			i--;
		}
	}
	stack_size=0;
	for (int j=save_size-1;j>=0;j--)
	{
		stk[stack_size++]=save[j];
	}
	queue_size=queue_size+temp_ptr->queue_size;
}

void PriorityQueue3 :: enqueue (IKeyValue  * key_value)
{
	Node *node = new Node();
	Node *temp = new Node();
	node->key=key_value->getKey();
	node->value=key_value->getValue();

	node->linkno=0;
	
	
	int flag=0;
	for (int i=stack_size-1; i>=0; i--)
	{
	    if(stk[i]->linkno == node->linkno)
		{
			flag=1;
			temp = stk[i];

			if (temp->key > node->key)
			{ 
				node->link[node->linkno++]=temp;
				stk[i]=node;
			}
			else
			{
				temp->link[temp->linkno++]=node;
				stk[i]=temp;
			}
			node=stk[i];
			stack_size--;
		}
		else
		{
			break;
		}
	}

	if (flag == 0)
	{
		stk[stack_size]=node;
		stack_size++;
	}
	else 
		stack_size++;
	queue_size++;
}


IVectorKeyValue * PriorityQueue3 :: returnSorted()
{
	return NULL;
}

int  PriorityQueue3 :: lowestKey ()
{
	int min = stk[stack_size-1]->key;
	strvalue->vssize=0;
	int k;
	for (int i=stack_size -1; i>=0; i--)
	{
		if (min >= stk[i]->key)
		{
			min =stk[i]->key;
			pos=i;
			k=i;
		}
	}
	strvalue->push_back(stk[k]->value);
	return min;
}

IVectorString * PriorityQueue3 :: lowestValues()
{
	return(strvalue);
}

void PriorityQueue3 :: dequeue ()
{
   int min=lowestKey();

   Node *temp_ptr[50000];
   int size=0;
   int i;
   for (i=0;i<pos;i++)
   {
	   temp_ptr[size++]=stk[i];
   }

   if (i == pos)
   {
       int j=stk[i]->linkno;
	   for (int k=0; k<j ; k++)
	   {
		   temp_ptr[size++]=stk[i]->link[k];
	   }
   }

   for (int i=pos+1; i<stack_size;i++)
   {
	   temp_ptr[size++]=stk[i];
   }

   stack_size=0;
   for (int i=0; i<size;i++)
   {
	   stk[stack_size++]=temp_ptr[i];
   }
   queue_size--;
}

size_t PriorityQueue3 :: size ()
{
	return queue_size;
}