// Circular_Queue.cpp : 定义控制台应用程序的入口点。
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
		cout << "选择要执行的功能\n1.入队\n2.出队\n3.显示\n4.空" << endl;
		cin >> ch;
		if (ch == 1)
		{
			cout << "要入队的元素：" << endl;
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