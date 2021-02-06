/*
	Name: 实验1-4(2) 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 07/04/20 23:20
	Description: 调试程序：利用指针输出二维数组的元素
*/

#include<stdio.h>

int main()
{
	int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
	int *p;
	int i;
	
	for (p = a[0]; p < a[0] + 12; p++){	/*标准输出*/
		if ((p - a[0]) % 4 == 0)
			printf("\n");
		printf("%4d", *p);
	}
	
	printf("\n------------");
	
	for (p = a[0]; i < 4; i++)	/*行列互换输出*/
		printf("\n%4d%4d%4d", *(p + i), *(p + i + 4), *(p + i + 8)); 
	
	return 0;
}

