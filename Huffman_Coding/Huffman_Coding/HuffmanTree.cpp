#include "stdafx.h"
#include "HuffmanTree.h"
#include "malloc.h"

HuffmanTree::HuffmanTree()
{
	root = NULL;
}

HuffmanNode * HuffmanTree::get_root()
{
	return root;
}

int HuffmanTree::build(string str)
{
	/*
	1.��ȡ�ַ�����ͳ��ÿ���ַ���Ƶ�Σ���д��map������
	2.�����������ζ�ȡ��С��ֵ��������-ֵ���д��һ��HuffmanNode�����
	3.�Ӷ����ж�ȡHuffman�ڵ㣬��������
	4.�ݹ����Huffman����ÿ��������ʱ��0��������ʱ��1
	*/
	map<char, int> freq;
	queue<HuffmanNode> queue;
	root = get_tree(get_queue(get_freq(str)));
	return true;
}

void HuffmanTree::encode(HuffmanNode * root,string code)
{
	if (root->l_child == NULL && root->r_child == NULL)
	{
		cout << root->data << ": " << code << endl;
		table[root->data] = code;
		return;
	}
	if (root->l_child != NULL)
		encode(root->l_child, code + '0');
	if (root->r_child != NULL)
		encode(root->r_child, code + '1');
}

void HuffmanTree::print_encoded(string code)
{
	for (int i = 0; i <= code.length() - 1; i++)
	{
		if (table.count(code[i]))
			cout << table[code[i]];
	}
	cout << endl;
	return;
}

string HuffmanTree::decode(HuffmanNode * root, string str) //����
{
	string rst = "";
	HuffmanNode * current = root;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
			current = current->l_child;
		else
			current = current->r_child;
		if (current->l_child == NULL && current->r_child == NULL) //�õ�һ���ַ�
		{
			rst += current->data;
			current = root;
		}
	}
	return rst;
}

HuffmanNode * HuffmanTree::get_tree(queue<HuffmanNode> queue)
{
	HuffmanNode * left;
	HuffmanNode * right;
	right = (HuffmanNode *)malloc(sizeof(HuffmanNode));
	left = (HuffmanNode *)malloc(sizeof(HuffmanNode));
	*left = queue.front();
	queue.pop();
	*right = queue.front();
	queue.pop();
	while (!queue.empty())
	{
		right = new HuffmanNode(NULL, left->weight + right->weight, left, right);
		left = (HuffmanNode *)malloc(sizeof(HuffmanNode));
		*left = queue.front();
		queue.pop();
	}
	root = new HuffmanNode(NULL, left->weight + right->weight, left, right);
	return root;
}

queue<HuffmanNode> HuffmanTree::get_queue(map<char, int> freq)
{
	map<char, int>::iterator min_iter;
	queue<HuffmanNode> queue;
	int min_int = 65534;
	while (freq.size())
	{
		min_int = 65534;
		for (map<char, int>::iterator i = freq.begin(); i != freq.end(); i++)
		{
			//����map���ҳ���С�Ľڵ�
			if (i->second <= min_int)
			{
				min_int = i->second;
				min_iter = i;
			}
		}
		//����С�Ľڵ����ݳ�ʼ��Ϊһ��Huffman�ڵ㲢���
		HuffmanNode queue_node(min_iter->first, min_iter->second,NULL,NULL);
		queue.push(queue_node);
		freq.erase(min_iter);
	}
	return queue;
}

map<char, int> HuffmanTree::get_freq(string str)
{
	map<char, int> freq;
	for (int i = 0; i <= str.length() - 1; i++)
	{
		if (freq.count(str[i]))
			freq[str[i]]++;
		else
			freq[str[i]] = 1;
	}
	return freq;
}