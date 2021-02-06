/*
	Name: 图书管理系统2.0程序头文件(单链表实现） 
	Copyright: 
	Author: 周吉瑞 
	Date: 20/04/20 12:55
	Description: 图书管理系统LinkList.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {
	
	char no[20];		// 图书ISBN  
	char name[50];		// 图书名字 
	float price;		// 图书价格 

} Book;					// 每本图书信息的结构类型为Book 

typedef struct LNode {
	
	Book data;				// 结点的数据域 
	struct LNode *next;		// 结点的指针域 
	
} LNode, *LinkList;			// LinkList为指向结构体LNode的指针类型

Status InitList_L(LinkList &L);							// 初始化单链表 
Status CreateList_L(LinkList &L, int n);				// 创建单链表 
Status ListLength_L(LinkList L, int &l);				// 求单链表表长 
Status LocateElem_L(LinkList L, char *b);				// 图书元素的查找 
Status ListInsert_L(LinkList &L, int i, Book e);		// 图书元素的插入 
Status GetElem_L(LinkList &L, char *b);					// 图书元素的取出 
Status PrintList_L(LinkList L);							// 顺序输出图书元素内容 
Status ScanfElem_L(Book &e);							// 图书元素的输入 

Status InitList_L(LinkList &L)	// 初始化单链表，构建一个空的单链表
{	
	L = new LNode;				// 生成新的头结点，用头指针L指向结点 
	if (!L) { 
		printf("InitList_L OVERFLOW!\n");
		exit(OVERFLOW);			// 头结点分配失败 
	}
		
	L->next = NULL;				// 头结点的指针域置空 
	
	return OK; 
}// InitList_L 

Status CreateList_L(LinkList &L, int n)		//创建单链表 
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
		
		if (!ListInsert_L(L, i + 1, e)) {
			printf("CreateList_L ERROR\n");
			return ERROR; 
		}
	}
	
	return OK;	
}// CreateList_L

Status ListLength_L(LinkList L, int &l)		// 求单链表表长	
{
	LNode *p;
	
	p = L->next;
	
	l = 0;
	while (p) {
		++l;
		p = p->next;
	}  
	
	return OK;
}// ListLength_L

Status LocateElem_L(LinkList L, char *b)		// 图书元素的查找
{
	LNode *p;
	
	for (p = L->next; p != NULL; p = p->next) {
		if (!strcmp(p->data.name, b)) {
			printf("查找成功！\n");
			printf("%-10s  ", p->data.no);
			printf("%-10s  ", p->data.name);
			printf("%-10f\n", p->data.price);
			return OK;
		}
	}
	
	printf("没有所查书籍！\n");
	return ERROR; 
}// LocateElem_L

Status ListInsert_L(LinkList &L, int i, Book e)		// 图书元素的插入
{
	LNode *p;
	LNode *s;
	int j = 0;
	
	p = L;
	
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}
	
	if (!p || (j > i - 1)) {
		if (i == 1) {
			s = new LNode;
			s->data = e;
			s->next = p->next;
			p->next = s;
		}
		
		printf("ListInsert_L ERROR\n");
		return ERROR;
	}
	
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	printf("插入成功！\n");
	return OK;
}// ListInsert_L

Status GetElem_L(LinkList &L, char *b)	// 图书元素的取出
{
	LNode *p;
	LNode *q;
	int i = 1;
	int j = 0;
	
	for (p = L->next; p != NULL; p = p->next) {
		if (!strcmp(p->data.name, b)) {
			q = L;
			
			while ((q->next) && (j < i - 1)) {
				q = q->next;
				++j;
			}
			
			if (!(q->next) || (j > i - 1)) {
				printf("GetElem_L ERROR\n");
				return ERROR;
			}
			
			q->next = p->next;
			
			delete p;
			
			printf("成功取出！\n");
			return OK;
		}
		++i;
	}
	
	printf("没有所要取出的书籍！\n");
	return ERROR; 
}//  GetElem_Sq	 

Status PrintList_L(LinkList L)	// 顺序输出图书元素内容
{
	printf("图书表库存为：\n");
	
	LNode *p;
	
	p = L->next;
	
	while (p) {
		printf("%-10s  ", p->data.no);
		printf("%-10s  ", p->data.name);
		printf("%-10f\n", p->data.price);
		
		p = p->next;	
	}
	
	return OK;	
}// PrintList_L 

Status ScanfElem_L(Book &e)		// 图书元素的输入
{
	printf("请输入书的ISBN：");
	scanf("%s", e.no);
		
	printf("请输入书的书名：");
	scanf("%s", e.name);
		
	printf("请输入书的价格：");
	scanf("%f", &e.price);
	
	return OK;	
}// ScanfElem_L 
