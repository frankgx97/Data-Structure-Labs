#include "stdafx.h"
#include "HuffmanNode.h"


HuffmanNode::HuffmanNode(char new_data,int new_weight,HuffmanNode * new_l_child = NULL,HuffmanNode * new_r_child = NULL)
{
	data = new_data;
	weight = new_weight;
	l_child = new_l_child;
	r_child = new_r_child;
}

