// SequenceList.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "����λ�ã�����Ԫ��" << endl;
	cin >> a >> b;
	InsertS(L,a,b);

	cout << "����Ԫ�����ݣ�" << endl;
	cin >> c;
	SeekS(L,c);
	cout << "����Ԫ��λ�ã�" << endl;
	cin >> e;
	SeekSe(L,e);
	cout << "��λ��ɾ��Ԫ�أ�" << endl;
	cin >> d;
	DeleteS(L,d);
	cout << "������ɾ��Ԫ�أ�" << endl;
	cin >> f;
	DeleteSe(L,f);
	system("pause");
	return 0;
}
