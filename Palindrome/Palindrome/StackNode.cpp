#include "stdafx.h"
#include "StackNode.h"


StackNode::StackNode(DATATYPE new_item,StackNode *new_next)
{
	data = new_item;
	next = new_next;
}

DATATYPE StackNode::get_data()
{
	return data;
}

StackNode * StackNode::get_next()
{
	return next;
}
