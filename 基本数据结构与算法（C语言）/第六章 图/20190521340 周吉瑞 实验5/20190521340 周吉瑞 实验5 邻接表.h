/*
	Name: 实验5  邻接表.h
	Copyright: 
	Author: 20190521340 周吉瑞
	Date: 27/05/20 13:24
	Description: 头文件：无向网的邻接表表示法
*/
#include <stdio.h>
#include <iostream>
using namespace std;

#define MVNum 100                       	//最大顶点数
#define OK 1
#define ERROR 0
#define OVERFLOW -2 

typedef int Status;
typedef char VerTexType;              		//假设顶点的数据类型为字符型
typedef int ArcType;                  		//假设边的权值类型为整型

//- - - - -图的邻接表存储表示- - - - -
typedef struct ArcNode {		//边结点 
	int adjvex;					//该边所指向的顶点的位置 
	struct ArcNode *nextarc;	//指向下一条边的指针 
	ArcType info;				//和边相关的信息 
} ArcNode;

typedef struct VNode {			//顶点信息 
	VerTexType data;
	ArcNode *firstarc;			//指向第一条依附该顶点的边的指针 
} VNode, AdjList[MVNum];		//AdjList表示邻接表类型 

typedef struct {				//邻接表 
	AdjList vertices;
	int vexnum, arcnum;			//图的当前顶点数和边数 
} ALGraph;

int LocateVex(ALGraph G, VerTexType v);
Status CreateUDG(ALGraph &G);
void  PrtALGraph(ALGraph G);

int LocateVex(ALGraph G, VerTexType v)
{
	//确定点v在G中的位置
	for (int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
	return -1;
}//LocateVex

Status CreateUDG(ALGraph &G)
{
    //采用邻接表表示法，创建无向网G
	int i , j , k;
	cout << "请输入总顶点数，总边数，以空格隔开：";
    cin >> G.vexnum >> G.arcnum;	//输入总顶点数，总边数
	cout << endl;
	cout << "输入点的名称，如a" << endl;
	for (i = 0; i < G.vexnum; ++i) {
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vertices[i].data;         	//依次输入点的信息
		G.vertices[i].firstarc = NULL;		//初始化表头结点的指针域为NULL 
	}
	cout << endl;
	cout << "输入边依附的顶点及权值，如 a b 5" << endl;
	for (k = 0; k < G.arcnum; ++k) {	//构造邻表 
		VerTexType v1 , v2;
		ArcType w;
		ArcNode *p1, *p2;
		cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
		cin >> v1 >> v2 >> w;			//输入一条边依附的顶点及权值
		i = LocateVex(G, v1);  
		j = LocateVex(G, v2);		
		//确定v1和v2在G中的位置，即顶点G.vertices中的序号
		p1 = new ArcNode;
		p1->adjvex = j;
		p1->info = w;					//边<v1, v2>的权值置为w
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
		//将新结点*p1插入顶点vi的边表头部
		p2 = new ArcNode;
		p2->adjvex = i;
		p2->info = w;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2; 
	}//for
	return OK;
}//CreateUDG

void  PrtALGraph(ALGraph G)  //输出邻接表 
{
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; ++i) {
		printf("%d %c", i, G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (1) {
			if (p != NULL) {
				printf(" -> [%d,%d]", p->adjvex, p->info);
				p =  p->nextarc;
			}
			else
				break;
		}
		cout << endl;	
	}
	
}//Ptrglaph
