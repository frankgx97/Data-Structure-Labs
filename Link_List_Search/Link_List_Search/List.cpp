#include "stdafx.h"
#include "List.h"


List::List(void)
{
	head = NULL;
	current = NULL;
}

int List::push(DATATYPE new_item)
{
	if (head == NULL) {
		head = new Node(new_item, NULL);
		current = head;
		return true;
	}
	current->next = new Node(new_item, NULL);
	current = current->get_next();
	return true;
}

int List::pop()
{
	Node * node_for_del;
	if (List::is_empty())
	{
		cout << "Á´±í¿Õ" << endl;
		return false;
	}
	node_for_del = head;
	head = head->get_next();
	delete node_for_del;
	return true;
}

void List::ls()
{
	Node * current = head;
	while (1)
	{
		cout << current->get_data();
		if (current->get_next() != NULL)
			current = current->get_next();
		else return;
	}
}

int List::is_empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

DATATYPE List::search(DATATYPE item) {
	current = head;
	while (current != NULL) {
		if (item == current->get_data())
			return current->get_data();
		current = current->next;
	}
	return -1;
}