#include "stdafx.h"
#include "Graph.h"


int main()
{
	Graph graph;

	graph.print();   // ��ӡͼ
	graph.DFS();     // ������ȱ���
	graph.BFS();     // ������ȱ���
	graph.prim(0);	 //�Ӷ���0��ʼ������С������
	system("pause");
	return 0;
}
