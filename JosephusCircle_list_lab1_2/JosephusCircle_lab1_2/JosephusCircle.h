#pragma once
#include "JosephusNode.h"
class JosephusCircle
{
public:
	//n=总人数，k=从k开始报数，m=数到m的人出列
	JosephusCircle(int,int,int);
	void start_circle();
	JosephusNode * countdown(JosephusNode *,int);
private:
	int n,k,m;
	JosephusNode *head;
};

