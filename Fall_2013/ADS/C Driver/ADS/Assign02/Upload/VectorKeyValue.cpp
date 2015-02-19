#include "VectorKeyValue.h"
#include <iostream>

void VectorKeyValue :: push_back(IKeyValue * item)
{
	KeyValue *node=new KeyValue();
	KeyValue *prev=new KeyValue();
	prev=vkvalue;
	node->value=item->getValue();
	node->key=item->getKey();
	node->nextelement=NULL;
	node->prevelement=NULL;

	KeyValue *temp=new KeyValue();
	temp=vkvalue;
	if (init == 0)
	{
		init=1;
		vkvalue=node;
	}
	else
	{
		temp=vkvalue;
		while (temp != NULL)
		{
			if (temp->getKey() <= node->getKey())
			{
				prev=temp;
				temp=temp->nextelement;
			}
			else
			{
				if (temp != vkvalue || prev->getKey() == node->getKey())
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
					vkvalue=node;
				}
				break;
			}
		}
		if (temp == NULL)
		{
			node->nextelement=prev->nextelement;
			prev->nextelement=node;
			node->prevelement=prev;
		}
	}
	vksize++;
}
 
void VectorKeyValue :: pop_back()
{
	vksize--;
}

IKeyValue * VectorKeyValue :: get(int index)
{
	KeyValue *temp=new KeyValue();
	temp=vkvalue;
	for (int i=0; i < index; i++)
	{
		temp=temp->nextelement;
	}
	return(temp);
}
 
void VectorKeyValue :: set(int index, IKeyValue * item)
{
	std :: cout << "";
}

size_t VectorKeyValue :: size()
{
	return vksize;
}