#pragma once

#include "Interfaces01.h"

class SingleNode : public ISingleNode
{

	public:
	SingleNode(){}
	~SingleNode(){}
	SingleNode * m_next;
    int m_value;
	void setValue (int value);
	int getValue ();
	SingleNode *getNext();
	void setNext(ISingleNode * next);
};