/*
	Name: 实验1-2 
	Copyright: 
	Author: 20190521340 周吉瑞  
	Date: 07/04/20 22:03
	Description: 调试程序：对一维数组中的元素进行逆序排列 
*/

#include <stdio.h>
#define N 10

int main()
{
	int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i;
	int temp;
	
	printf("\nthe original Array is:\n ");
	
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
		
	for (i = 0; i < N; i++) {		/*交换数组元素使之逆序*/
		temp = a[i];				/*中间值法*/
		a[i] = a[N-i-1];
		a[N-i-1] = temp;
	}
	
	printf("\nthe changed Array is:\n");
	
	for (i = 0; i < N; i++)
		printf("%4d", a[i]);

	return 0;
}

