#include "stdafx.h"
#include "List.h"

int main()
{
	List list;
	int num;
	DATATYPE item;
	cout << "Ԫ�ظ�����" << endl;
	cin >> num;
	cout << "��������Ԫ��" << endl;
	for (int i = 0; i < num; i++) {
		cin >> item;
		list.push(item);
	}
	cout << "Ҫ������Ԫ�أ�" << endl;
	cin >> item;
	cout << "���������" << list.search(item) << endl;
	system("pause");
    return 0;
}

