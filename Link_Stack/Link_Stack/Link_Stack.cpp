#include "stdafx.h"
#include "LinkStack.h"

void main()
{
	int ch;
	DATATYPE item;
	LinkStack stack;
	while (1)
	{
		cout << "选择要执行的功能\n1.入栈\n2.删除栈顶\n3.显示栈顶\n4.栈是否为空（1为空，0为非空）" << endl;
		cin >> ch;
		if (ch == 1)
		{
			cout << "要插入的元素：" << endl;
			cin >> item;
			stack.push(item);
		}
		else if(ch == 2)
			stack.pop();
		else if(ch == 3)
			cout << stack.get_top() << endl;
		else if(ch == 4)
			cout << stack.is_empty() << endl;
		system("pause");
		system("cls");
	}
}
