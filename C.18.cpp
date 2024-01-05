#include<stdio.h>
#include<stdlib.h>
#define NUM 10
typedef struct Node
{
    int seat;
    struct Node* next;
 
}Node,*LinkList;  
void InitList(LinkList& L) 
{
    L=(Node *)malloc(sizeof(Node));  
    L->next=NULL;  
}
 
void CreatList(LinkList& L, int n)
{
    LinkList p,q;
    q=NULL;
    p=L;
    for (int i=0;i<n;i++)
    {
        q=(Node *)malloc(sizeof(Node)); 
        q->seat=i+1;
        q->next=NULL;
        p->next=q;
        p=q;
    }
    p->next=L->next;
}
 
void NodeDelet(LinkList& m, LinkList& n)
{
    LinkList r=m;
    n->next=m->next;
    m = m->next;
    printf("%d ",r->seat);
    free(r);
}
int KillGame(LinkList& L) 
{
    LinkList K=L;
    int count=1; 
    LinkList m,n;
    m=L->next;
    n=L->next;
    printf("被淘汰的人的顺序：");
    while(m)
    {
        if (count!=3)
        {
            n=m;
            m=m->next;
            count++;
        }
        else  
        {
            count=1;   
            NodeDelet(m,n);
        }
        if (m==n) 
            return n->seat; 
    }
}
int main()
{
    LinkList phead=NULL;
    InitList(phead);
    CreatList(phead,NUM);
    printf("\n最后活着的人起始位置：%d",KillGame(phead));
    return 0;
}
