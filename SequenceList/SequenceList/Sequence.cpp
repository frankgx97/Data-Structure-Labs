#include "stdafx.h"
#include "Sequence.h"

SeqList *InitS()
{
	SeqList *L;
	L = new SeqList;
	L->SeqLength = 0;
	return L;
}

void InputS(SeqList *L,int n)
{
	cout << "输入要储存的元素" << endl;
	for (int i=0;i<n;i++)
	{
		cin >> L->data[i];
		L->SeqLength++;
	}
	cin.sync();
}

void DisplayS(SeqList *L)
{
	for (int i=0;i<=L->SeqLength-1;i++)
		cout << L->data[i] << "";
	cout << endl;
}

int InsertS(SeqList*L,int i,DataType x)
{
	i-=1;
	cout << "item,position" << endl;
	int j;
	if (L->SeqLength == MAXSIZE-1)
	{
		cout << "full" <<endl;
		return -1;
	}
	if (i<0 || i>L->SeqLength)
	{
		cout << "error" <<endl;
		return 0;
	}
	for (j=L->SeqLength-1;j>=i;j--)
		L->data[j+1] = L->data[j];
	L->data[i]=x;
	L->SeqLength++;
	DisplayS(L);
}

int DeleteS(SeqList *L,int i)
{
	i -= 1;
	int j;
	cout << "remove i+1" << endl;
	if (i<0 || i>L->SeqLength)
	{
		cout << "error" <<endl;
		return 0;
	}
	for (j=i;j<=L->SeqLength-1;j++)
		L->data[j] = L->data[j+1];
	L->SeqLength--;
	DisplayS(L);
}

int DeleteSe(SeqList *L,DataType x)
{
	int a = SeekS(L,x);
	if (a)
		DeleteS(L,a);
	else
		cout << "err" << endl;
	return 0;
}

int SeekS(SeqList *L,DataType x)
{
	int i = 0;
	while(i<L->SeqLength-1 && L->data[i] != x)
		++i;
	if (i<L->SeqLength-1)
	{
		cout << "item position:" << i+1 << endl;
		return i+1;
	}else{
		cout << "not found" << endl;
		return 0;
	}
}


int SeekSe(SeqList *L,int i)
{
	if (i<1||i>L->SeqLength)
	{
		cout << "not found\n";
		return 0;
	}
	cout << L->data[i-1] <<endl;
	return 0;
}


