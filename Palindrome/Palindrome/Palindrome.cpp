#include "stdafx.h"
#include "Link_Stack.h"

void main()
{
	char c;
	int num=0,is_odd=false;
	LinkStack stack,stack1;
    while( (c = getchar()) != '\n' )  //���������ж�ȡ�ַ�
	{
        stack.push(c); 
		num++;
	}
	if (num % 2)
		is_odd = true;
	num /= 2;
	for (int i=1;i<=num;i++)
	{
		stack1.push(stack.get_top());
		stack.pop();
	}
	if (is_odd)
		stack.pop();
	for (int i=1;i<=num;i++)
	{
		if (stack.get_top() != stack1.get_top())
		{
			cout << "���ǻ��ġ�" << endl;
			system("pause");
			return;
		}
		else	
		{
			stack1.pop();
			stack.pop();
		}
	}
	cout << "�ǻ��ġ�" << endl;
	system("pause");
	return;
}

