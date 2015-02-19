#include "SingleList.h"
#include "SingleNode.h"
#include <iostream>
#include <stack>

void SingleList::addHead (int value)
{
	if (firsttime == 0)
	{
		head = new SingleNode();
		head->m_next=NULL;
	    head->m_value = value;
		firsttime =1;
	}
	else
	{
		node = new SingleNode();
		node->m_value=value;
		node->m_next=head;
		head=node;
	}

};

SingleNode * SingleList :: getHead()
{
	return head;
}

void SingleList::setHead(ISingleNode * head)
{
	 head=node;
}
   
void SingleList::orderSort2()
{
	SingleNode *stack[2];
    SingleNode *temp_ptr=new SingleNode();
	SingleNode *prev_stack =new SingleNode();
	SingleNode *temp_head=new SingleNode();

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
			}
		    if (prev_stack != NULL)
			{
				prev_stack->m_next=stack[count-1];
			}
			else
			{
				temp_head=stack[1];
			}
			prev_stack=stack[0];
			count=0;
		}
	}
	for (int i=count-1; i>0;i--)
	{
		stack[i]->m_next=stack[i-1];
	}		    
	if (prev_stack != NULL)
	{
		prev_stack->m_next=stack[count-1];
	}
	else
	{
		temp_head=stack[1];
	}
	prev_stack=stack[0];
	head=temp_head;
}

void SingleList::orderSort3()
{
	SingleNode *stack[3];
    SingleNode *temp_ptr=new SingleNode();
	SingleNode *prev_stack =new SingleNode();
	SingleNode *temp_head=new SingleNode();

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
			}
		    if (prev_stack != NULL)
			{
				prev_stack->m_next=stack[count-1];
			}
			else
			{
				temp_head=stack[2];
			}
			prev_stack=stack[0];
			count=0;
		}
	}
	for (int i=count-1; i>0;i--)
	{
		stack[i]->m_next=stack[i-1];
	}		    
	if (prev_stack != NULL)
	{
		prev_stack->m_next=stack[count-1];
	}
	else
	{
		temp_head=stack[count-1];
	}
	prev_stack=stack[0];
	head=temp_head;
}

void SingleList::sequenceOrderSort()
{   
	int step_size=2;
	SingleNode *temp_ptr=new SingleNode();
	temp_ptr=head;
	SingleNode *temp=new SingleNode ();
	SingleNode *next=new SingleNode ();
	SingleNode *prev=new SingleNode();
	SingleNode *top =new SingleNode();
	
	int seq=0;
	prev=NULL;
	SingleNode** stk;
	stk=(SingleNode**) malloc ((step_size)*sizeof(SingleNode*));
	int stack_size=0;
	SingleNode *start = new SingleNode();
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
			          temp->m_next = next;
			      }
		     }
		     if (prev != NULL)
		     {
			    prev->m_next=top;
		     }
			 free(stk);
		     prev=temp;
		     step_size++;
			 stk=(SingleNode**) malloc ((step_size)*sizeof(SingleNode*));
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
		      temp->m_next = next;
		 }
     
         if (prev != NULL)
         {
	          prev->m_next=top;
	     }
    }
	head=start;
}

void SingleList::reverse()
{
	SingleNode *stack[20];
    SingleNode *temp_ptr=new SingleNode();
	SingleNode *prev_stack =new SingleNode();
	SingleNode *temp_head=new SingleNode();

	temp_ptr=head;
	int count=0;
	prev_stack=NULL;

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
			}
		    if (prev_stack != NULL)
			{
				stack[0]->m_next=prev_stack;
			}
			prev_stack=stack[count-1];
			count=0;
		}
	}
	for (int i=count-1; i>0;i--)
	{
		stack[i]->m_next=stack[i-1];
	}		    
	if (prev_stack != NULL)
	{
		stack[0]->m_next=prev_stack;
	}
	head=stack[count-1];
	std::cout << "";
}
