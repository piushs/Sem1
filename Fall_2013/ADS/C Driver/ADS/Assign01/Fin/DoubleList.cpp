#include "Interfaces01.h"

#include "DoubleList.h"
#include "DoubleNode.h"
#include <iostream>

DoubleList :: DoubleList ()
{
      firsttime =0;
	 
	  for (int i=0 ; i< ADDR_SIZE; i++)
	  {
		  addr[i]=NULL;
	  }
}

IDoubleNode * DoubleList :: getHead()
{
	return(head);
}

IDoubleNode *DoubleList :: getTail()
{
	return(tail);
}

void DoubleList::setHead(IDoubleNode * node)
{
	head=(DoubleNode *) node;
}

void DoubleList::setTail (IDoubleNode *node)
{
	tail=(DoubleNode *) node;
}

void DoubleList :: addSorted (int value)
{
	if (firsttime == 0)
	{
		head = new DoubleNode();
		head->setNext(NULL);
		head->setPrev(NULL);
	    head->setValue(value);
		tail=head;
		firsttime =1;
	}
	else
	{
		node = new DoubleNode();
		DoubleNode *temp_ptr = new DoubleNode ();
		DoubleNode *temp=new DoubleNode ();
		node->setValue(value);
		
		int div=value/10;

		if (addr[div] == NULL)
		{
		   addr[div]=node;
		   div--;
		   while (addr[div] == NULL && div >=0)
		   {
			   div--;
		   }
		   if (div >= 0)
			   temp_ptr=addr[div];
		   else
			   temp_ptr=head;
		}
		else
		{
		   if (addr[div]->getValue() < value)
			   temp_ptr=addr[div];
		   else
		   {
			   div--;
		       while (addr[div] == NULL && div >=0)
		       {
			      div--;
		       }
		       if (div >= 0)
			       temp_ptr=addr[div];
		       else
			       temp_ptr=head;
		   }
		}
		
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
				   DoubleList :: setHead(node);
			   }
			   else
			   {
				   temp->m_next=node;
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
				   DoubleList :: setTail(node);
				   break;
			   }
			   temp_ptr=temp_ptr->m_next;
			}
		}
	}
}

void DoubleList :: orderSort2()
{
	DoubleNode *stack[2];
    DoubleNode *temp_ptr=new DoubleNode();
	DoubleNode *prev_stack =new DoubleNode();
	DoubleNode *temp_head=new DoubleNode();

	temp_ptr=head;
	int count=0;
	prev_stack=NULL;

	while (temp_ptr != NULL)
	{
		if (count < 2)
		{
			stack[count++]=temp_ptr;
			temp_ptr=temp_ptr->m_next;
		}
		else
		{
			for (int i=count-1; i>0;i--)
			{
				stack[i]->m_next=stack[i-1];
				stack[i-1]->m_prev=stack[i];
			}
		    if (prev_stack != NULL)
			{
				prev_stack->m_next=stack[count-1];
				stack[count-1]->m_prev=prev_stack;
			}
			else
			{
				stack[1]->m_prev=NULL;
				temp_head=stack[1];
			}
			prev_stack=stack[0];
			count=0;
		}
	}
	for (int i=count-1; i>0;i--)
	{
		stack[i]->m_next=stack[i-1];
		stack[i-1]->m_prev=stack[i];
	}		    
	if (prev_stack != NULL)
	{
		prev_stack->m_next=stack[count-1];
		stack[count-1]->m_prev=prev_stack;
	}
	else
	{
		temp_head=stack[1];
	}
	DoubleList::setHead(temp_head);
	stack[0]->m_next=NULL;
	DoubleList::setTail(stack[0]);
}

void DoubleList::orderSort3()
{
	DoubleNode *stack[3];
    DoubleNode *temp_ptr=new DoubleNode();
	DoubleNode *prev_stack =new DoubleNode();
	DoubleNode *temp_head=new DoubleNode();

	temp_ptr=head;
	int count=0;
	prev_stack=NULL;

	while (temp_ptr != NULL)
	{
		if (count < 3)
		{
			stack[count++]=temp_ptr;
			temp_ptr=temp_ptr->m_next;
		}
		else
		{
			for (int i=count-1; i>0;i--)
			{
				stack[i]->m_next=stack[i-1];
				stack[i-1]->m_prev=stack[i];
			}
		    if (prev_stack != NULL)
			{
				prev_stack->m_next=stack[count-1];
				stack[count-1]->m_prev=prev_stack;
			}
			else
			{
				stack[2]->m_prev=NULL;
				temp_head=stack[2];
			}
			prev_stack=stack[0];
			count=0;
		}
	}
	for (int i=count-1; i>0;i--)
	{
		stack[i]->m_next=stack[i-1];
		stack[i-1]->m_prev=stack[i];
	}		    
	if (prev_stack != NULL)
	{
		prev_stack->m_next=stack[count-1];
		stack[count-1]->m_prev=prev_stack;
	}
	else
	{
		temp_head=stack[2];
	}
	setHead(temp_head);
	stack[0]->m_next=NULL;
	setTail(stack[0]);
}

void DoubleList :: sequenceOrderSort()
{
	int step_size=2;
	DoubleNode *temp_ptr=new DoubleNode();
	temp_ptr=head;
	DoubleNode *temp=new DoubleNode ();
	DoubleNode *next=new DoubleNode ();
	DoubleNode *prev=new DoubleNode();
	DoubleNode *top =new DoubleNode();
	
	int seq=0;
	prev=NULL;
	DoubleNode** stk;
	stk=(DoubleNode**) malloc ((step_size)*sizeof(DoubleNode*));
	int stack_size=0;
	DoubleNode *start = new DoubleNode();
	while (temp_ptr != NULL)
	{
		stk[stack_size++]=temp_ptr;
		if (stack_size == step_size)
		{
			 temp_ptr=temp_ptr->m_next;
			 stack_size--;
			 if (seq == 0)
			 {
				 start = stk[stack_size];
				 seq=1;
			 }
		     int flag=0;
			
		     while (stack_size >= 0)
		     {
			      if (flag==0)
			      {
				     top=stk[stack_size];
				     flag=1;
			      }
			      temp=stk[stack_size];
			      stack_size --;
			      if (stack_size>=0)
			      {
			          next=stk[stack_size];
			          temp->m_next=next;
					  next->m_prev=temp;
			      }
		     }
		     if (prev != NULL)
		     {
			    prev->m_next=top;
				top->m_prev=prev;
		     }
			 free(stk);
		     prev=temp;
		     step_size++;
			 stk=(DoubleNode**) malloc ((step_size)*sizeof(DoubleNode*));
			 stack_size=0;
		}
		else
		{
		     temp_ptr=temp_ptr->m_next;
		}
	}

	int flag=0;
	stack_size --;
	while (stack_size >= 0)
    {
	     if (flag==0)
	     {
		     top=stk[stack_size];				     
			 flag=1;
	     }
		 temp=stk[stack_size];
	     stack_size--;
	     if (stack_size >=0)
	     {
		      next=stk[stack_size];
		      temp->m_next=next;
			  next->m_prev=temp;
		 }
     
         if (prev != NULL)
         {
	          prev->m_next=top;
			  top->m_prev=prev;
	     }
    }
	start->setPrev(NULL);
	temp->setNext(NULL);
	DoubleList::setHead(start);
	DoubleList::setTail(temp);
}
 
void DoubleList ::reverse()
{
	DoubleNode *stack[20];
    DoubleNode *temp_ptr=new DoubleNode();
	DoubleNode *prev_stack =new DoubleNode();
	DoubleNode *temp_head=new DoubleNode();

	temp_ptr=head;
	int count=0;
	prev_stack=NULL;
	DoubleNode *end=new DoubleNode ();
	end=head;
	while (temp_ptr != NULL)
	{
		if (count < 20)
		{
			stack[count++]=temp_ptr;
			temp_ptr=temp_ptr->m_next;
		}
		else
		{
			for (int i=count-1; i>0;i--)
			{
				stack[i]->m_next=stack[i-1];
				stack[i-1]->m_prev=stack[i];
			}
		    if (prev_stack != NULL)
			{
				stack[0]->m_next=prev_stack;
				prev_stack->m_prev=stack[0];
			}
			prev_stack=stack[count-1];
			count=0;
		}
	}
	for (int i=count-1; i>0;i--)
	{
		stack[i]->m_next=stack[i-1];
		stack[i-1]->m_prev=stack[i];
	}		    
	if (prev_stack != NULL)
	{
		stack[0]->m_next=prev_stack;
		prev_stack->m_prev=stack[0];
	}
	DoubleList::setHead(stack[count-1]);
	head->setPrev(NULL);
	DoubleList::setTail(end);
	tail->setNext(NULL);
}