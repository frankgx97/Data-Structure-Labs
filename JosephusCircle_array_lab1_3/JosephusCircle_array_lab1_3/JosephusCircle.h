#pragma once
#include <iostream>
using namespace std;
#define N 9

class JosephusCircle
{
public:
	JosephusCircle(int,int,int);
	void start_circle();
	int n,k,m;

private:
	int countdown(int,int);
	int circle[N+1];
};

