#include "LinkedListSort.h"

LinkedListNode *min (LinkedListNode *head_one, LinkedListNode *head_two)
{
	if (head_one->key > head_two->key)
		return(head_two);
	else
		return(head_one);
}

LinkedListNode *max (LinkedListNode *head_one, LinkedListNode *head_two)
{
	if (head_one->key < head_two->key)
		return(head_two);
	else
		return(head_one);
}

LinkedListNode *merge(LinkedListNode *head_one, LinkedListNode *head_two)
{

	LinkedListNode *head_three = new LinkedListNode();

	if (head_one == NULL)
		return(head_two);
	else if (head_two == NULL)
		return(head_one);
	
	/*
	if (head_one->key < head_two->key)
	{
		head_three = head_one;
		head_three->next = merge (head_one->next, head_two);
	}
	else
	{
		head_three = head_two;
		head_three->next = merge(head_one, head_two->next);
	} */

	LinkedListNode *min_ptr = new LinkedListNode();
	LinkedListNode *max_ptr = new LinkedListNode();
	LinkedListNode *prev = new LinkedListNode();
	LinkedListNode *temp = new LinkedListNode();
	LinkedListNode *first = new LinkedListNode();
	
	min_ptr = min (head_one, head_two);
	max_ptr = max (head_one, head_two);
	prev = NULL;
	head_three = min_ptr;
	while(1)
	{
		 while (min_ptr->key < max_ptr->key)
		 {
			 prev = min_ptr;
			 min_ptr = min_ptr->next;

			 if (min_ptr == NULL)
				 break;
		 }
		 
		 if (min_ptr == NULL)
			 break;

		 temp = max_ptr->next;
		 prev->next = max_ptr;
		 max_ptr->next = min_ptr;

		
		 if (temp != NULL)
		 {
			max_ptr = max(temp,min_ptr);
			min_ptr = min (temp,min_ptr);
		 }
	}

	prev->next=max_ptr;
	
	return(head_three);
}

void quicksort (LinkedListNode *a[200000], int first, int last)
{
	int i=first, j=last;
	LinkedListNode *tmp;
	LinkedListNode * pivot = a[abs((first + last)/2)];

	while (i<=j)
	{
		while (a[i]->key < pivot->key)
			i++;
		while (a[j]->key > pivot->key)
			j--;
		if (i<=j)
		{
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			i++;
			j--;
		}
	}

	if (first < j)
		quicksort(a,first,j);
	
	if (i < last)
		quicksort(a,i,last);


}


LinkedListNode * LinkedListSort::sort(LinkedListNode * head)
{
	LinkedListNode *head_one;
	LinkedListNode *head_two;

	
	/*
	int i=0;
	LinkedListNode *temp_ptr=new LinkedListNode();
	temp_ptr=head;
	LinkedListNode *temp1_ptr = new LinkedListNode();
	LinkedListNode *a[200000];

	temp_ptr = head;
	for (i=0; temp_ptr != NULL ;i++)
	{
		a[i]=temp_ptr;
		temp_ptr = temp_ptr->next;
	}
	
	while(temp_ptr != NULL)
	{
		temp1_ptr = temp_ptr -> next;
		while (temp1_ptr != NULL)
		{
			if (temp_ptr -> key > temp1_ptr->key)
			{
				LinkedListNode * swap;
				swap = temp1_ptr;
				temp1_ptr =  temp_ptr;
				temp_ptr = swap;
			}
			temp1_ptr = temp1_ptr->next;
		}
		temp_ptr = temp_ptr -> next;
	} 

	for (int j=0 ; j<i; j++)
	{
		for (int k=j+1; k<i; k++)
		{
			if (a[j]->key > a[k]->key)
			{
				LinkedListNode *swap;
				swap = a[j];
				a[j] = a[k];
				a[k] = swap;
			}
		}
	}

	for (int j=0; j <i-1 ;j++)
	{
		a[j]->next=a[j+1];
	}

	a[i-1]->next = NULL;
	*/
	LinkedListNode *a[250000];
	LinkedListNode *temp_ptr=new LinkedListNode();
	temp_ptr=head;
	
	temp_ptr = head;
	int i;
	for (i=0; temp_ptr != NULL ;i++)
	{
		a[i]=temp_ptr;
		temp_ptr = temp_ptr->next;
	}
	quicksort(a,0,i-1);

	for (int j=0; j <i-1 ;j++)
	{
		a[j]->next=a[j+1];
	}

	a[i-1]->next = NULL;
	head=a[0];

	return(head);
	if (head == NULL || head->next == NULL) 
		return(head);
	/*
	head_one = head;
	head_two = head->next;

	while (head_two != NULL && head_two->next !=  NULL)
	{
		head = head->next;
		head_two = head_two->next->next;
	}

	head_two = head->next;
	head->next = NULL;
	
	
	//return merge (sort (head_one), sort(head_two));

	return merge (head_one, head_two); */
}

