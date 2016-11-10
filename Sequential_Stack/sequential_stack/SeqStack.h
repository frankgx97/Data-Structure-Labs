#pragma once
#include <iostream>
using namespace std;

#define DATATYPE int
#define max_size 20
class SeqStack
{
public:
	SeqStack(void);
	int push(DATATYPE);//在栈顶插入元素
	int pop();//删除栈顶元素
	DATATYPE get_top();//读取栈顶元素
	int is_empty();//是否为空
private:
	DATATYPE data[max_size];
	int top;
};