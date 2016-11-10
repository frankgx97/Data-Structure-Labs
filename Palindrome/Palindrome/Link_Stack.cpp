#include "stdafx.h"
#include "Link_Stack.h"


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

int LinkStack::pop()
{
	StackNode * node_for_del;
	if (LinkStack::is_empty())
	{
		cout << "stack empty." << endl;
		return false;
	}
	node_for_del = top;
	top = top -> get_next();
	delete node_for_del;
	return true;
}

DATATYPE LinkStack::get_top()
{
	if (LinkStack::is_empty())
	{
		cout << "stack empty." << endl;
		return false;
	}
	return top -> get_data();
}

int LinkStack::is_empty()
{
	if (top == NULL)
		return true;
	else
		return false;
}