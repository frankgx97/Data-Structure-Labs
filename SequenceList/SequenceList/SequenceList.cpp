// SequenceList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Sequence.h"
#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e,f,num;
	SeqList *L;
	L = InitS();
	cout << "element number" << endl;
	cin >> num;
	InputS(L,num);
	DisplayS(L);
	cout << "插入位置，插入元素" << endl;
	cin >> a >> b;
	InsertS(L,a,b);

	cout << "搜索元素内容：" << endl;
	cin >> c;
	SeekS(L,c);
	cout << "搜索元素位置：" << endl;
	cin >> e;
	SeekSe(L,e);
	cout << "从位置删除元素：" << endl;
	cin >> d;
	DeleteS(L,d);
	cout << "从内容删除元素：" << endl;
	cin >> f;
	DeleteSe(L,f);
	system("pause");
	return 0;
}
