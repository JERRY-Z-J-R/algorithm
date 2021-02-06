/*
	Name: 实验1-5 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 07/04/20 23:48
	Description: 调试程序：设有一个学生表格，有姓名、年龄、班级3项
				编程输入人员的数据，再以表格输出
*/

#include <stdio.h>
#define N 10

typedef struct student {
	char name[8];		/*姓名*/
	int age;	    	/*年龄*/
	int clas;		/*班级*/
}PERSON; 

int main()
{
	int i, n;
	PERSON stu[N];

	printf("\n请输入人数(<10):\n");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {				/*输入n个人员的信息*/
		printf("\n请输入第%d人员的信息：(name  age    class)\n", i + 1);
		scanf("%s%d%d",stu[i].name, &stu[i].age, &stu[i]. clas);
	}
	printf("\n------------------------------\n"); 
	printf("name          age               class/office\n");
	
	for (i = 0; i < n; i++) 			/*输出*/
		printf("%4s  is     %3d years old      His class  is %d\n", stu[i].name, stu[i].age,  stu[i].clas);

	return 0;
}

