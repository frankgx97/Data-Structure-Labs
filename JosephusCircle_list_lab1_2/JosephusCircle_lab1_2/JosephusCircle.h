#pragma once
#include "JosephusNode.h"
class JosephusCircle
{
public:
	//n=��������k=��k��ʼ������m=����m���˳���
	JosephusCircle(int,int,int);
	void start_circle();
	JosephusNode * countdown(JosephusNode *,int);
private:
	int n,k,m;
	JosephusNode *head;
};

