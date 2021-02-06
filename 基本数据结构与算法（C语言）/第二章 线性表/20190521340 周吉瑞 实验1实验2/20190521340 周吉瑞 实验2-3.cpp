/*
	Name: 实验2-3 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 09/04/20 09:26
	Description: 阅读下面程序，在横线处填写欠缺内容，并补充函数的基本功能注释。
				运行程序，写出结果（运行截图）   
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;		/* 定义表元素的类型 */
typedef int Status; 		/* Status是函数返回值类型，其值是函数结果状态代码 */

typedef struct LNode { 		 /* 线性表的循环单链表存储 */

    ElemType data;		  	/* 结点的数据域 */ 
    struct LNode *next;		/* 结点的指针域 */ 
    
} LNode, *LinkList;

LinkList CreateList(int n); 				    /* 建立带头结点的循环单链表 */
Status PrintList(LinkList L); 				    /* 顺序输出单链表 */
Status GetElem(LinkList L, int i, ElemType &e); /* 取出单链表第i个值并用e返回其值 */

LinkList CreateList(int n) {					/* 创建单链表 */ 
    LNode *p, *q, *head;
    int i;
    
    head = new LNode;       
	head->next = head;
    p = head;
    
    for (i = 0; i < n; i++) {
    	q = new LNode;       
		printf("input data %i:",i+1);
    	scanf("%d", &(q->data));            /* 输入元素值 */
    	p->next = q;                       	/* 新结点连在表末尾 */
    	p = q;
	}
	
	q->next = head;
	                           
    return head;
}/*CreateList*/

Status PrintList(LinkList L)
{
    LNode *p;
    
    p = L->next;  /*p指向单链表的第1个元素*/
    
    while(p != L) {
        printf("p:%d  p->data:%d  p->next:%d\n", p, p->data, p->next);
        p = p->next;
	}
                        
    return OK;
}/*PrintList*/

Status GetElem(LinkList L, int i, ElemType &e)		/* 取出单链表第i个值并用e返回其值 */
{
    LNode *p;						
	int j = 1;						/* 计数器j初值赋为1 */ 
	
    p = L->next;					/* 初始化，p指向首元结点 */ 
    
    while (p != L && j < i) {        /* 顺链域向后扫描，直到p为空或p指向第i个元素 */              
        p = p->next;			/* p指向下一个结点 */
		++j;					/* 计数器j相应加1 */
    }
    
    if (p == L || j > i)			/* i值不合法i>n或i<=0 */
        return ERROR;           /* 取第i个结点的数据域 */     
		  
	e = p->data;
	                       
	return OK;
}/*GetElem*/

int main()
{
    int n, i;
	ElemType e;
	
    LinkList L = NULL;      /* 定义指向单链表的指针 */
    
    printf("please input n:");  /* 输入单链表的元素个数 */
    scanf("%d", &n);
    
    if (n > 0) {
        printf("\n1-Create LinkList:\n");	/* 创建单循环链表 */
        L = CreateList(n);      
		  
        printf("\n2-Print LinkList:\n");	/* 输出单链表 */ 
        PrintList(L);
		           
        printf("\n3-GetElem from LinkList:\n");		/* 单链表的取值 */ 
        printf("input i=");
        scanf("%d", &i);
        if (GetElem(L, i, e))     
            printf("No%i is %d", i, e);
        else
            printf("not exists\n");
    }
    
	else
        printf("ERROR\n");
        
    return 0;
}

