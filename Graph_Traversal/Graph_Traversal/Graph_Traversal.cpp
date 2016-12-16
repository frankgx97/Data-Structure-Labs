#include "stdafx.h"
#include "Graph.h"


int main()
{
	Graph graph;

	graph.print();   // 打印图
	graph.DFS();     // 深度优先遍历
	graph.BFS();     // 广度优先遍历
	graph.prim(0);	 //从顶点0开始生成最小生成树
	system("pause");
	return 0;
}
