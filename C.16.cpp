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
int isSubsequence(node* A, node* B) {
    if (A == NULL) {
        return 0; // A为空，不是子序列
    }
    if (B == NULL) {
        return 1; // B为空，是子序列
    }
    // 递归步骤
    if (A->data == B->data) {
        return isSubsequence(A->next, B->next); // 比较下一个元素
    }
	else{
        return isSubsequence(A->next, B); // 继续比较当前A元素和下一个B元素
    }
}
int main() {
    int a[]={1,2,3,4,5};
    int b[]={2,4};
    int na=sizeof(a)/sizeof(int);
    int nb=sizeof(b)/sizeof(int);
    node *A,*B;
    A=create(a,na);
	B=create(b,nb);
    // 判断B是否是A的子序列
	printf("测试序列为：\n");
	printf("A=[1,2,3,4,5]\nB=[2,4]\n"); 
    if (isSubsequence(A, B)) {
        printf("B是A子序列\n");
    }else{
        printf("B不是A子序列\n");
    }
	
    // 释放链表空间
    while (A != NULL) {
        node* temp = A;
        A = A->next;
        free(temp);
    }

    while (B != NULL) {
        node* temp = B;
        B = B->next;
        free(temp);
    }
    int c[]={1,3,5,7};
    int d[]={1,2,3};
    int nc=sizeof(c)/sizeof(int);
    int nd=sizeof(d)/sizeof(int);
    node *C,*D;
    C=create(c,nc);
	D=create(d,nd);
    // 判断B是否是A的子序列
	printf("测试序列为：\n");
	printf("C=[1,3,5,7]\nD=[1,2,3]\n"); 
    if (isSubsequence(A, B)) {
        printf("D是C子序列\n");
    }else{
        printf("D不是C子序列\n");
    }
    return 0;
}
