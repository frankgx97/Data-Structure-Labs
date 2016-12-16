#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
class Graph {
private:
	char vexs[MAX];    // ���㼯��
	int vex_num;             // ������
	int edge_num;             // ����
	int matrix[MAX][MAX];   // �ڽӾ���

public:
	Graph();	// ����ͼ(�Լ���������)
	void DFS();	// ���������������ͼ
	void BFS();	// �����������
	void print();	// ��ӡ�������ͼ
	void prim(int);

private:
	int getPosition(char);// ����ch��matrix�����е�λ��
	int firstVertex(int);	// ���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1
	int nextVertex(int, int);	// ���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1
	void DFS(int,int *);	// ���������������ͼ�ĵݹ�ʵ��
};