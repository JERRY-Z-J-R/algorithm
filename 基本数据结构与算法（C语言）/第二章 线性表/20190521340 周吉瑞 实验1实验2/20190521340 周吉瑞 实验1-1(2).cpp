/*
	Name: 实验1-1(2) 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 07/04/20 21:32
	Description: 调试程序：输出100以内所有的素数（用函数实现） 
*/

#include <stdio.h>

int isprime(int n)	/*判断一个数是否为素数*/
{
	int m = 2;
	while (m < n) {
		if (n % m == 0)	/*可以与m整除*/
			return 0;
		++m;
	}
	
	return 1;
}

int main()	/*输出100以内所有素数*/
{
	int i;
	
	printf("\n");
	
	for (i = 2; i < 100; ++i) {	/*判断范围：2~~99*/
		if (isprime(i) == 1)
			printf("%4d", i);
	} 
	
	return 0;
}

