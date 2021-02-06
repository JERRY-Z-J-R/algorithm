/*
	Name: 实验2-2
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 08/04/20 23:24
	Description: 阅读下面程序，在横线处填写欠缺内容，并补充函数的基本功能注释。运行程序，写出结果（运行截图） 
				为实验2-1补充删除和查找功能函数，并在主函数中补充代码，验证这两个函数的正确性，写出结果（运行截图） 
*/

#include <stdio.h>
#include <malloc.h>
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
Status ListInsert_sq(SqList &L, int i, ElemType e);		/* 顺序表的第i个位置之前插入元素e */
Status PrintList_sq(SqList L);  		/*输出顺序表的元素*/
Status ListDelete_sq(SqList &L, int i);	 /*删除第i个元素*/
int ListLocate_sq(SqList L, ElemType e);	 	/*查找值为e的元素*/

Status InitList_sq(SqList &L) 	 //算法2.1 顺序表的初始化(构造一个空的顺序表L)
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

/*输出顺序表中的元素*/
Status PrintList_sq(SqList L) 
{
    int i;
    for (i = 1; i <= L.length; i++)
        printf("%5d", L.elem[i-1]);
        
    return OK;
}/*PrintList*/

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

/*在顺序表中删除第i个元素,并用e返回其值，i值的合法范围是1<=i<=L.length */
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
	if ((i < 1) || (i > L.length)) {
		printf("ERROR\n"); 
		return ERROR;  //i值不合法
	}   
	 
	e = L.elem[i - 1];	
	
	for (int j = i; j <= L.length; j++)
		L.elem[j-1] = L.elem[j];  //被删除元素之后的元素前移
		    
	--L.length;      //表长减1
	
	return OK;
}

/*在顺序表中查找指定值元素，返回其序号*/
int ListLocate_sq(SqList L, ElemType e)
{  
	for (int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;     //查找成功，返回序号i+1
	
	printf("There is no the element.\n")	;	
	return 0;     //查找失败，返回0
}

int main()
{
    SqList sl;
    int n;
	int m, k;
	int i, e;
	int x;
    
    printf("please input n:");  /*输入顺序表的元素个数*/
    scanf("%d", &n);
    
    if (n > 0 && n <= 100) {
        printf("\n1-Create SqList:\n");
        InitList_sq(sl);		/*顺序表的初始化(构造一个空的顺序表L)*/
        
        CreateList_sq(sl, n);		/* 创建顺序表(顺序输入数据元素) */
        
        printf("\n2-Print SqList:\n");
        PrintList_sq(sl);		/*输出顺序表*/
		 
        printf("\nplease input insert location and data:(location,data)\n");
	    scanf("%d,%d", &m, &k);
	    ListInsert_sq(sl, m, k);		/* 顺序表的第m个位置之前插入元素k */
	    
	    printf("\n3-Print SqList:\n");
	    PrintList_sq(sl);		/*输出顺序表*/	
	    
	    printf("\nplease input delete elem's location:");		/*在顺序表中删除第i个元素,并用e返回其值*/
	    scanf("%d", &i);
	    ListDelete_Sq(sl, i, e);
	    if (ListDelete_Sq(sl, i, e))
	    	printf("delete elem is: %d\n", e);
	    
	    printf("\n4-Print SqList:\n");
	    PrintList_sq(sl);		/*输出顺序表*/	
	    
	    printf("\nplese input locate element:");	/*在顺序表中查找指定值元素，返回其序号*/
	    scanf("%d", &x);
	    if (ListLocate_sq(sl, x))
	    	printf("The element is top %d\n", ListLocate_sq(sl, x));
	    
	    
    }
    else
        printf("ERROR\n");
        
    return 0;
}

