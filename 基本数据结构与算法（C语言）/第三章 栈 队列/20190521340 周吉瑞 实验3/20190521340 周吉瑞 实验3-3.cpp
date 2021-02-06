/*
	Name: 实验3-3
	Copyright: 
	Author: 20190521340 周吉瑞 
	Date: 14/04/20 14:24
	Description: 设计一个判断表达式括号是否匹配的算法，并编程实现。
				如：  	输入：2+[(c-d)*6-(f-7)*a)]/6 	输出：NO
						输入：a-[(c-d)*6-(s/3-x)]/2		输出：YES

*/

#include <stdio.h>
#include "intstack.h"

int main()
{
	char ch;  
	SqStack S;
	SElemType e;
	int f = 1;
	
    InitStack(S);
    
    printf("input formula Enter is end:");
    
    while ((ch = getchar()) != '\n') {
    	
        if (ch == '(' || ch == '[' || ch == '{')
			Push(S, ch);   
		   
        else {
        	
		    if (ch == ')') {
			
                if (StackEmpty(S))
					f = 0;
					    
                else {
					Pop(S, e);
                   	if (e != '(')
						f = 0;
				}
				
			}
                                           
            if (ch == ']') {
			
              	if (StackEmpty(S)) 
					f = 0;
					    
                else {
					Pop(S, e);
                   	if (e != '[')
						f = 0;
				}
				
			}
				
            if (ch == '}') {
		
                if (StackEmpty(S))
					f = 0;
					    
                else {
					Pop(S, e);
                   	if (e != '{')
						f = 0;
				}
				
			}
			
	   }
	   
	}
	
	if (f) {
		if (StackEmpty(S))  
			printf("YES\n");        
		else 
			printf("NO\n");
	}
	
	else {
    	printf("NO\n");
	} 
	     
	return 0;                
} 
