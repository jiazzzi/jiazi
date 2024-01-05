#include<stdio.h>
#include <stdlib.h> 
// 定义二叉树的节点结构体 
typedef struct TreeNode 
{ 
	char value; 
	struct TreeNode* left; 
	struct TreeNode* right; 
} TreeNode;
// 创建一个新的节点 
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
	// 将当前节点添加到路径中 
	path[pathLen] = root->value; 
	pathLen++; // 如果当前节点是叶子节点且值等于目标值，则打印路径 
	if (root->left == NULL && root->right == NULL && root->value == target) 
	{ 
		printf("从根节点到叶子节点 %c 的路径是：", target); 
		for (int i = 0; i < pathLen; i++) 
		{ 
		printf("%c ", path[i]); 
		} 
		printf("\n"); 
	} // 递归遍历左子树和右子树 
	printPath(root->left, target, path, pathLen);
	printPath(root->right, target, path, pathLen); 
}
int main() 
{ // 创建一棵二叉树 
	char path[100];
	TreeNode* root = createNode('A'); 
	root->left = createNode('B'); 
	root->right = createNode('C'); 
	root->left->left = createNode('D'); 
	root->left->right = createNode('E'); 
	root->right->left = createNode('F'); 
	root->right->right = createNode('G');
	// 输出从根节点到叶子节点 'F' 的路径 
	char target = 'F'; 
	if (panduan(root, target)==1)
		printPath(root, 'F', path, 0);
	if (panduan(root, target)==0)
		printf("%c不是叶子节点。\n", target);
	return 0; 
}
