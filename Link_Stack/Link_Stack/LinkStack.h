#pragma once
#include "StackNode.h"
class LinkStack
{
public:
	LinkStack(void);
	int push(DATATYPE);
	int pop();
	DATATYPE get_top();
	int is_empty();
	void ls();
private:
	StackNode *top;
};

