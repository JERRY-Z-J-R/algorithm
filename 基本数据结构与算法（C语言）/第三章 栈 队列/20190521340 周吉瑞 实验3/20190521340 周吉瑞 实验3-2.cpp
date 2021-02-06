/*
	Name: 实验3-2 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 14/04/20 13:54
	Description: 编写一个十进制转换为八进制的数制转换程序（要求利用栈来实现），
				并验证其正确性。如输入1348，输出2504
*/

#include <stdio.h>
#include "intstack.h"

int main()
{
	int n;
	SqStack S;
	SElemType e;
	
	printf("input (10 jinzhi):");
	scanf("%d", &n);
	
	InitStack(S);
	
	while (n) {
		Push(S, n % 8);
		n = n / 8;
	}
	cout << "(8 jinzhi):";
	
	while (!StackEmpty(S)) {
		Pop(S, e);
		cout << e;
	}
} 
