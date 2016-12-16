#include "stdafx.h"
#include "Graph.h"
Graph::Graph()
{
	char c1, c2;
	int i, p1, p2;

	cout << "顶点数量: ";
	cin >> vex_num;
	cout << "边数量：";
	cin >> edge_num;
	if (vex_num < 1 || edge_num < 1 || (edge_num >(vex_num * (vex_num - 1))))
	{
		cout << "invalid vex" << endl;
		return;
	}

	// 初始化顶点
	for (i = 0; i < vex_num; i++)
	{
		cout << "顶点(" << i << "): ";
		cin >> vexs[i];
	}

	for (int i = 0; i <= vex_num; i++)
		for (int j = 0; j <= vex_num; j++)
			matrix[i][j] = 65535;

	// 初始化边
	for (i = 0; i < edge_num; i++)
	{
		int weight;
		cout << "边(" << i << "): ";

		cin >> c1 >> c2 >> weight;

		p1 = getPosition(c1);
		p2 = getPosition(c2);
		if (p1 == -1 || p2 == -1)
		{
			cout << "invalid edge" << endl;
			return;
		}

		matrix[p1][p2] = weight;
		matrix[p2][p1] = weight;
	}
}

int Graph::getPosition(char ch)
{
	//返回ch在matrix矩阵中的位置
	int i;
	for (i = 0; i<vex_num; i++)
		if (vexs[i] == ch)
			return i;
	return -1;
}


int Graph::firstVertex(int v)
{
	//返回顶点v的第一个邻接顶点的索引，失败则返回-1
	int i;

	if (v<0 || v>(vex_num - 1))
		return -1;

	for (i = 0; i < vex_num; i++)
		if (matrix[v][i] == 1)
			return i;

	return -1;
}

int Graph::nextVertex(int v, int w)
{
	//返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
	int i;

	if (v<0 || v>(vex_num - 1) || w<0 || w>(vex_num - 1))
		return -1;

	for (i = w + 1; i < vex_num; i++)
		if (matrix[v][i] == 1)
			return i;

	return -1;
}

void Graph::DFS(int i, int *visited)
{
	int w;

	visited[i] = 1;
	cout << vexs[i] << " ";
	// 遍历该顶点的所有邻接顶点。若是没有访问过，那么继续往下走
	for (w = firstVertex(i); w >= 0; w = nextVertex(i, w))
		if (!visited[w])
			DFS(w, visited);
}


void Graph::DFS()
{
	/**
	* 访问指定的起始顶点；
	* 若当前访问的顶点的邻接顶点有未被访问的，则任选一个访问之；反之，退回到最近访问过的顶点；直到与起始顶点相通的全部顶点都访问完毕；
	* 若此时图中尚有顶点未被访问，则再选其中一个顶点作为起始顶点并访问之，转 2； 反之，遍历结束。
	*/
	int i;
	int visited[MAX];

	for (i = 0; i < vex_num; i++)
		visited[i] = 0;

	cout << "DFS: ";
	for (i = 0; i < vex_num; i++)
		if (!visited[i])
			DFS(i, visited);
	cout << endl;
}

void Graph::BFS()
{
	int head = 0;
	int rear = 0;
	int queue[MAX];
	int visited[MAX];   // 顶点访问标记
	int i, j, k;

	for (i = 0; i < vex_num; i++)
		visited[i] = 0;

	cout << "BFS: ";
	for (i = 0; i < vex_num; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << vexs[i] << " ";
			queue[rear++] = i;  // 入队列
		}
		while (head != rear)
		{
			j = queue[head++];  // 出队列
			for (k = firstVertex(j); k >= 0; k = nextVertex(j, k)) //k是为访问的邻接顶点
			{
				if (!visited[k])
				{
					visited[k] = 1;
					cout << vexs[k] << " ";
					queue[rear++] = k;
				}
			}
		}
	}
	cout << endl;
}

void Graph::print()
{
	int i, j;

	cout << "邻接矩阵：" << endl;
	for (i = 0; i < vex_num; i++)
	{
		for (j = 0; j < vex_num; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void Graph::prim(int start)
{
	int min, i, j, k, m, n, sum;
	int index = 0;         // prim最小树的索引，即prims数组的索引
	char prims[MAX];     // prim最小树的结果数组
	int weights[MAX];    // 顶点间边的权值，如果为0则表示已经加入最小生成树数组

	/**
	* 最小生成树中第一个数是start顶点
	* 初始化顶点的权值数组，
	* 将每个顶点的权值初始化为第start个顶点到该顶点的权值。
	*/
	prims[index++] = vexs[start];
	for (i = 0; i < vex_num; i++)
		weights[i] = matrix[start][i];

	weights[start] = 0;//start顶点的权值为0。

	for (i = 0; i < vex_num; i++)
	{
		if (start == i)
			continue;

		j = 0;
		k = 0;
		min = 65535;
		//找出权值最小的顶点。
		while (j < vex_num)
		{
			//如果weights[j]=0，表示已经加入了最小生成树中
			if (weights[j] != 0 && weights[j] < min)
			{
				min = weights[j];
				k = j;
			}
			j++;
		}

		// 权值最小的顶点k，将k加入到最小生成树的结果数组中
		prims[index++] = vexs[k];
		weights[k] = 0;
		// 当k被加入到最小生成树的结果数组中之后，更新其它顶点的权值。
		for (j = 0; j < vex_num; j++)
		{
			if (weights[j] != 0 && matrix[k][j] < weights[j])
				weights[j] = matrix[k][j];
		}
	}

	// 计算最小生成树的权值
	sum = 0;
	for (i = 1; i < index; i++)
	{
		min = 65535;
		// 获取prims[i]在matrix中的位置
		n = getPosition(prims[i]);
		// 在vexs[0...i]中，找出到j的权值最小的顶点。
		for (j = 0; j < i; j++)
		{
			m = getPosition(prims[j]);
			if (matrix[m][n]<min)
				min = matrix[m][n];
		}
		sum += min;
	}
	// 打印最小生成树
	cout << "权值[" << vexs[start] << "]：" << sum << ": ";
	for (i = 0; i < index; i++)
		cout << prims[i] << " ";
	cout << endl;
}