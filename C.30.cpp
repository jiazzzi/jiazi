#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ��
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// �ж��������Ƿ�ṹ��ͬ
int isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) { // ��������Ϊ�գ���Ϊ�ṹ��ͬ
        return 1;
    }
    if (!p || !q) { // ����������һ��Ϊ�գ���Ϊ�ṹ��ͬ
        return 0;
    }
    if (p->val != q->val) { // ���������ڵ��ֵ��ͬ����Ϊ�ṹ��ͬ
        return 0;
    }
    // �ݹ��ж����������Ƿ�ṹ��ͬ
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// �ж���B1���Ƿ��������B2�ṹ��ͬ������
int isSubtree(TreeNode *B1, TreeNode *B2) {
    if (!B1) { // B1Ϊ�գ��޷��ҵ�����
        return 0;
    }
    if (isSameTree(B1, B2)) { // B1��B2�ṹ��ͬ��������
        return 1;
    }
    // �ݹ���B1�����������в��ҽṹ��ͬ������
    return isSubtree(B1->left, B2) || isSubtree(B1->right, B2);
}

// ����һ�ö�����
TreeNode* createTree(int val, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

int main() {
    // ����B1��B2������
    TreeNode *B1 = createTree(1,
        createTree(2,
            createTree(4, NULL, NULL),
            createTree(5, NULL, NULL)
        ),
        createTree(3,
            createTree(6, NULL, NULL),
            createTree(7, NULL, NULL)
        )
    );
    TreeNode *B2 = createTree(2,
        createTree(4, NULL, NULL),
        createTree(5, NULL, NULL)
    );
    // �ж�B1�Ƿ������B2�ṹ��ͬ������
    if (isSubtree(B1, B2)) {
        printf("������ͬ�ṹ����\n");
    } else {
        printf("��������ͬ�ṹ����\n");
    }
    return 0;
}
