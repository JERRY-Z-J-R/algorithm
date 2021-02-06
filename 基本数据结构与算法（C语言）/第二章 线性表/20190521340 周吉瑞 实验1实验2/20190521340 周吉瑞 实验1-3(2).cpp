/*
	Name: 实验1-3(2)
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 07/04/20 22:30
	Description: 调试程序：在二维数组中，若某一位置上的元素在该行中最大，  
							而在该列中最小，则该元素即为该二维数组的一个鞍点。
							要求从键盘上输入一个二维数组，  
							当鞍点存在时，把鞍点找出来
*/

#include <stdio.h>
#define M 3
#define N 4

int main()
{
	int a[M][N];
	int i,j,k;
	int x,y;
	
	printf("\n请输入二维数组的数据：\n");
	
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
			
	printf("\n---------------\n"); 
			
	for (i = 0; i < M; i++) {		/*输出矩阵*/
		for (j = 0; j < N; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	
	for (i = 0; i < M; i++) {
		k = 0;
		for (j = 1; j < N; j++)	/*找出第i行的最大值*/
			if (a[i][j] > a[i][k])
				k = j;
		
		x = 0;
		for (y = 1; y < M; y++)	/*判断第i行的最大值是否为该列的最小值*/
			if (a[y][k] < a[x][k])
				x = y;
				
		if (i == x)			/*在第i行找到鞍点*/
			printf("鞍点:%d,  行:%d,  列:%d\n", a[i][k], i, k);
	}
	
	return 0;
}

