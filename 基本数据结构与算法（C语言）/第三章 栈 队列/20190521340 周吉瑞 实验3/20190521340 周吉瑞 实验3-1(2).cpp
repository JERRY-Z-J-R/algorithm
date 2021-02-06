/*
	Name: 实验3-1(2) 
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 14/04/20 13:29
	Description: 顺序栈的实现.cpp 
*/

#include <stdio.h>
#include "intstack.h"

void PrintStack(SqStack &S)
{
    int n = 1; 
    
    while (n <= S.top - S.base) {
		printf("%3d", Get(S, n));
		++n;
	}
	
    printf("\n");      
}/*Pop_and_Print*/

int CreateStack(SqStack &S)
{
    int e;
    
    if (InitStack(S)) {
		printf("初始化栈成功!\n");
    	prt_base_top_length(S);
    }  
    else {
        printf("初始化失败!\n");
        return ERROR;
    }
    
    printf("\n输入需要入栈的各个整数:(Terminated by inputing a character)\n");
   	
	while (scanf("%d", &e)) {
		Push(S, e);
        prt_base_top_length(S);
    }
     
    return OK;
}/*CreateStack*/


int main()
{
    SqStack ss;
    
    printf("1-建立栈\n");
    CreateStack(ss);
    
    printf("\n2-出栈并打印\n");
    prt_base_top_length(ss);
	PrintStack(ss);
	
    prt_base_top_length(ss);
    PrintStack(ss);
    
    return 0;
}   	

