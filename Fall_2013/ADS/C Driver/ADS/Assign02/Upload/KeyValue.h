#pragma once

#include "Interfaces02.h"
#include "VectorString.h"

class  KeyValue : public IKeyValue{

public :
  int key;
  std::string value;
  KeyValue *nextelement, *prevelement;

  KeyValue() {}
  ~KeyValue() {}
  void setKey(int key);
  void setValue(std::string value);
  int getKey();
  std::string getValue();
};

class Node 
{

public:
	Node ()
	{
		linkno=0;
		for (int i=0 ; i < 20;i++)
			link[i]=NULL;
	}
	~Node() {}
	int key;
	std :: string value;
	int linkno;
	Node *link[20];
};