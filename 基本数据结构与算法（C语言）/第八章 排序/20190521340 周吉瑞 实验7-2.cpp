/*
	Name: 实验7-2 排序 
	Copyright:
	Author: 20190521340 周吉瑞 
	Date: 2020/07/08 8:30 AM
	Description: 各种排序方法的比较（加入希尔排序） 
*/

#include <stdio.h>
#define MAXSIZE 100

typedef int keytype;
typedef char anytype;

typedef struct {
	keytype key;
	anytype otherinfo;
}ElemType;

typedef struct {
	ElemType r[MAXSIZE+1];
	int length;
}SqList;

void prt(SqList L, int low, int high) 
{ 
	int i;
	for (i = low; i <= high; i++)
    printf("%4d", L.r[i].key);
}

int InsertSort(SqList &L)
{
	int i, j, sum=0;
	
	for (i = 2; i <= L.length; ++i) {
		if (L.r[i].key < L.r[i-1].key) {
			L.r[0] = L.r[i];		
			L.r[i] = L.r[i-1];
      		for (j = i-2; L.r[0].key < L.r[j].key; --j) {	
			  	L.r[j+1] = L.r[j];	
				sum++;
			}//for 
            L.r[j+1] = L.r[0];         
   		}//if
   		
   		printf("第%2d趟:", i-1);
    	printf("{");
		prt(L, 1, i);
		printf("}");
  	 	prt(L, i+1, L.length);
		printf("\n");
    }//for	
    
	return sum;
}//InsertSort


int BubbleSort(SqList &L) 
{	
	int i, j, flag, n, sum=0;
	ElemType t;
	n = L.length;
	flag = 1; 		
	
	for (i=1; i<n && flag==1; i++) {
		flag = 0;		
		
    	for (j = 1; j <= n-i; j++) {
			if(L.r[j].key > L.r[j+1].key) {
				flag = 1;			
				t = L.r[j];
				L.r[j] = L.r[j+1];
				L.r[j+1] = t;	
				sum++;
			}//if	
		}//for 
		
		printf("第%2d趟:", i);
		prt(L, 1, L.length);
		printf("\n");
	}//for
	
    return sum;
}//BubbleSort

int SelectSort(SqList &L) 
{	
	int i, j, k, sum=0;
	ElemType t;
	
	for (i = 1; i < L.length; ++i) { 
		k = i;
		
   		for(j = i+1; j <= L.length; ++j) {
			sum++;
			if(L.r[j].key < L.r[k].key) {
				k = j;	
			}//if
  		}//for
  		
		if (k!=i) {
		t = L.r[i];
		L.r[i] = L.r[k];
		L.r[k] = t;
		}//if 
		
		printf("第%2d趟:", i);
		prt(L, 1, L.length);
		printf("\n");
	}//for
	
	return sum;
}//SelectSort

int ShellInsert(SqList &L, int dk)
{
	int i, j, sum=0;
	
	for (i = dk+1; i <= L.length; ++i) {
		
		if (L.r[i].key < L.r[i-dk].key) {
			L.r[0] = L.r[i];
			
			for (j = i-dk; j > 0 && (L.r[0].key < L.r[j].key); j-=dk) {
				L.r[j+dk] = L.r[j];
				++sum;
			}//for
			
			L.r[j+dk] = L.r[0];
		}//if
	}//for
	
	return sum;
}//ShellInsert

int ShellSort(SqList &L)
{
	int sum = 0;
	int k;
	int dk;
	int n = L.length;
	
	dk = n / 2;
	dk = (dk%2)? dk: dk+1;
	
	
	for (k = 1; dk > 0; dk/=2, ++k) {
		sum = sum + ShellInsert(L, dk);
		
		printf("第%2d趟:", k);
		prt(L, 1, L.length);
		printf("\n");
	}//for
	
	return sum;
}//ShellSort

void input(SqList &L)
{	
	int i;
 	keytype x;
 	
 	printf("\n请输入待排序的一组数据（不多于%d个）,以0表示结束:\n", MAXSIZE);
 	
	for (i=1; i<=MAXSIZE; i++) {
		scanf("%d", &x);
    	if (x == 0) {
			break;
		}//if
    	L.r[i].key = x;
    }//for
    
    L.length = i - 1;
}//input

void copy(SqList L1, SqList &L2)   
{ 
	int i;
	
	for (i=0; i<=L1.length; i++) {
    	L2.r[i] = L1.r[i];
    }//for
    
    L2.length = L1.length;
}//copy

int main()
{ 	
	int i, j, n, len1, len2, len3, len4;
  	keytype x;
  	SqList L, L1;
  	
	input(L);
	n = L.length;
  	copy(L, L1);  
	 
 	printf("\n1.直接插入排序：\n");
	printf("\n排序前元素序列为：\n        ");
    prt(L, 1, L.length);
	printf("\n");
    len1 = InsertSort(L);
    printf("元素个数为%d个，移动次数为：%d\n", n, len1);

	copy(L1, L);
	printf("\n2.冒泡排序：\n");
	printf("\n排序前元素序列为：\n       ");
    prt(L, 1, L.length);
	printf("\n");
    len2 = BubbleSort(L);
    printf("元素个数为%d个，交换次数为：%d\n", n, len2);

   	copy(L1, L);
	printf("\n3.简单选择排序：\n");
    printf("\n排序前元素序列为：\n       ");
    prt(L, 1, L.length);
	printf("\n");
    len3 = SelectSort(L);
    printf("元素个数为%d个，比较次数为：%d\n", n, len3);
    
    copy(L1, L);
	printf("\n4.希尔排序：\n");
    printf("\n排序前元素序列为：\n       ");
    prt(L, 1, L.length);
	printf("\n");
    len4 = ShellSort(L);
    printf("元素个数为%d个，交换次数为：%d\n", n, len4);
    getchar();
    
    return 0;
}//main


