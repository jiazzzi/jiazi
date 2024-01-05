#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;
node *create(int a[],int n)
{
	node *L,*s,*r;
	L=(node *)malloc(sizeof(node));
	r=L;
	for(int i=0;i<n;i++)
	{
		s=(node *)malloc(sizeof(node));
		s->data=a[i];
		r->next=s;
		s->prev=r;
		r=s;
	}
	r->next=NULL;
	return L->next;
}
node *findjiao(node *A,node *B)
{
	node *C,*s,*r;
	C=(node *)malloc(sizeof(node));
	r=C;
	while(A&&B)
	{
		s=(node *)malloc(sizeof(node));
		if(A->data<B->data)
			A=A->next;
		else if(B->data<A->data)
			B=B->next;
		else if(B->data==A->data)
		{
			s->data=B->data;
			r->next=s;
			s->prev=r;
			r=s;
			B=B->next;
			A=A->next;
		}
	}
	r->next=NULL;
	return C->next;
}
node *findbing(node *A,node *B)
{
	node *D,*s,*r;
	D=(node *)malloc(sizeof(node));
	r=D;
	while(A&&B)
	{
		s=(node *)malloc(sizeof(node));
		if(A->data<B->data)
		{
			s->data=A->data;
			r->next=s;
			s->prev=r;
			r=s;
			A=A->next;
		}
		else if(B->data<A->data)
		{
			s->data=B->data;
			r->next=s;
			s->prev=r;
			r=s;
			B=B->next;
		}
		else if(B->data==A->data)
		{
			s->data=B->data;
			r->next=s;
			s->prev=r;
			r=s;
			B=B->next;
			A=A->next;
		}
	}
	while(A)
	{
		s=(node *)malloc(sizeof(node));
		s->data=A->data;
		r->next=s;
		s->prev=r;
		r=s;
		A=A->next;
	}
	while(B)
	{
		s=(node *)malloc(sizeof(node));
		s->data=B->data;
		r->next=s;
		s->prev=r;
		r=s;
		B=B->next;
	}
	r->next=NULL;
	return D->next;
}
int main()
{
    int a[]= {1, 2, 3, 4, 5};
    int b[]= {3, 4, 5, 6, 7};
    int na=sizeof(a)/sizeof(int);
    int nb=sizeof(b)/sizeof(int);
    node *A,*B,*C,*D;
    A=create(a,na);
    B=create(b,nb);
    C=findjiao(A,B);
    while(C)
    {
    	printf("%d ",C->data);
    	C=C->next;
	}
	printf("\n");
	D=findbing(A,B);
	while(D)
    {
    	printf("%d ",D->data);
    	D=D->next;
	}
    return 0;
}
