/*
	Name: 实验5  邻接矩阵.h
	Copyright: 
	Author: 20190521340 周吉瑞
	Date: 27/05/20 09:24
	Description: 头文件：无向网的邻接矩阵表示法
*/
#include <stdio.h>
#include <iostream>
using namespace std;

#define MaxInt 32767                    	//表示极大值，即∞
#define MVNum 100                       	//最大顶点数
#define OK 1
#define ERROR 0
#define OVERFLOW -2 

typedef int Status;
typedef char VerTexType;              		//假设顶点的数据类型为字符型
typedef int ArcType;                  		//假设边的权值类型为整型

//- - - - -图的邻接矩阵存储表示- - - - -
typedef struct {
	VerTexType vexs[MVNum];            		//顶点表
	ArcType arcs[MVNum][MVNum];      		//邻接矩阵
	int vexnum, arcnum;                		//图的当前点数和边数
} AMGraph;

int LocateVex(AMGraph G , VerTexType v);	//确定点v在G中的位置
Status CreateUDN(AMGraph &G);    				//采用邻接矩阵表示法，创建无向网G
void  PrtAMGraph(AMGraph G);  				//输出邻接矩阵
int Degree(AMGraph G, int k);  				//求第k个顶点的度

int LocateVex(AMGraph G , VerTexType v)
{
	//确定点v在G中的位置
	for (int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
	return -1;
}//LocateVex

Status CreateUDN(AMGraph &G)
{
    //采用邻接矩阵表示法，创建无向网G
	int i , j , k;
	cout << "请输入总顶点数，总边数，以空格隔开：";
    cin >> G.vexnum >> G.arcnum;	//输入总顶点数，总边数
	cout << endl;
	cout << "输入点的名称，如a" << endl;
	for (i = 0; i < G.vexnum; ++i) {
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vexs[i];         	//依次输入点的信息
	}
	cout << endl;
	for (i = 0; i < G.vexnum; ++i) {  	
	//初始化邻接矩阵，边的权值均置为极大值MaxInt
		for(j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	}
	cout << "输入边依附的顶点及权值，如 a b 5" << endl;
	for (k = 0; k < G.arcnum; ++k) {	//构造邻接矩阵
		VerTexType v1 , v2;
		ArcType w;
		cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
		cin >> v1 >> v2 >> w;			//输入一条边依附的顶点及权值
		i = LocateVex(G, v1);  
		j = LocateVex(G, v2);		
		//确定v1和v2在G中的位置，即顶点数组的下标
		G.arcs[i][j] = w;				//边<v1, v2>的权值置为w
		G.arcs[j][i] = G.arcs[i][j];	//置<v1, v2>的对称边<v2, v1>的权值为w
	}//for
	return OK;
}//CreateUDN

void  PrtAMGraph(AMGraph G)  //输出邻接矩阵
{
	int i,j;
	for (i = 0 ; i < G.vexnum ; ++i) {
		for (j = 0; j < G.vexnum; ++j) {
			if (G.arcs[i][j] != MaxInt)
				cout << G.arcs[i][j] << "\t";
			else
				cout << "∞" << "\t";
		}//for j
		cout << endl;
 	}//for i
	cout << endl;
}//Ptrgraph

int Degree(AMGraph G, int k) //求第k个顶点的度
{ 
	int j, d = 0;
	for (j = 0; j < G.vexnum; ++j) {
		if (G.arcs[k][j] != MaxInt)
			d = d + G.arcs[k][j];
	}
	return d;
}//Degree
