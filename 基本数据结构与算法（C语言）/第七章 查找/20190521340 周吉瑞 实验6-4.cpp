/*
	Name: 20190521340 周吉瑞 实验6-4 
	Copyright: 
	Author: 周吉瑞 
	Date: 26/06/20 08:50
	Description: 二叉树表的查找 
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1;
#define ERROR 0;
#define OVERFLOW -2;

typedef int Status;
typedef int KeyType;

typedef struct {
	KeyType key;
	char name;
} ElemType;

typedef struct  BSTNode {
	ElemType data;
	struct  BSTNode *lchild, *rchild;		
} BSTNode, *BSTree;

void InsertBST(BSTree &T, ElemType e);
void CreatBST(BSTree &T);
void InOrder(BSTree T);
BSTree SearchBST(BSTree T, KeyType key);
void Shou_End(BSTNode *p);

int main(void)
{
	BSTree T;
	CreatBST(T);
	
	printf("printf BT:\n");
	InOrder(T);

	KeyType key;
	BSTNode *p = NULL;

	do {
		printf("\nSearchBST\n");
		printf("input '0' is SearchBST_end\n");

		printf("input key:");
		scanf("%d", &key);
		getchar();

		p = SearchBST(T, key);

		Shou_End(p);

	} while (key != 0);

	return 0;
}

void InsertBST(BSTree &T, ElemType e)
{
	BSTNode *S;
	
	if (!T) {
		S = new BSTNode;
		S->data = e;
		S->lchild = NULL;
		S->rchild = NULL;
		T = S;
	}

	else if (e.key < T->data.key) {
		InsertBST(T->lchild, e);
	}

	else if (e.key > T->data.key) {
		InsertBST(T->rchild, e);
	}

	return ;
} //InsertBST

void CreatBST(BSTree &T)
{
	ElemType e;
	
	T = NULL;

	printf("CreatBST '0' is end.\n");

	scanf("%d", &e.key);
	while (e.key != 0) {
		InsertBST(T, e);
		scanf("%d", &e.key);
	} //while 

	return ;
} //CreatBST

void InOrder(BSTree T)  
{
  if (T != NULL) {
 	InOrder(T->lchild);
 	printf("%d\t", T->data.key);
   	InOrder(T->rchild);
  }
} //InOrder

BSTree SearchBST(BSTree T, KeyType key)
{
	if ((!T) || key == T->data.key) {
		return T;
	}

	else if (key < T->data.key) {
		return SearchBST(T->lchild, key);
	}

	else {
		return SearchBST(T->rchild, key);
	}
} //SearchBST 

void Shou_End(BSTNode *p)
{
	if (p == NULL) {
		printf("NO!\n");
	}
	else {
		printf("YES!\n");
	}

	return ;
} //Shou_End


