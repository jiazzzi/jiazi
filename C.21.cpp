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
void findzhongou(node *A,node *B,int n)
{
	node *p;
	int a,b,i;
	for(i=0;i<n/2;i++)
	{
		if(A->data<B->data)
		{
			p=A;
			A=A->next;
		}
		else if(B->data<A->data)
		{
			p=B;
			B=B->next;
		}
	}
	a=p->data;
	if(A->data<B->data)
	{
		p=A;
		A=A->next;
	}
	else if(B->data<A->data)
	{
		p=B;
		B=B->next;
	}
	b=p->data;
	printf("%.1f",1.0*(a+b)/2);
}
void findzhongji(node *A,node *B,int n)
{
	node *p;
	int a,i;
	for(i=0;i<n/2;i++)
	{
		if(A->data<B->data)
		{
			p=A;
			A=A->next;
		}
		else if(B->data<A->data)
		{
			p=B;
			B=B->next;
		}
	}
	a=p->data;
	printf("%d",a);
}
int main()
{
    int a[]={11, 13, 15, 17, 19};
    int b[]={2, 4, 6, 8, 20};
    int na=sizeof(a)/sizeof(int);
    int nb=sizeof(b)/sizeof(int);
    int n=na+nb;
    node *A,*B;
    A=create(a,na);
    B=create(b,nb);
    if(n%2==0)
    	findzhongou(A,B,n);
    else
    	findzhongji(A,B,n);
    return 0;
}
