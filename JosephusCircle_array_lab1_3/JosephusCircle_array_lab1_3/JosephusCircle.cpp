#include "stdafx.h"
#include "JosephusCircle.h"


JosephusCircle::JosephusCircle(int n=N,int k=1,int m=5)
{
	JosephusCircle::n = N;
	JosephusCircle::k = k;
	JosephusCircle::m = m;

	
	for (int i=1;i<=N;i++)
		circle[i] = i;
}

void JosephusCircle::start_circle()
{
	int node_count = N;
	int current = 1;

	current = k;
	
	while(node_count > 0)
	{
		current = countdown(current,m);
		cout << "== node " << current << " eliminated , ";
		circle[current] = 0;
		node_count--;
		cout << node_count << " nodes remain==" << endl;
	}
	cout << "== DONE ==\n";
}

int JosephusCircle::countdown(int current,int num)
{
	for (int i=1;i<=num-1;i++)
	{
		if (circle[current] == 0)
			--i;
		++current;
		if (current > N)
			current = 1;
	}
	while (!circle[current])
	{
		current ++;
		if (current > N)
			current = 1;
	}
	return current;
}
