// Circular_Queue.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LinkQueue.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

void main()
{
	int ch;
	DATATYPE item;
	LinkQueue queue;
	while (1)
	{
		cout << "ѡ��Ҫִ�еĹ���\n1.���\n2.����\n3.��ʾ\n4.��" << endl;
		cin >> ch;
		if (ch == 1)
		{
			cout << "Ҫ��ӵ�Ԫ�أ�" << endl;
			cin >> item;
			queue.in(item);
		}
		elif(ch == 2)
			queue.out();
		elif (ch == 3)
			queue.ls();
		elif (ch == 4)
			queue.empty();
		system("pause");
		system("cls");
	}
	return;
}