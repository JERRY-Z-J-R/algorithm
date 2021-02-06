/*
	Name: 实验5-2  main.cpp 
	Copyright: 
	Author: 201900521340 周吉瑞 
	Date: 27/05/20 10:28
	Description: 深度优先搜索遍历连通图的递归算法（邻接矩阵存储）
*/

#include "20190521340 周吉瑞 实验5 邻接矩阵.h"

bool visited[MVNum] = {false};					//访问标志数组，其初值为"false"
int FirstAdjVex(AMGraph G , int v);				//返回v的第一个邻接点
int NextAdjVex(AMGraph G, int v, int w);		//返回v相对于w的下一个邻接点

void DFS(AMGraph G, int v) 	//从第v个顶点出发递归地深度优先遍历图G
{  
	cout << G.vexs[v] << "    ";  
	visited[v] =  true;
	//访问第v个顶点，并置访问标志数组相应分量值为true
	int w;
	for (w = FirstAdjVex(G, v);  w >= 0;  w = NextAdjVex(G, v, w))  
	//依次检查v的所有邻接点w ，FirstAdjVex(G, v)表示v的第一个邻接点 
	//NextAdjVex(G, v, w)表示v相对于w的下一个邻接点，w≥0表示存在邻接点 
		if (!visited[w])
			DFS(G, w); //对v的尚未访问的邻接顶点w递归调用DFS
}//DFS

int FirstAdjVex(AMGraph G , int v) //求v的第一个未被访问过的邻接点
{
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (G.arcs[v][i] != MaxInt && visited[i] == false)
			return i;
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(AMGraph G , int v , int w) //v相对于w的下一个未被访问过的邻接点
{
	int i;
	for(i = w ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] != MaxInt && visited[i] == false)
			return i;
	}
	return -1;
}//NextAdjVex

int main()
{
	cout << "**深度优先搜索遍历连通图的递归算法**" << endl;
	AMGraph G; 
	CreateUDN(G);
	cout << endl;
	cout << "无向连通图G的邻接矩阵如下：" << endl ;
	PrtAMGraph(G);                     
	VerTexType c;
 	int i;
	do {
		cout << "请输入遍历连通图的起始点：";
		cin >> c;
		i = LocateVex(G , c);     //求顶点c的序号
    	if(i < 0)
			cout << "该点不存在，请重新输入！" << endl;
	} while (i < 0);
	
	cout << "深度优先搜索遍历连通图结果：" << endl;
	DFS(G, i);
	cout << endl;
	return 0;
}//main
