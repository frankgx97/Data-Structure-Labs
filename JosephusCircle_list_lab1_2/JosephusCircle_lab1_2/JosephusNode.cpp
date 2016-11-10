#include "stdafx.h"
#include "JosephusNode.h"


JosephusNode::JosephusNode(int id)
{
	JosephusNode::id = id;
}

void JosephusNode::set_next(JosephusNode *next)
{
	JosephusNode::next = next;
}

JosephusNode* JosephusNode::get_next()
{
	return JosephusNode::next;
}

int JosephusNode::get_id()
{
	return id;
}