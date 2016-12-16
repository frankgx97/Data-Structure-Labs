#include "stdafx.h"
#include "Graph.h"
Graph::Graph()
{
	char c1, c2;
	int i, p1, p2;

	cout << "��������: ";
	cin >> vex_num;
	cout << "��������";
	cin >> edge_num;
	if (vex_num < 1 || edge_num < 1 || (edge_num >(vex_num * (vex_num - 1))))
	{
		cout << "invalid vex" << endl;
		return;
	}

	// ��ʼ������
	for (i = 0; i < vex_num; i++)
	{
		cout << "����(" << i << "): ";
		cin >> vexs[i];
	}

	for (int i = 0; i <= vex_num; i++)
		for (int j = 0; j <= vex_num; j++)
			matrix[i][j] = 65535;

	// ��ʼ����
	for (i = 0; i < edge_num; i++)
	{
		int weight;
		cout << "��(" << i << "): ";

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
	//����ch��matrix�����е�λ��
	int i;
	for (i = 0; i<vex_num; i++)
		if (vexs[i] == ch)
			return i;
	return -1;
}


int Graph::firstVertex(int v)
{
	//���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1
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
	//���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1
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
	// �����ö���������ڽӶ��㡣����û�з��ʹ�����ô����������
	for (w = firstVertex(i); w >= 0; w = nextVertex(i, w))
		if (!visited[w])
			DFS(w, visited);
}


void Graph::DFS()
{
	/**
	* ����ָ������ʼ���㣻
	* ����ǰ���ʵĶ�����ڽӶ�����δ�����ʵģ�����ѡһ������֮����֮���˻ص�������ʹ��Ķ��㣻ֱ������ʼ������ͨ��ȫ�����㶼������ϣ�
	* ����ʱͼ�����ж���δ�����ʣ�����ѡ����һ��������Ϊ��ʼ���㲢����֮��ת 2�� ��֮������������
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
	int visited[MAX];   // ������ʱ��
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
			queue[rear++] = i;  // �����
		}
		while (head != rear)
		{
			j = queue[head++];  // ������
			for (k = firstVertex(j); k >= 0; k = nextVertex(j, k)) //k��Ϊ���ʵ��ڽӶ���
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

	cout << "�ڽӾ���" << endl;
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
	int index = 0;         // prim��С������������prims���������
	char prims[MAX];     // prim��С���Ľ������
	int weights[MAX];    // �����ߵ�Ȩֵ�����Ϊ0���ʾ�Ѿ�������С����������

	/**
	* ��С�������е�һ������start����
	* ��ʼ�������Ȩֵ���飬
	* ��ÿ�������Ȩֵ��ʼ��Ϊ��start�����㵽�ö����Ȩֵ��
	*/
	prims[index++] = vexs[start];
	for (i = 0; i < vex_num; i++)
		weights[i] = matrix[start][i];

	weights[start] = 0;//start�����ȨֵΪ0��

	for (i = 0; i < vex_num; i++)
	{
		if (start == i)
			continue;

		j = 0;
		k = 0;
		min = 65535;
		//�ҳ�Ȩֵ��С�Ķ��㡣
		while (j < vex_num)
		{
			//���weights[j]=0����ʾ�Ѿ���������С��������
			if (weights[j] != 0 && weights[j] < min)
			{
				min = weights[j];
				k = j;
			}
			j++;
		}

		// Ȩֵ��С�Ķ���k����k���뵽��С�������Ľ��������
		prims[index++] = vexs[k];
		weights[k] = 0;
		// ��k�����뵽��С�������Ľ��������֮�󣬸������������Ȩֵ��
		for (j = 0; j < vex_num; j++)
		{
			if (weights[j] != 0 && matrix[k][j] < weights[j])
				weights[j] = matrix[k][j];
		}
	}

	// ������С��������Ȩֵ
	sum = 0;
	for (i = 1; i < index; i++)
	{
		min = 65535;
		// ��ȡprims[i]��matrix�е�λ��
		n = getPosition(prims[i]);
		// ��vexs[0...i]�У��ҳ���j��Ȩֵ��С�Ķ��㡣
		for (j = 0; j < i; j++)
		{
			m = getPosition(prims[j]);
			if (matrix[m][n]<min)
				min = matrix[m][n];
		}
		sum += min;
	}
	// ��ӡ��С������
	cout << "Ȩֵ[" << vexs[start] << "]��" << sum << ": ";
	for (i = 0; i < index; i++)
		cout << prims[i] << " ";
	cout << endl;
}