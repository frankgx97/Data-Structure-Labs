#pragma once
#include <iostream>
using namespace std;

class JosephusNode
{
public:
	JosephusNode(int);
	void set_next(JosephusNode *);
	JosephusNode * get_next();
	int get_id();

	JosephusNode *next;
private:
	int id;

};