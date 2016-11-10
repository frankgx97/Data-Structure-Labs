#include "stdafx.h"
#include "SeqStack.h"

SeqStack::SeqStack(void)
{
	top = -1;
}

int SeqStack::push(DATATYPE new_item)
{
	if (top == max_size)
	{
		cout << "stack full." << endl;
		return false;
	}
	data[top + 1] = new_item;
	top++;
	return true;
}

int SeqStack::pop()
{
	if (SeqStack::is_empty())
	{
		cout << "stack empty." << endl;
		return false;
	}
	top--;
	return true;
}

DATATYPE SeqStack::get_top()
{
	return data[top];
}

int SeqStack::is_empty()
{
	if (top == -1)
		return true;
	else
		return false;
}