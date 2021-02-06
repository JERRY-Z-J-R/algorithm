/*
	Name: 利用二叉树计算表达式 
	Copyright: 
	Author: Jerry_Z.
	Date: 06/05/20 19:21
	Description: 利用先序遍历建立表达式二叉树，并输出计算结果 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {      /* 结点结构声明 */
	char data ;              /* 结点数据 */
	struct BTNode *lchild;
	struct BTNode *rchild ;  /* 指针 */
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

void InOrder(BiTree p)      /* 中序遍历二叉树 */
{
  if (p != NULL) {
 	InOrder(p->lchild);
   	printf("%c", p->data);
   	InOrder(p->rchild);
  }
}/* InOrder */

double calculate(BiTree p)
{
	if (p == NULL)
		return 0;
	else if ('0' <= p->data &&  p->data <= '9')
		return p->data - '0';
	else if (p->data == '+')
		return calculate(p->lchild) + calculate(p->rchild);
	else if (p->data == '-')
		return calculate(p->lchild) - calculate(p->rchild);
	else if (p->data == '*')
		return calculate(p->lchild) * calculate(p->rchild);
	else if (p->data == '/')
		return calculate(p->lchild) / calculate(p->rchild);
}/* calculate */ 

int main(void)
{
  BiTree t = NULL;

  printf("\nplease input data:(用.表示空树)\n");
  printf("注：先序遍历输入\n"); 
  createBiTree(t);

  InOrder(t);
  printf("\nbioadashi = %f\n", calculate(t));

  system("pause");
  return 0;
}

