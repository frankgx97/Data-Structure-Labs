#pragma once
#include <iostream>
using namespace std;

#define DATATYPE int
class StackNode
{
public:
	StackNode(DATATYPE,StackNode *);
	DATATYPE get_data();
	StackNode * get_next();
private:
	DATATYPE data;
	StackNode *next;
};

