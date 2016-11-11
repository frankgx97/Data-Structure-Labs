#pragma once
#include <iostream>
using namespace std;

#define DATATYPE int
#define elif else if

class QueueNode
{
public:
	QueueNode(DATATYPE,QueueNode *);
	void set_next(QueueNode *);
	QueueNode * get_next();
	int get_data();

	QueueNode *next;
private:
	DATATYPE data;
};