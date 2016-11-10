#include "stdafx.h"
#include "JosephusCircle.h"

JosephusCircle::JosephusCircle(int n,int k,int m)//n=总人数，k=从k开始报数，m=数到m的人出列
{
	head = NULL;
	JosephusNode *current = NULL;
	JosephusCircle::n = n;
	JosephusCircle::k = k;
	JosephusCircle::m = m;

	for (int i=1;i<=n;i++)
	{
		if (i == 1)
		{
			head = new JosephusNode(i);
			current = head;
			continue;
		}
		current -> set_next(new JosephusNode(i));
		current = current -> get_next();
	}
	current -> set_next(head);
}

/*已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。
从编号为k的人开始报数，数到m的那个人出列；
他的下一个人又从1开始报数，数到m的那个人又出列；*/
void JosephusCircle::start_circle()
{
	int node_count = n;
	JosephusNode *current = head;
	JosephusNode *node_for_del = NULL;
	current = countdown(head,k-1);
	cout << "k=" << current -> get_id() << endl;
	//工作指针位于k，从k开始。
	while (node_count>0)
	{
		current = countdown(current,m-2);
		//工作指针位于要出列的前一位
		cout << "== node " << current -> next -> get_id() << " eliminated,";
		node_for_del = current -> get_next();//待删除的节点
		current ->set_next(current -> next -> next);//出列。
		delete node_for_del;//释放内存
		node_count--;
		current = current -> get_next();
		cout << node_count<< " nodes remain ==\n";
	}
}

JosephusNode * JosephusCircle::countdown(JosephusNode *head,int num)
{
	JosephusNode *current = head;
	for (int i=1;i<=num;i++)
		current = current -> get_next();
	return current;
}