/*
	Name: 实验5-3  main.cpp 
	Copyright: 
	Author: 201900521340 周吉瑞 
	Date: 27/05/20 14:28
	Description: 深度优先搜索遍历连通图的递归算法（邻接表存储）
*/

#include "20190521340 周吉瑞 实验5 邻接表.h"

bool visited[MVNum] = {false};	//访问标志数组，其初值为"false"

void DFS_AL(ALGraph G, int v)	//图G为邻接表类型，从第v个顶点出发深度优先搜索遍历 
{
	ArcNode *p;
	int w;
	cout << G.vertices[v].data << "    ";
	visited[v] = true;
	p = G.vertices[v].firstarc;
	while (p != NULL) {
		w = p->adjvex;
		if (!visited[w])
			DFS_AL(G, w);
		p = p->nextarc;
	}
}

int main()
{
	cout << "**深度优先搜索遍历连通图的递归算法**" << endl;
	ALGraph G; 
	CreateUDG(G);
	cout << endl;
	cout << "无向连通图G的邻接表如下：" << endl ;
	PrtALGraph(G);                     
	VerTexType c;
 	int i;
	do {
		cout << "请输入遍历连通图的起始点：";
		cin >> c;
		i = LocateVex(G, c);     //求顶点c的序号
    	if(i < 0)
			cout << "该点不存在，请重新输入！" << endl;
	} while (i < 0);
	
	cout << "深度优先搜索遍历连通图结果：" << endl;
	DFS_AL(G, i);
	cout << endl;
	return 0;
}//main
