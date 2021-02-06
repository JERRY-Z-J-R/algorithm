/*
	Name: 学生备忘录系统程序头文件(单链表） 
	Copyright: ...
	Author: 周吉瑞 
	Date: ...
	Description: 学生备忘录系统 LinkList.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {
	
	char id[15];			// 学生学号
	char name[15];			// 学生姓名 

} Student;					// 每个学生信息的结构类型为Student 

typedef struct Lidde {
	
	Student data;			// 结点的数据域 
	struct Lidde *next;		// 结点的指针域 
	
} Lidde, *LinkList;			// LinkList为指向结构体Lidde的指针类型

Status InitList_L(LinkList &L);							// 初始化单链表 
Status CreateList_L(LinkList &L, int n);				// 创建单链表 
Status ListLength_L(LinkList L, int &l);				// 求单链表表长 
Status LocateElem_L(LinkList L, char *b);				// 学生元素的查找 
Status ListInsert_L(LinkList &L, int i, Student e);		// 学生元素的插入 
Status GetElem_L(LinkList &L, char *b);					// 学生元素的移出 
Status PrintList_L(LinkList L);							// 顺序输出学生备忘录内容 
Status ScanfElem_L(Student &e);							// 学生元素的输入 
Status ForeverStudent_ZhouJiRui(LinkList &L);			// 初始化我自己

Status ForeverStudent_ZhouJiRui(LinkList &L)
{
	Student zjr;
	
	strcpy(zjr.id, "20190521340");
	strcpy(zjr.name, "周吉瑞");
	
	ListInsert_L(L, 1, zjr);
	
	return OK;
}// Status ForeverStudent_ZhouJiRui
 
Status InitList_L(LinkList &L)	// 初始化单链表，构建一个空的单链表
{	
	L = new Lidde;				// 生成新的头结点，用头指针L指向结点 
	
	if (!L) { 
		printf("\nInitList_L OVERFLOW!\n");
		exit(OVERFLOW);			// 头结点分配失败 
	}// if
		
	L->next = NULL;				// 头结点的指针域置空 
	
	return OK; 
}// InitList_L 

Status CreateList_L(LinkList &L, int n)		// 创建单链表 
{
	Student e;
	int i;
	
	for (i = 0; i < n; ++i) {
		printf("请输入第%d个学生的学号：", i + 1);
		scanf("%s", e.id);
		
		printf("请输入第%d个学生的姓名：", i + 1);
		scanf("%s", e.name);
		
		if (!ListInsert_L(L, i + 1, e)) {
			printf("\nCreateList_L ERROR!\n");
			return ERROR; 
		}// if
	}// for
	
	return OK;	
}// CreateList_L

Status ListLength_L(LinkList L, int &l)		// 求单链表表长	
{
	Lidde *p;
	
	p = L->next;
	
	l = 0;
	
	while (p) {
		++l;
		p = p->next;
	}// while
	
	return OK;
}// ListLength_L

Status LocateElem_L(LinkList L, char *b)		// 学生元素的查找
{
	Lidde *p;
	
	for (p = L->next; p != NULL; p = p->next) {
		if (!strcmp(p->data.name, b)) {
			printf("\n查找成功！\n");
			printf("%-10s  ", p->data.id);
			printf("%-10s  ", p->data.name);
			
			return OK;
		}// if
	}// for
	
	printf("\n没有所查学生！");
	return ERROR; 
}// LocateElem_L

Status ListInsert_L(LinkList &L, int i, Student e)		// 学生元素的插入
{
	Lidde *p;
	Lidde *s;
	int j = 0;
	
	p = L;
	
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}// while
	
	if (!p || (j > i - 1)) {
		if (i == 1) {
			s = new Lidde;
			s->data = e;
			s->next = p->next;
			p->next = s;
		}// if
		
		printf("\nListInsert_L ERROR!\n");
		return ERROR;
	}// if
	
	s = new Lidde;
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	printf("\n添加成功！\n");
	return OK;
}// ListInsert_L

Status GetElem_L(LinkList &L, char *b)	// 学生元素的移出 
{
	Lidde *p;
	Lidde *q;
	int i = 1;
	int j = 0;
	
	for (p = L->next; p != NULL; p = p->next) {
		if (!strcmp(p->data.name, b)) {
			q = L;
			
			while ((q->next) && (j < i - 1)) {
				q = q->next;
				++j;
			}// while
			
			if (!(q->next) || (j > i - 1)) {
				printf("\nGetElem_L ERROR!\n");
				return ERROR;
			}// if
			
			q->next = p->next;
			
			delete p;
			
			printf("\n成功移出！\n");
			return OK;
		}// if
		++i;
	}// for
	
	printf("\n没有所要移出的学生！\n");
	return ERROR; 
}//  GetElem_Sq	 

Status PrintList_L(LinkList L)	// 顺序输出学生备忘录内容
{
	printf("当前备忘录：\n\n");
	
	Lidde *p;
	
	p = L->next;
	
	while (p) {
		printf("%-10s  ", p->data.id);
		printf("%-10s  \n", p->data.name);
		
		p = p->next;	
	}// while
	
	return OK;	
}// PrintList_L 

Status ScanfElem_L(Student &e)		// 学生元素的输入
{
	printf("请输入学生的学号：");
	scanf("%s", e.id);
		
	printf("请输入学生的姓名：");
	scanf("%s", e.name);
	
	return OK;	
}// ScanfElem_L 
