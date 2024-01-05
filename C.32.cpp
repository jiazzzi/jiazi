#include<stdio.h>
#include <stdlib.h> 
// ����������Ľڵ�ṹ�� 
typedef struct TreeNode 
{ 
	char value; 
	struct TreeNode* left; 
	struct TreeNode* right; 
} TreeNode;
// ����һ���µĽڵ� 
TreeNode* createNode(char value) 
{ 
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); 
	newNode->value = value; 
	newNode->left = NULL; 
	newNode->right = NULL; 
	return newNode; 
}
int panduan(TreeNode* root, char target)
{ 
	if (root == NULL) 
	{ 
		return 0; 
	}
	if (root->value == target) 
	{ 
		return 1; 
	} 
	if (panduan(root->left, target) || panduan(root->right, target)) 
	{ 
		return 1;
	} 
	return 0; 
}
void printPath(TreeNode* root, char target, char* path, int pathLen) 
{ 
	if (root == NULL) 
	{
		return;
	}
	// ����ǰ�ڵ���ӵ�·���� 
	path[pathLen] = root->value; 
	pathLen++; // �����ǰ�ڵ���Ҷ�ӽڵ���ֵ����Ŀ��ֵ�����ӡ·�� 
	if (root->left == NULL && root->right == NULL && root->value == target) 
	{ 
		printf("�Ӹ��ڵ㵽Ҷ�ӽڵ� %c ��·���ǣ�", target); 
		for (int i = 0; i < pathLen; i++) 
		{ 
		printf("%c ", path[i]); 
		} 
		printf("\n"); 
	} // �ݹ������������������ 
	printPath(root->left, target, path, pathLen);
	printPath(root->right, target, path, pathLen); 
}
int main() 
{ // ����һ�ö����� 
	char path[100];
	TreeNode* root = createNode('A'); 
	root->left = createNode('B'); 
	root->right = createNode('C'); 
	root->left->left = createNode('D'); 
	root->left->right = createNode('E'); 
	root->right->left = createNode('F'); 
	root->right->right = createNode('G');
	// ����Ӹ��ڵ㵽Ҷ�ӽڵ� 'F' ��·�� 
	char target = 'F'; 
	if (panduan(root, target)==1)
		printPath(root, 'F', path, 0);
	if (panduan(root, target)==0)
		printf("%c����Ҷ�ӽڵ㡣\n", target);
	return 0; 
}
