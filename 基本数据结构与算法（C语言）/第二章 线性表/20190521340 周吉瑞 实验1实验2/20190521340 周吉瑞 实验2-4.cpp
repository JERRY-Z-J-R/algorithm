/*
	Name: 实验2-4
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 09/04/20 19:30
	Description: 阅读下面程序，在横线处填写欠缺内容，并补充函数的基本功能注释。
				运行程序，写出结果（运行截图）
				为第3题补充插入功能函数和删除功能函数。
				并在主函数中补充代码,验证这两个函数的正确性
*/

#include <stdio.h>
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

LinkList CreateList(int n); 				   		 /* 建立带头结点的循环单链表 */
Status PrintList(LinkList L); 				    	 /* 顺序输出单链表 */
Status GetElem(LinkList L, int i, ElemType &e); 	 /* 取出单链表第i个值并用e返回其值 */
Status ListDelete(LinkList &L, int i, ElemType &e);	 /* 在带头结点的单链表L中，删除第i个位置,并用e返回被删元素 */
Status ListInsert(LinkList &L, int i, ElemType e);	 /* 在带头结点的单链表L中第i个位置插入值为e的新结点 */
LNode * LocateElem(LinkList L, ElemType e);			 /* 单链表按值e查找 */

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
}/* CreateList */

Status PrintList(LinkList L)
{
    LNode *p;
    
    p = L;				/* p指向单链表的头结点 */  
    p = p->next;		/* p指向单链表的第1个元素 */
    
    while(p != L) {		/* while循环直到p指向头结点时退出循环 */ 
        printf("p:%d  p->data:%d  p->next:%d\n", p, p->data, p->next);
        p = p->next;	/* p指向下一个结点 */
	}
                        
    return OK;
}/* PrintList */

Status GetElem(LinkList L, int i, ElemType &e)		/* 取出单链表第i个值并用e返回其值 */
{
    LNode *p;						
	int j = 1;						/* 计数器j初值赋为1 */ 
	
    p = L->next;					/* 初始化，p指向首元结点 */ 
    
    while (p != L && j < i) {        /* 顺链域向后扫描，直到p为空或p指向第i个元素 */              
        p = p->next;			/* p指向下一个结点 */
		++j;					/* 计数器j相应加1 */
    }
    
    if (p == L || j > i) {			/* i值不合法i>n或i<=0 */
    	printf("ERROR\n");
        return ERROR;           /* 取第i个结点的数据域 */    
	}
		  
	e = p->data;
	                       
	return OK;
}/* GetElem */

Status ListDelete(LinkList &L, int i, ElemType &e)	/* 在带头结点的单链表L中，删除第i个位置,并用e返回被删元素 */
{
	LNode *p, *q;
    int j;
    
    p = L;
	j = 0;
	
    while ((p->next != L) && j < i - 1) {		/* 查找第i-1个结点，p指向该结点 */
    	p = p->next;
      	++j;
	}
	 
 	if (p->next == L || (j > i - 1)) {		/* i值不合法 */ 
 		if (i == 1) {
 			q = p->next;							/* 临时保存被删结点的地址以备释放 */
 			p->next = q->next; 						/* 改变删除结点前驱结点的指针域 */ 
 			e = q->data;  							/* 用e保存被删结点数据域 */ 
 			delete q; 								/* 释放删除结点的空间 */ 
 
    		return OK;		
		}
		
 		printf("ListDeleteERROR\n");
  		return ERROR; 
	}
		     
 	q = p->next;							/* 临时保存被删结点的地址以备释放 */
 	p->next = q->next; 						/* 改变删除结点前驱结点的指针域 */ 
 	e = q->data;  							/* 用e保存被删结点数据域 */ 
 	delete q; 								/* 释放删除结点的空间 */ 
 
    return OK;
}/* ListDelete */ 

Status ListInsert(LinkList &L, int i, ElemType e)	/* 在带头结点的单链表L中第i个位置插入值为e的新结点 */
{
    int j;
	LNode *p, *s; 
	
    p = L;
	j = 0;
	
    while (j < i - 1) {
    	p = p->next;  					/* 查找第i-1个结点，p指向该结点 */
    	++j;
	}
	
    if (p == L || j > i - 1) {
    	if (i == 1) {
    		s = new LNode; 						/* 生成新结点*s */ 
  			s->data = e;              			/* 将结点*s的数据域置位e */ 
  			s->next = p->next;      			/* 将结点*s的指针域指向结点ai */ 
  			p->next = s;						/* 将结点*p的指针域指向结点*s */ 
  	
  			return OK;	
		}	
		printf("ListInsertERROR\n");
  		return ERROR;
	}
  		
  	s = new LNode; 						/* 生成新结点*s */ 
  	s->data = e;              			/* 将结点*s的数据域置位e */ 
  	s->next = p->next;      			/* 将结点*s的指针域指向结点ai */ 
  	p->next = s;						/* 将结点*p的指针域指向结点*s */ 
  	
  	return OK;
}/* ListInsert */ 

LNode * LocateElem(LinkList L, ElemType e, int &n)		 /* 单链表按值e查找 */
{
	LNode *p;
	n = 1;
	
	p = L->next;		/* 初始化，p指向首元结点 */ 
	
	while (p != L  && p->data != e) {		/* 顺链域向后扫描，直到p为空或p所指结点的数据域等于e */
		p = p->next;				/* p指向下一个结点 */
		n++;
	}

	return p;						/* 查找成功返回值为e的结点地址p，查找失败p为L(头结点地址) */ 
}/* LocateElem */




int main()
{
    int n, i;
	ElemType e;
	int m, k;
	
    LinkList L = NULL;      /* 定义指向单链表的指针 */
    
    printf("please input n:");  /* 输入单链表的元素个数 */
    scanf("%d", &n);
    
    if (n > 0) {
        printf("\n1-Create LinkList:\n");	/* 创建单循环链表 */
        L = CreateList(n);      
		  
        printf("\n2-Print LinkList:\n");	/* 输出单链表 */ 
        PrintList(L);
		           
        printf("\n3-GetElem from LinkList:\n");		/* 单链表的取值 */ 
        printf("input i=");					/* 输入须要取出的元素序号 */ 
        scanf("%d", &i);
        if (GetElem(L, i, e))     
            printf("No%i is %d", i, e);
        else
            printf("not exists\n");
            
        printf("\n4-please input insert location and data:(location,data)\n");
	    scanf("%d,%d", &m, &k);
	    ListInsert(L, m, k);		/* 单链表的第m个位置之前插入元素k */
	    
	    printf("\n5-Print LinkList:\n");	/* 输出单链表 */ 
        PrintList(L);
        
        printf("\n6-please input delete elem's location:");		/* 在单链表表中删除第x个元素,并用y返回其值 */
	    scanf("%d", &i);
	    if (ListDelete(L, i, e));
			printf("delete elem is: %d\n", e);
	    	
	    printf("\n7-Print LinkList:\n");	/* 输出单链表 */ 
        PrintList(L);
        
        printf("\n8-please input LocateElem:");
        scanf("%d", &e); 
        if (LocateElem(L, e, n) == L)
        	printf("NO\n");
        else
        	printf("address:%d   No%d\n", LocateElem(L, e, n), n);
    }
    
	else
        printf("ERROR\n");
        
    return 0;
}

