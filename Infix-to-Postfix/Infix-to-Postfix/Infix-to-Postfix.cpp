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
	cout << "输入中缀表达式。\ne.g. 9+(3-1)*3+10/2\n答案：931-3*+102/+\n" << endl;
	cin >> infix;
    for (int i=0;i<=infix.length()-1;i++)
	{
		if (infix[i] >= '0' && infix[i] <= '9')//如果为数字，直接输出
			cout << infix[i];
		if ((infix[i] >= '(' && infix[i] <= '*') || infix[i] == '+' || infix[i] == '-' || infix[i] == '/')
		//如果为符号，判断其与栈顶符号的优先级，如果是右括号或优先级低于栈顶符号，则栈顶元素依次出栈并输出，并将当前符号进栈
		{
			if (infix[i] == '(')
				stack.push(infix[i]);
			elif (infix[i] == ')' || (infix[i] == '+' && (stack.get_top() == '*' || stack.get_top() == '/')) || (infix[i] == '-') && (stack.get_top() == '*' || stack.get_top() == '/'))
			{
				if (infix[i] == ')')//当右括号时，将左括号之上的所有元素出栈
				{
					while (stack.get_top() != '(')
						cout << stack.pop();
					stack.pop();//清除栈中剩余的左括号
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
	while (stack.get_top() != NULL)//剩余元素全部出栈
		cout << stack.pop();
	cout << endl;
	system("pause");
}