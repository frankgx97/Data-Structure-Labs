#pragma once
#include <iostream>
using namespace std;

#define DATATYPE int
#define max_size 20
class SeqStack
{
public:
	SeqStack(void);
	int push(DATATYPE);//��ջ������Ԫ��
	int pop();//ɾ��ջ��Ԫ��
	DATATYPE get_top();//��ȡջ��Ԫ��
	int is_empty();//�Ƿ�Ϊ��
private:
	DATATYPE data[max_size];
	int top;
};