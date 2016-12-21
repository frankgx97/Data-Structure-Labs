#include "stdafx.h"
#include "List.h"

int main()
{
	List list;
	int num;
	DATATYPE item;
	cout << "元素个数：" << endl;
	cin >> num;
	cout << "输入链表元素" << endl;
	for (int i = 0; i < num; i++) {
		cin >> item;
		list.push(item);
	}
	cout << "要搜索的元素：" << endl;
	cin >> item;
	cout << "搜索结果：" << list.search(item) << endl;
	system("pause");
    return 0;
}

