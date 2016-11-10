#include "stdafx.h"
#include "JosephusCircle.h"
/*数据结构实验1
约瑟夫环循环链表实现*/

int main()
{
	int n,k,m;
	cout << "input n,k,m" <<endl;
	cin >> n >> k >> m;
	JosephusCircle circle(n,k,m);
	circle.start_circle();
	system("pause");
	return 0;
}

