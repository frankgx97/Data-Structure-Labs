#include "stdafx.h"
#include "LinkQueue.h"

LinkQueue::LinkQueue()
{
	head = NULL;
	rear = NULL;
	nodes = 0;
}

void LinkQueue::ls()
{
	QueueNode * current = head;
	if (!nodes)
	{
		cout << "Пе" << endl;
		return;
	}
	for (int i=1;i<=nodes;i++)
	{
		cout << current -> get_data() << endl;
		current = current -> next;
	}
	return;
}

int LinkQueue::in(DATATYPE new_item)
{
	QueueNode * rear_temp;
	if (!nodes)
	{
		head = new QueueNode(new_item,NULL);
		nodes++;
	}
	elif (nodes == 1)
	{
		rear = new QueueNode(new_item,head);
		rear -> next -> next = rear;
		nodes++;
	}
	else
	{
		rear -> next = new QueueNode(new_item,rear -> next);
		rear = rear -> next;
		nodes++;
	}
	return true;
}
void LinkQueue::empty()
{
	while (nodes)
		LinkQueue::out();
}

DATATYPE LinkQueue::out()
{
	QueueNode * node_for_del;
	if (!nodes)
	{
		cout << "Пе" << endl;
		return false;
	}
	elif (nodes == 1)
	{
		delete rear;
		rear = NULL;
		nodes--;
	}
	else
	{
		node_for_del = rear -> next;
		rear -> next = rear -> next -> next;
		nodes--;
	}
	return 1;
}


