#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
class Graph {
private:
	char vexs[MAX];    // 顶点集合
	int vex_num;             // 顶点数
	int edge_num;             // 边数
	int matrix[MAX][MAX];   // 邻接矩阵

public:
	Graph();	// 创建图(自己输入数据)
	void DFS();	// 深度优先搜索遍历图
	void BFS();	// 广度优先搜索
	void print();	// 打印矩阵队列图
	void prim(int);

private:
	int getPosition(char);// 返回ch在matrix矩阵中的位置
	int firstVertex(int);	// 返回顶点v的第一个邻接顶点的索引，失败则返回-1
	int nextVertex(int, int);	// 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
	void DFS(int,int *);	// 深度优先搜索遍历图的递归实现
};