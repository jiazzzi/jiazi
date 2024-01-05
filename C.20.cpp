#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node *next;
}node;
node *create(node *A,int s[])
{
	node *r,*p;
	A=(node *)malloc(sizeof(node));
	r=A;
	int i=0;
	while(s[i]!=0)
	{
		p=(node *)malloc(sizeof(node));
		p->data=s[i];
		r->next=p;
		r=p;
		i++;
	}
	r->next=NULL;
	return A->next;
}
node chai(node *A)
{
	node *B,*C,*p1,*r1,*p2,*r2;
	B=(node *)malloc(sizeof(node));
	C=(node *)malloc(sizeof(node));
	r1=B;
	r2=C;
	int c=1;
	while(A)
	{
		if(c%2==1)
		{
			p1=(node *)malloc(sizeof(node));
			p1->data=A->data;
			r1->next=p1;
			r1=p1;
			A=A->next;
			c++; 
		}
		else if(c%2==0)
		{
			p2=(node *)malloc(sizeof(node));
			p2->data=A->data;
			r2->next=p2;
			r2=p2;
			A=A->next;
			c++;
		}
	}
	r1->next=NULL;
	r2->next=NULL;
	B=B->next;
	if(B)
	{
		printf("%d",B->data);
		B=B->next;
	}
	while(B)
	{
		printf("->%d",B->data);
		B=B->next;
	}
	printf("\n");
	C=C->next;
	if(C)
	{
		printf("%d",C->data);
		C=C->next;
	}
	while(C)
	{
		printf("->%d",C->data);
		C=C->next;
	}
	printf("\n");
}
int main()
{
	node *A,*A1;
	A1=A;
	int s[100];
	int i=0;
	scanf("%d",&s[i]);
	while(s[i]!=0)
	{
		i++;
		scanf("%d",&s[i]);
	}
	A=create(A,s);
	chai(A);
	return 0;
}
