#pragma once
#include <iostream>
using namespace std;
#define MAXSIZE 18
typedef int DataType;
typedef struct
{
	DataType data[MAXSIZE];
	int SeqLength;
}SeqList;

SeqList *InitS();
void InputS(SeqList* ,int);
void DisplayS(SeqList*);
int InsertS(SeqList*,int,DataType);
int DeleteS(SeqList*,int);
int DeleteSe(SeqList*,DataType);
int SeekS(SeqList*,DataType);
int SeekSe(SeqList*,int);



