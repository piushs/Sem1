#include "Interfaces01.h"

#include "DoubleList.h"
#include "DoubleNode.h"
#include <iostream>

IDoubleNode * DoubleList :: getHead()
{
	std :: cout << "";
	return(head);
}

IDoubleNode *DoubleList :: getTail()
{
	std :: cout << "";
	return(tail);
}

void setHead(DoubleNode * head)
{
	std :: cout << "";
}

void setTail (DoubleNode *tail)
{
	std :: cout << "";
}

void DoubleList :: addSorted (int value)
{
	if (firsttime == 0)
	{
		head = new DoubleNode();
		head->m_next=NULL;
		head->m_prev=NULL;
	    head->m_value = value;
		tail=head;
		firsttime =1;
	}
	else
	{
		node = new DoubleNode();
		DoubleNode *temp_ptr = new DoubleNode ();
		DoubleNode *temp=new DoubleNode ();
		node->m_value=value;
		temp_ptr=head;
		while (temp_ptr!=NULL)
		{
		    if ( value < temp_ptr->m_value )
		    {   
			   temp=temp_ptr->m_prev;
		       node->m_next=temp_ptr;
			   temp_ptr->m_prev=node;
		       node->m_prev=temp;
			   if (temp_ptr == head )
			   {
				   head=node;
			   }
			   break;
		    }
		    else
		    {
			   if (temp_ptr->m_next==NULL)
		       {
			       temp=temp_ptr->m_next;
				   temp_ptr->m_next=node;
				   node->m_prev=temp_ptr;
				   node->m_next=temp;
				   tail=node;
			   }
			   temp_ptr=temp_ptr->m_next;
			}
		}
	}
}

void ordersort2()
{
	std :: cout << "";
}

void orderSort3()
{
	std :: cout << "";
}

void sequenceOrderSort()
{
	std :: cout << "";
}
 
void reverse()
{
	std :: cout << "";
}