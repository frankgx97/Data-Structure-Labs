#include "stdafx.h"
#include "QueueNode.h"


QueueNode::QueueNode(DATATYPE new_data,QueueNode * set_next)
{
	QueueNode::data = new_data;
	QueueNode::next = set_next;
}

void QueueNode::set_next(QueueNode *next)
{
	QueueNode::next = next;
}

QueueNode* QueueNode::get_next()
{
	return QueueNode::next;
}

int QueueNode::get_data()
{
	return data;
}