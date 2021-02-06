/*
	Name: 实验5-1  main.cpp
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 27/05/20 09:24
	Description: 采用邻接矩阵表示法创建无向网并输出和统计各个结点的度
*/
#include "20190521340 周吉瑞 实验5 邻接矩阵.h"

int main()
{
	cout << "****采用邻接矩阵表示法创建无向网****" << endl ;
	AMGraph G;
	CreateUDN(G);
	cout << endl;
	cout << "该图的邻接矩阵如下：" << endl;
  	PrtAMGraph(G);
	cout << endl << "*****各个顶点的度：*****" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		printf("第%d个顶点 %c 的度：%d\n", i, G.vexs[i] , Degree(G,i));
	} 
	return 0;
}//main
