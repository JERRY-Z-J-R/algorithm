/*
	Name: 图书管理系统2.0主文件(单链表实现)
	Copyright: 
	Author: 周吉瑞 
	Date: 20/04/20 12:55
	Description: 图书管理系统main.cpp
*/

#include "LinkList.h" 

int main(void)
{
	LinkList L;
	InitList_L(L);
	
	printf("---------------------------------------\n")
	printf("------------图书管理系统2.0------------\n");
	printf("---------------------------------------\n");
	
	int n;
	printf("请输入图书表将要插入的图书数：");
	scanf("%d", &n);
	CreateList_L(L, n);
	
	printf("---------------------------------------\n");
	PrintList_L(L);
	
	int r = 1;
	while (r) {
	
		int m;
		printf("---------------------------------------\n");
		printf("1.图书查找\n");
		printf("2.取走图书\n");
		printf("3.添加图书\n");
		printf("4.查询图书总量\n");
		printf("5.退出系统\n"); 
		printf("---------------------------------------\n");
		printf("请选择功能：");
		scanf("%d", &m);
	
		switch (m) {
		
			case 1:
				printf("---------------------------------------\n");
				printf("你选择了：图书查找\n");
				printf("请输入你要查找书的书名：");
				char b[50];
				scanf("%s", &b); 
				LocateElem_L(L, b);
				
				break;
			
			case 2:
				printf("---------------------------------------\n");
				printf("你选择了：取走图书\n");
				printf("请输入你要取出书的书名：");
				char c[50];
				scanf("%s", &c);
				GetElem_L(L, c);
			
				printf("---------------------------------------\n");
				PrintList_L(L); 
				
				break;
			
			case 3:
				printf("---------------------------------------\n");
				printf("你选择了：添加图书\n");
				printf("请输入你要插入的位置序号：");
				int i;
				scanf("%d", &i);
				Book e;
				ScanfElem_L(e); 
				ListInsert_L(L, i, e); 
			
				printf("---------------------------------------\n");
				PrintList_L(L);
				
				break;
			
			case 4:
				printf("---------------------------------------\n");
				printf("你选择了：查询图书总量\n");
				int l;
				ListLength_L(L, l);
				printf("图书总量为：%d本\n", l); 
				
				break;
			
			case 5:
				r = 0; 
				
				break;
				
		}
		
	}
	
	printf("---------------------------------------\n");
	printf("成功退出系统！\n");
	printf("---------------------------------------\n");
	
	system("pause");
	return 0;	
} 
