/*
	Name:20190521340 周吉瑞 实验6-1
	Copyright:
	Date:周吉瑞
	Description:线性表的查找(设置监视哨的顺序查找) 
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 100

typedef int Status;
typedef int KeyType;

int count_1 = 0; 

typedef struct {
	KeyType key;
	char name;
} ElemType;

typedef struct {
	ElemType *R;
	int length;
} SSTable;

Status InitList_SSTable(SSTable &ST)
{
	ST.R = new ElemType[MAXSIZE + 1];

	if (!ST.R) {
		printf("初始化错误.\n");
		exit(OVERFLOW);
	}

	ST.length = 0;
	
	return OK;
}

Status Create_SSTable(SSTable &ST)
{
	int i = 1;
	int j;

	printf("创建顺序表, 以'0'为结束标志.\n");

	do {
		scanf("%d", &j);

		if (j == 0) {
			break;
		}

		ST.R[i++].key = j;
		ST.length++;
	} while (1);

	printf("\n");
	
	return OK;
}

void Output_table(SSTable ST)
{
	int i;
	
	printf("顺序表为:\n");
	for (i = 1; i <= ST.length; i++) {
		printf("%4d\t", ST.R[i].key);
	}

	printf("\n\n");

	return ;
}

int Search_Seq(SSTable ST, KeyType key, int &count_1)
{
	int i;
	count_1 = 1;
	ST.R[0].key = key;

	for (i = ST.length; ST.R[i].key != key; --i) {
		count_1++;
	} 

	return i;
}

void Shou_End(int resule, int testkey)
{
	if (resule == 0) {
		printf("未找到%d\n", testkey);
	}

	else {
		printf("找到%d, 位置为%d\n", testkey, resule);
	}
	
	printf("比较次数为:%d\n\n", count_1);
	
	return ;
}

int main(void)
{
	SSTable ST;

	InitList_SSTable(ST);
	Create_SSTable(ST);
	Output_table(ST);

	int testkey;
	int resule;

	do {
		printf("请输入待查关键字, 输入'0'退出查找.\n");
		scanf("%d", &testkey);
		
		printf("\n");

		resule = Search_Seq(ST, testkey, count_1);
		Shou_End(resule, testkey);
	} while (testkey != 0);

	return 0;
}
