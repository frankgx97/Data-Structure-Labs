#include "stdafx.h"
#include "LinkStack.h"

void main()
{
	int ch;
	DATATYPE item;
	LinkStack stack;
	while (1)
	{
		cout << "ѡ��Ҫִ�еĹ���\n1.��ջ\n2.ɾ��ջ��\n3.��ʾջ��\n4.ջ�Ƿ�Ϊ�գ�1Ϊ�գ�0Ϊ�ǿգ�" << endl;
		cin >> ch;
		if (ch == 1)
		{
			cout << "Ҫ�����Ԫ�أ�" << endl;
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
