#pragma once
#include "Node.h"
class List
{
public:
	List(void);
	int push(DATATYPE);
	DATATYPE search(DATATYPE);
	int pop();
	int is_empty();
	void ls();
private:
	Node *head;
	Node *current;
};

