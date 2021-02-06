/*
	Name: 实验4 
	Copyright: 
	Author: 20190521340 周吉瑞
	Date: 06/05/20 09:05
	Description: 二叉树的应用与实现
*/

#include <stdio.h>
#include <stdlib.h>

#define PRT printf("p=%8d  p->data=%c  p->lchild=%8d  p->rchild=%8d\n", p, p->data, p->lchild, p->rchild)

typedef struct BTNode {      /* 结点结构声明 */
	char data ;                /* 结点数据 */
	struct BTNode *lchild;
	struct BTNode *rchild ;    /* 指针 */
} *BiTree;

int createBiTree(BiTree &t)  /* 先序遍历创建二叉树 */
{
	char s;
	BiTree q;

	s = getchar();

	if (s == '.') {
    t = NULL; 
    return 1;
  }

	q = (BiTree)malloc(sizeof(struct BTNode));

	if (q == NULL) {
    printf("Memory alloc failure!\n");
    return 0;
  }

	q->data = s;
	t = q;

	createBiTree(q->lchild);  /* 递归建立左子树 */
	createBiTree(q->rchild);  /* 递归建立右子树 */

	return 1;
}/* createBiTree */

void PreOrder(BiTree p)     /* 先序遍历二叉树 */
{
  if (p != NULL) {
       PRT;
       PreOrder(p->lchild);
       PreOrder(p->rchild);
  }
}/* PreOrder */

void InOrder(BiTree p)      /* 中序遍历二叉树 */
{
  if (p != NULL) {
 	  InOrder(p->lchild);
   	PRT;
   	InOrder(p->rchild);
  }
}/* InOrder */

void PostOrder(BiTree p)    /* 后序遍历二叉树 */
{
  if (p != NULL) {
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    PRT;
  }
}/* PostOrder */

void release(BiTree t)      /* 释放二叉树空间 */
{
  if(t != NULL) {
    release(t->lchild);
    release(t->rchild);
    free(t);
  }
}/* release */

int nodenum(BiTree p)       /* 求二叉树结点数 */
{
  int n;

  if (p == NULL)
    return 0;
  else
    n = (nodenum(p->lchild) + nodenum(p->rchild) + 1);

  return n;
}/* nodenum */

int leafnum(BiTree p)       /* 求二叉树叶子结点数 */
{
  int n0;

  if (p == NULL)
    n0 = 0;
  else
    if (p->lchild == NULL && p->rchild == NULL) 
	   	n0 = 1; 
  	else
	   	n0 = (leafnum(p->lchild) + leafnum(p->rchild));      
  
  return n0;
}/* leafnum */

int depth(BiTree p)         /* 求二叉树深度 */
{
  int d1,d2;
  if (p == NULL) 
    return 0;
  else {
    d1 = depth(p->lchild);
    d2 = depth(p->rchild);
    
    if (d1 > d2)
      return (d1 + 1);
    else
      return (d2 + 1);
  }
}/* depth */

int main(void)
{
  BiTree t = NULL;

  printf("\nplease input data:(用.表示空树)");
  createBiTree(t);

  printf("\n\nPreOrder the tree is:\n");
  PreOrder(t);

  printf("\n\nInOrder the tree is:\n");
  InOrder(t);

  printf("\n\nPostOrder the tree is:\n");
  PostOrder(t);

  printf("\n\n该二叉树有%d个结点\n", nodenum(t));

  printf("\n该二叉树有%d个叶子结点\n", leafnum(t));

  printf("\n该二叉树的深度为%d\n\n", depth(t));
  release(t);

  system("pause");
  return 0;
}

