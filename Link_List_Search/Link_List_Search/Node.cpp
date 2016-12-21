#include "stdafx.h"
#include "Node.h"

Node::Node(DATATYPE new_item, Node *new_next)
{
	data = new_item;
	next = new_next;
}

DATATYPE Node::get_data()
{
	return data;
}

Node * Node::get_next()
{
	return next;
}
