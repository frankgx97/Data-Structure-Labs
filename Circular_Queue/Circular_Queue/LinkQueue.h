#pragma once
#include "QueueNode.h"
class LinkQueue
{
public:
	LinkQueue();
	int in(DATATYPE);
	DATATYPE out();
	void ls();
	int nodes;
	void empty();
	QueueNode *head;
private:
	
	QueueNode *rear;
};

