#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;
int Pop(SqStack* S);
void InitStack(SqStack* S)
{  
	S->base=(int*)malloc(100*sizeof(int));
	S->top=S->base;
	S->stacksize=100; 
}
int Pop(SqStack* S)
{  
	if (S->top==S->base) 
		return 0;
	char e = *--S->top;
		return e;
}
 
void PrintStack(SqStack* S)
{    
	while(S->top!=S->base)
	{
		int c=Pop(S);      
		if (c<10)
			printf("%d", c);
		else
			printf("%c", c);
	}
}
 
void  Push(SqStack* S,char e) {     
	if (S->top-S->base>=S->stacksize)
	{
		S->base=(int*)realloc(S->base, (S->stacksize+10)*sizeof(int)); 
		S->top=S->base+S->stacksize;
		S->stacksize+=10;
	}
	*S->top=e;  
	S->top++;
}
 
 
int main()
{
	int i,j,t,end = 0;
	SqStack S;
	InitStack(&S);
	int number;
	scanf("%d",&number);
	int x=number,y=number,z=number;
	while(x)
	{                  //转换成二进制
		t=x%2;
		x=x/2;
		Push(&S,t);
	}
	PrintStack(&S);
	printf("\n");
	while(y)
	{                 //转换成八进制
		t=y%8;
		y=y/8;
		Push(&S,t);
	}
	PrintStack(&S);
	printf("\n");
	while(z)
	{                //转换成十六进制
		t=z%16;
		int t1;
		char t2;
		z=z/16;
		if (t==10)
		{
			t2='A';
			Push(&S, t2);
		}
		else if (t==11)
		{
			t2='B';
			Push(&S, t2);
		}
		else if(t==12)
		{
			t2='C';
			Push(&S,t2);
		}
		else if (t==13)
		{
			t2 ='D';
			Push(&S,t2);
		}
		else if (t==14)
		{
			t2 ='E';
			Push(&S,t2);
		}
		else if(t==15)
		{
			t2 ='F';
			Push(&S,t2);
		}
		else
		{
			t1=t;
			Push(&S,t1);
		}
	}
	PrintStack(&S);
	return 0;
}
