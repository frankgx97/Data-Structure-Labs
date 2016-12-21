#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX 100

int binary_search(int [], int, int, int);

int main()
{
	int arr[MAX];
	int num, key;
	cout << "元素数量:" << endl;
	cin >> num;
	cout << "输入数组" << endl;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		cin.sync();
	}
	cout << "要查找的元素" << endl;
	cin >> key;
	cout << "位置：" << binary_search(arr, 0, num, key) << endl;
	system("pause");
    return 0;
}

int binary_search(int arr[], int start, int end, int key) {
	int mid;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (arr[mid] < key)
			start = mid + 1;
		else if (arr[mid] > key)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}