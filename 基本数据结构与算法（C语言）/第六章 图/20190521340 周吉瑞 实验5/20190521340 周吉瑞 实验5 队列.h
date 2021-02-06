/*
	Name: 实验5  队列.h 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 27/05/20 13:20
	Description: 头文件：队列 （链队） 
*/
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char VerTexType;
typedef int Status;

typedef struct QNode {
	VerTexType data;
	struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr front;		//队头指针 
	QueuePtr rear;		//队尾指针 
} LinkQueue;

Status InitQueue(LinkQueue &Q)	//构造一个空队列Q 
{
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue &Q, VerTexType e)	//插入元素e为Q的新队尾元素 
{
	QNode *p;
	p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK; 	
}

Status DeQueue(LinkQueue &Q, VerTexType &e)	//删除Q的队头元素，用e返回其值
{
	QNode *p;
	if (Q.front == Q.rear)
		return ERROR; 
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) 
		Q.rear = Q.front;
	delete p;
	return OK;
}

Status QueueEmpty(LinkQueue Q)	//判断队列为空
{
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR; 
} 


 
