#include "stdafx.h"
#include "LinkStack.h"


LinkStack::LinkStack(void)
{
	top = NULL;
}

int LinkStack::push(DATATYPE new_item)
{
	if (LinkStack::is_empty())
		top = new StackNode(new_item,NULL);
	else
		top = new StackNode(new_item,top);
	return true;
}

DATATYPE LinkStack::pop()
{
	StackNode * node_for_del;
	DATATYPE data_for_return;
	if (LinkStack::is_empty())
		return NULL;
	data_for_return = top -> get_data();
	node_for_del = top;
	top = top -> get_next();
	delete node_for_del;
	return data_for_return;
}

DATATYPE LinkStack::get_top()
{
	if (LinkStack::is_empty())
		return NULL;
	return top -> get_data();
}

int LinkStack::is_empty()
{
	if (top == NULL)
		return true;
	else
		return false;
}