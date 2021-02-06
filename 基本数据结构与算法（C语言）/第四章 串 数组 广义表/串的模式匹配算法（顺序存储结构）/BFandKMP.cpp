/*
	Name: 实验：实现串的模式匹配功能（顺序存储结构） 
	Author: Jerry_Zhou
	Date: 02/05/20 14:06
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXSIZE 100

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {

	char ch[MAXSIZE + 1];	// ch[0] = StringLength
	
} SString;

Status CreateString(SString &S);
Status PrintStringLength(SString S);
int Index_BF(SString S, SString T, int pos, int &n);
void Get_nextval(SString T, int *nextval);
int Index_KMP(SString S, SString T, int pos, int &m);

int main(void)
{
	int pos;
	int n, m;	// 函数循环计数器
	SString S, T;

	printf("---------------------------\n");
	printf("-----串的模式匹配BF/KMP-----\n");
	printf("---------------------------\n");

	printf("[1].Create String S\n");		// 创建主串S
	CreateString(S);

	PrintStringLength(S);

	printf("---------------------------\n");

	printf("[2].Create Srting T\n");		// 创建子串T
	CreateString(T);

	PrintStringLength(T);

	printf("---------------------------\n");

	printf("[3].IndexString\n");			// 设置检索起点POS
	printf("input pos:");
	scanf("%d", &pos);

	printf("---------------------------\n");

	printf("1. Index_BF\n");		// BF算法
	printf("T is located in the S no.%d\n", Index_BF(S, T, pos, n));
	printf("run sum is: %d\n", n);		// BF算法最多执行语句次数
	
	printf("---------------------------\n");

	printf("2. Index_KMP\n");		// KMP算法
	printf("T is located in the S no.%d\n", Index_KMP(S, T, pos, m));
	printf("run sum is: %d\n", m);	// KMP算法最多执行语句次数

	printf("---------------------------\n");
	
	system("pause");
	return 0;	
}// main

Status CreateString(SString &S)		// 创建顺序串
{
	char c;


	printf("input Srting:");
	for (int i = 1; i <= 100; ++i) {
		cin >> c;

		if (c == '#')
			return OK;
		else {
			S.ch[i] = c;
			S.ch[0] = i;
		}
	}
}// CreateString

Status PrintStringLength(SString S)		// 输出顺序串串长 
{
	printf("\nLength = %d\n", S.ch[0]);

	return OK;
}// PrintString

int Index_BF(SString S, SString T, int pos, int &n)
// 返回子串T在主串S中的第pos个字符之后的位置，若不存在，则函数返回0
{
	int i = pos;
	int j = 1;

	n = 0;

	while (i <= S.ch[0] && j <= T.ch[0]) {
		if (S.ch[i] == T.ch[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 2;
			j = 1; 
		}

		++n;
	}

		if (j > T.ch[0])
			return (i - T.ch[0]);
		else
			return 0;
}// Index_BF

void Get_nextval(SString T, int nextval[])
// 求模式串T中的next函数修正值并存入数组nextval
{
	int i, j;

	i = 1;
	j = 0;
	nextval[1] = 0;

	while (i < T.ch[0]) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			++i;
			++j;

			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}// Get_nextval

int Index_KMP(SString S, SString T, int pos, int &m)
// 返回子串T在主串S中的第pos个字符之后的位置，若不存在，则函数返回0
{
	int i = pos;
	int j = 1;
	int nextval[100];

	m = 0;

	Get_nextval(T, nextval);

	while (i <= S.ch[0] && j <= T.ch[0]) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;
		}
		else 
			j = nextval[j];

		++m;
	}
		if (j > T.ch[0])
			return (i - T.ch[0]);
		else
			return 0;
}// Index_KMP

