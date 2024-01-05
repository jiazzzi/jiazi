#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct 
{ 
	char data[100]; 
	int top;
} Stack;
void initStack(Stack *s) 
{ 
	s->top = -1; 
} 
int isEmpty(Stack *s) 
{ 
	return s->top == -1; 
} 
int isFull(Stack *s) 
{ 
	return s->top == 100 - 1; 
} 
void push(Stack *s, char c) 
{ 
	if (isFull(s)) 
	{ 
	printf("Stack is full!\n"); 
	exit(1); 
	} 
	s->data[++s->top] = c; 
} 
char pop(Stack *s) 
{ 
	if (isEmpty(s)) 
	{ 
	printf("Stack is empty!\n"); 
	exit(1); 
	} 
	return s->data[s->top--]; 
} 
char peek(Stack *s) 
{ 
	if (isEmpty(s)) 
	{ 
		printf("Stack is empty!\n"); 
	exit(1); 
	} 
	return s->data[s->top]; 
} 
int isValidOutStackSeq(char *seq, char *charset) 
{ 
	Stack s; 
	initStack(&s); 
	int i = 0, j = 0; 
	while (seq[i] != '\0') 
	{ 
		if (!isEmpty(&s) && peek(&s) == seq[i]) 
		{ 
			pop(&s); i++; 
		} 
		else 
		{ 
			while (j < strlen(charset) && charset[j] != seq[i]) 
			{ 
				push(&s, charset[j]); j++; 
		} 
		if (j == strlen(charset)) 
		{ 
			return 0; 
		} 
		push(&s, charset[j]); 
		j++; 
		} 
	} 
	return isEmpty(&s); 
} 
int main() 
{ 
	char s1[100], s2[100]; 
	printf("���������У�"); 
	scanf("%s", s1); 
	printf("�������ַ�����"); 
	scanf("%s", s2); 
	if (isValidOutStackSeq(s1, s2)) 
	{ 
		printf("�ǺϷ��ĳ�ջ���С�\n"); 
	} 
	else 
	{ 
		printf("���ǺϷ��ĳ�ջ���С�\n"); 
	} 
	return 0; 
}
