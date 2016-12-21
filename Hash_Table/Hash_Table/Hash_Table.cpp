#include "stdafx.h"
#include "Node.h"
#include <time.h>
#include "stdlib.h"
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000

#define random(x) (rand()%x)


int main()
{
	Node * hash_table[MAX] = { NULL };
	Node * current;
	int rnd, key, flag = 0;
	srand((int)time(0));
	int arr[19999] = { 0 };
	for (int i = 0; i < 12000; i++) {
		while (1) {
			rnd = random(19999);
			if (arr[rnd] == 0) {
				arr[rnd] = 1;
				break;
			}
		}
		key = rnd / 2;
		cout << i << "  -  ";
		if (hash_table[key] == NULL) {
			hash_table[key] = new Node(rnd);
			cout << "[" << key << "]" << rnd << endl;
		}
		else {
			current = hash_table[key];
			cout << "[" << key << "]";
			cout << " => " << current->data;
			current->next = new Node(rnd);
			cout <<" -> " << rnd << endl;
		}
	}
	cout << "要查找的键：" << endl;
	cin >> key;
	cout << '[' << key << ']';
	current = hash_table[key];
	if (current == NULL) {
		cout << "未找到" << endl;
		system("pause");
		return 0;
	}
	while (current != NULL) {
		cout << " -> " << current->data;
		current = current->next;
	}
	cout << endl;
	system("pause");
    return 0;
}

