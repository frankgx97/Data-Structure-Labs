#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <map>

class HuffmanNode
{
public:
	HuffmanNode(char,int,HuffmanNode *,HuffmanNode *);
	char data;
	int weight;
	HuffmanNode * l_child;
	HuffmanNode * r_child;
private:

};

