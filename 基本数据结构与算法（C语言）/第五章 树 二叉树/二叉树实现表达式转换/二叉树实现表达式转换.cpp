#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char TElemType;

typedef struct  BiTNode {

	TElemType data;
	struct BiTNode *lchild, *rchild;
	
}BiTNode, *BiTree;

Status CreateBiTree(BiTree &T);		// 先序遍历创建二叉树
Status InOrderTraverse(BiTree T);	// 中序遍历二叉树并输出
Status PostTraverse(BiTree T);		// 后序遍历二叉树并输出

int main(void)
{
	BiTree T;

	printf("请输入算术表达式的前缀式：\n");
	printf("注意：空用'#'表示\n");

	CreateBiTree(T);
	
	printf("\n表达式的中缀式为：\n\n");
	InOrderTraverse(T);
	printf("\n表达式的后缀式为：\n\n");
	PostTraverse(T);

	system("pause");
	return 0;
}// main

Status CreateBiTree(BiTree &T)		// 先序遍历创建二叉树
{
	char ch;
	cin >> ch;

	if (ch == '#')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}

	return OK;
} // CreateBiTree

Status InOrderTraverse(BiTree T)	// 中序遍历二叉树并输出
{
	if (T == NULL)
		return OK;
	else {
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}// InOrderTraverse

Status PostTraverse(BiTree T)		// 后序遍历二叉树并输出
{
	if (T == NULL)
		return OK;
	else {
		PostTraverse(T->lchild);
		PostTraverse(T->rchild);
		cout << T->data;
	}
}// PostTraverse



