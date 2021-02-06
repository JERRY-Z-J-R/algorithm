/*
	Name: 实验1-2(2)
	Copyright: 
	Author: 20190521340 周吉瑞  
	Date: 07/04/20 22:12
	Description: 调试程序：对一维数组中的元素进行逆序排列 
*/

#include <stdio.h>
#define N 10

int main()
{
	int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[N];	/*定义一个用来与a进行元素交换的数组*/
	int i;
	
	printf("\nthe original Array is:\n ");
	
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
		
	for (i = 0; i < N; i++)		/*交换数组元素使之逆序*/ 
		b[i] = a[N-i-1];
		
	for (i = 0; i < N; i++)		/*将b数组的元素赋给a数组*/
		a[i] = b[i];
	
	printf("\nthe changed Array is:\n");
	
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);

	return 0;
}

