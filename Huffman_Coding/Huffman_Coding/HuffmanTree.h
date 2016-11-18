#pragma once
#include "HuffmanNode.h"
#include <queue>

class HuffmanTree
{
public:
	HuffmanTree();
	HuffmanNode * get_root();
	int build(string);
	void encode(HuffmanNode *, string);
	string decode(HuffmanNode *, string);
	void print_encoded(string);
private:
	HuffmanNode * root;
	map<char, string> table;
	map<char, int> get_freq(string);
	queue<HuffmanNode> get_queue(map<char, int>);
	HuffmanNode * get_tree(queue<HuffmanNode>);
};

