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
        return 0; // AΪ�գ�����������
    }
    if (B == NULL) {
        return 1; // BΪ�գ���������
    }
    // �ݹ鲽��
    if (A->data == B->data) {
        return isSubsequence(A->next, B->next); // �Ƚ���һ��Ԫ��
    }
	else{
        return isSubsequence(A->next, B); // �����Ƚϵ�ǰAԪ�غ���һ��BԪ��
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
    // �ж�B�Ƿ���A��������
	printf("��������Ϊ��\n");
	printf("A=[1,2,3,4,5]\nB=[2,4]\n"); 
    if (isSubsequence(A, B)) {
        printf("B��A������\n");
    }else{
        printf("B����A������\n");
    }
	
    // �ͷ�����ռ�
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
    // �ж�B�Ƿ���A��������
	printf("��������Ϊ��\n");
	printf("C=[1,3,5,7]\nD=[1,2,3]\n"); 
    if (isSubsequence(A, B)) {
        printf("D��C������\n");
    }else{
        printf("D����C������\n");
    }
    return 0;
}
