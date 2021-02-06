/*
	Name: 图书管理系统程序头文件(顺序表实现） 
	Copyright: 
	Author: 周吉瑞 
	Date: 19/04/20 16:29
	Description: 图书管理系统SqList.h 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {
	
	char no[20];		// 图书ISBN  
	char name[50];		// 图书名字 
	float price;		// 图书价格 

} Book;					// 每本图书信息的结构类型为Book 

typedef struct {
	
	Book *elem;			// 存储空间基地址 
	int length;			// 图书表中当前图书个数
	 
} SqList;				// 图书表的顺序存储结构类型为SqList 

Status InitList_Sq(SqList &L);							// 初始化顺序表 
Status CreateList_Sq(SqList &L, int n);					// 创建顺序表 
Status ListLength_Sq(SqList L, int &l);					// 求顺序表表长 
Status LocateElem_Sq(SqList L, char *b);				// 图书元素的查找 
Status ListInsert_Sq(SqList &L, int i, Book e);			// 图书元素的插入 
Status GetElem_Sq(SqList &L, char *b);					// 图书元素的取出 
Status PrintList_Sq(SqList L);							// 顺序输出图书元素内容 
Status ScanfElem_Sq(Book &e);							// 图书元素的输入 

Status InitList_Sq(SqList &L)		// 初始化顺序表，构造一个空的顺序表 
{	
	L.elem = new Book[MAXSIZE];		// 为顺序表分配一个大小为MAXSIZE的结构体数组空间 
	if (!L.elem)					// 储存分配失败 
		exit(OVERFLOW);
	
	L.length = 0;					// 空表长度为0 
	
	return OK;
}// InitList_Sq

Status CreateList_Sq(SqList &L, int n)		// 创建顺序表 
{
	Book e;
	int i;
	
	for (i = 0; i < n; ++i) {
		printf("请输入第%d本书的ISBN：", i + 1);
		scanf("%s", e.no);
		
		printf("请输入第%d本书的书名：", i + 1);
		scanf("%s", e.name);
		
		printf("请输入第%d本书的价格：", i + 1);
		scanf("%f", &e.price);
		
		if (!ListInsert_Sq(L, i + 1, e)) {  	//将第i+1本书的信息插入图书表第i+1个元素处 
			printf("CreateList_Sq ERROR!\n");
			return ERROR;
		}
	} 
	
	return OK;
}// CreateList_Sq

Status ListLength_Sq(SqList L, int &l)		// 求顺序表表长	
{
	l = L.length;
	
	return OK;
}// ListLength_Sq 

Status LocateElem_Sq(SqList L, char *b)		// 图书元素的查找
{
	int i;
	
	for (i = 0; i < L.length; ++i) {
		if (!strcmp(L.elem[i].name, b)) {
			printf("查找成功！\n");
			printf("%-10s  ", L.elem[i].no);
			printf("%-10s  ", L.elem[i].name);
			printf("%-10f\n", L.elem[i].price);
			return OK;
		}
	}
	
	printf("没有所查书籍！\n");
	return ERROR; 
}// LocateElem_Sq

Status ListInsert_Sq(SqList &L, int i, Book e)		// 图书元素的插入
{
	if ((i < 1) || (i > MAXSIZE)) {
		printf("1_ListInsert_Sq ERROR!\n");
		return ERROR;
	}
	
	if (L.length == MAXSIZE) {
		printf("2_ListInsert_Sq ERROR!\n");
		return ERROR;
	}
	
	for (int j = L.length - 1; j >= i - 1; --j)
		L.elem[j+1] = L.elem[j];
		
	L.elem[i-1] = e;
	++L.length;
	
	printf("插入成功！\n"); 
	return OK;
}// ListInsert_Sq

Status GetElem_Sq(SqList &L, char *b)	// 图书元素的取出
{
	int i, j;
	
	for (i = 0; i < L.length; ++i) {
		if (!strcmp(L.elem[i].name, b)) {
			for (j = i; j < L.length - 1; ++j) {
				L.elem[j] = L.elem[j+1];
			}
			
			--L.length;
			printf("成功取出！\n");
			return OK;
		}
	}

	printf("没有所要取出的书籍！\n");
	return ERROR; 
}//  GetElem_Sq	
	
Status PrintList_Sq(SqList L)	// 顺序输出图书元素内容
{
	printf("图书表库存为：\n"); 
	
	int i;
	for (i = 1; i <= L.length; ++i) {
		printf("%-10s  ", L.elem[i-1].no);
		printf("%-10s  ", L.elem[i-1].name);
		printf("%-10f\n", L.elem[i-1].price);
	}	
	
	return OK;
}// PrintList_Sq 

Status ScanfElem_Sq(Book &e)	// 图书元素的输入
{
	printf("请输入书的ISBN：");
	scanf("%s", e.no);
		
	printf("请输入书的书名：");
	scanf("%s", e.name);
		
	printf("请输入书的价格：");
	scanf("%f", &e.price);
	
	return OK;
}// ScanfElem_Sq 
