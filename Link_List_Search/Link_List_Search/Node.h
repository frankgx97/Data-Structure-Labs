#pragma once
#include <iostream>
using namespace std;

#define DATATYPE int
class Node
{
public:
	Node(DATATYPE, Node *);
	DATATYPE get_data();
	Node * get_next();
	DATATYPE data;
	Node *next;
};

