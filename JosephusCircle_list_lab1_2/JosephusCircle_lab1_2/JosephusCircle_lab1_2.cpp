#include "stdafx.h"
#include "JosephusCircle.h"
/*���ݽṹʵ��1
Լɪ��ѭ������ʵ��*/

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

