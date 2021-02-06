/*
	Name: 实验2-5 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 10/04/20 14:01
	Description: 利用顺序表实现两个集合AB的并集（A = A U B) 
*/

#include <stdio.h>
#include <stdlib.h> 

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 100     /*初始分配的顺序表长度*/

typedef int ElemType;   /*定义表元素的类型*/
typedef int Status;		/*函数返回值类型，其值是函数结果状态码*/ 

typedef struct {
	
	ElemType *elem;		//存储空间的基地址
	int length;		//当前长度
	
} SqList;

Status InitList_sq(SqList &L);	 	/*顺序表的初始化(构造一个空的顺序表L)*/
Status CreateList_sq(SqList &L, int n);	 /* 创建顺序表(顺序输入数据元素) */
Status PrintList_sq(SqList L);  		/*输出顺序表的元素*/
Status MergeList_sq(SqList &LA, SqList LB, int n, int m);	/* 线性表LA LB的合并 */
Status ListInsert_sq(SqList &L, int i, ElemType e);		/* 顺序表的第i个位置之前插入元素e */
Status GetElem_sq(SqList L, int i, ElemType &e);		/* 顺序表的取值 */
int ListLocate_sq(SqList L, ElemType e);	 	/*查找值为e的元素*/

Status InitList_sq(SqList &L) 	 // 顺序表的初始化(构造一个空的顺序表L)
{	
	L.elem = new ElemType[MAXSIZE];
 	//为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem) {
		printf("OVERFLOW\n");
		exit(OVERFLOW); //存储分配失败退出 
	}
	
	L.length = 0; //空表长度为0
	
	return OK;
}/*InitList*/


Status CreateList_sq(SqList &L, int n)
{
    ElemType e;
    
    int i;
    for (i = 0; i < n; i++) {
        printf("input data %d: ", i + 1);
        scanf("%d", &e);
        
        if (!ListInsert_sq(L, (i + 1), e)) {
			printf("ERROR\n");
            return ERROR;
    	}
    }
    
    return OK;
}/*CreateList*/

/* 输出顺序表中的元素 */
Status PrintList_sq(SqList L) 
{
    int i;
    for (i = 1; i <= L.length; i++)
        printf("%5d", L.elem[i-1]);
        
    return OK;
}/*PrintList*/

Status MergeList_sq(SqList &LA, SqList LB, int n, int m)	/* 线性表LA LB的合并 */
{
	/* 将所有在线性表LB中但不在LA中的数据元素插入到LA中 */
	int e;
	
	for (int i = 1; i <= m; i++) {
	 	GetElem_sq(LB, i, e);
	 	if (!ListLocate_sq(LA, e))
	 		ListInsert_sq(LA, ++n, e);
	}
	
	return OK;
}/*MergeList_sq*/

Status ListInsert_sq(SqList &L, int i, ElemType e)
{
    int k;
    
	if (i < 1 || i > (L.length + 1)) {
		printf("ERROR\n");
		return ERROR;
	}
		    
	if (L.length >= MAXSIZE) {
		printf("ERROR\n");
		return ERROR; 
	}
	
    for (k = (L.length - 1); k >= (i - 1); k--)         
        L.elem[k+1] = L.elem[k];

    L.elem[i-1] = e;
	                     
    ++L.length;
	                                 
    return OK;
}/*ListInsert*/

/*在顺序表中查找指定值元素，返回其序号*/
int ListLocate_sq(SqList L, ElemType e)
{  
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;     //查找成功，返回序号i+1
	
	return 0;     //查找失败，返回0
}/*ListLocate*/

Status GetElem_sq(SqList L, int i, ElemType &e)
{
	if (i < 1 || i > L.length)
		return ERROR;
		
	e = L.elem[i - 1];
	
	return OK;
}/*GetElem*/

int main()
{
    SqList LA, LB;
    int n, m;
    
    printf("please input LA(n):");  /* 输入顺序表LA的元素个数 */
    scanf("%d", &n);
    
    printf("please input LB(m):");  /* 输入顺序表的LB元素个数 */
    scanf("%d", &m);
    
    
    if ((n && m) > 0 && (n && m) <= 100) {
        printf("\nCreate SqList(LA)):\n");
        InitList_sq(LA);		/*顺序表的初始化(构造一个空的顺序表LA)*/
        
        CreateList_sq(LA, n);		/* 创建顺序表LA(顺序输入数据元素) */
        
        printf("\nPrint SqList(LA):\n");
        PrintList_sq(LA);		/*输出顺序表LA*/
        
        printf("\nCreate SqList(LB):\n");
        InitList_sq(LB);		/*顺序表的初始化(构造一个空的顺序表LB)*/
        
        CreateList_sq(LB, m);		/* 创建顺序表LB(顺序输入数据元素) */
        
        printf("\nPrint SqList(LB):\n");
        PrintList_sq(LB);		/*输出顺序表LB*/
        
        MergeList_sq(LA, LB, n, m);	/* 线性表LA LB的合并 */
        
        printf("\nPrint SqList(LA U LB):\n");
        PrintList_sq(LA);		/*输出顺序表LA = LA U LB*/
    }
    else
        printf("ERROR\n");
        
    return 0;
}

