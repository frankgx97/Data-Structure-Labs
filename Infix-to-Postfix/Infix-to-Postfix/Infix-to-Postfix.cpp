#include "stdafx.h"
#include "LinkStack.h"
#include <string>

/* ascii
60-71	0-9
50	(
51	)
52	*
53	+
55	-
57	/
*/

void main()
{
	string infix;
	LinkStack stack;
	cout << "������׺���ʽ��\ne.g. 9+(3-1)*3+10/2\n�𰸣�931-3*+102/+\n" << endl;
	cin >> infix;
    for (int i=0;i<=infix.length()-1;i++)
	{
		if (infix[i] >= '0' && infix[i] <= '9')//���Ϊ���֣�ֱ�����
			cout << infix[i];
		if ((infix[i] >= '(' && infix[i] <= '*') || infix[i] == '+' || infix[i] == '-' || infix[i] == '/')
		//���Ϊ���ţ��ж�����ջ�����ŵ����ȼ�������������Ż����ȼ�����ջ�����ţ���ջ��Ԫ�����γ�ջ�������������ǰ���Ž�ջ
		{
			if (infix[i] == '(')
				stack.push(infix[i]);
			elif (infix[i] == ')' || (infix[i] == '+' && (stack.get_top() == '*' || stack.get_top() == '/')) || (infix[i] == '-') && (stack.get_top() == '*' || stack.get_top() == '/'))
			{
				if (infix[i] == ')')//��������ʱ����������֮�ϵ�����Ԫ�س�ջ
				{
					while (stack.get_top() != '(')
						cout << stack.pop();
					stack.pop();//���ջ��ʣ���������
					continue;
				}
				else
				{
					while (stack.get_top() != NULL)
						cout << stack.pop();
					stack.push(infix[i]);
				}
			}
			else
				stack.push(infix[i]);
		}
	}
	while (stack.get_top() != NULL)//ʣ��Ԫ��ȫ����ջ
		cout << stack.pop();
	cout << endl;
	system("pause");
}