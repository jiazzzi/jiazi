#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 判断两棵树是否结构相同
int isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) { // 两棵树都为空，认为结构相同
        return 1;
    }
    if (!p || !q) { // 两棵树中有一棵为空，认为结构不同
        return 0;
    }
    if (p->val != q->val) { // 两棵树根节点的值不同，认为结构不同
        return 0;
    }
    // 递归判断左右子树是否结构相同
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// 判断树B1中是否包含与树B2结构相同的子树
int isSubtree(TreeNode *B1, TreeNode *B2) {
    if (!B1) { // B1为空，无法找到子树
        return 0;
    }
    if (isSameTree(B1, B2)) { // B1和B2结构相同，返回真
        return 1;
    }
    // 递归在B1的左右子树中查找结构相同的子树
    return isSubtree(B1->left, B2) || isSubtree(B1->right, B2);
}

// 创建一棵二叉树
TreeNode* createTree(int val, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

int main() {
    // 创建B1和B2两棵树
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
    // 判断B1是否包含与B2结构相同的子树
    if (isSubtree(B1, B2)) {
        printf("包含相同结构子树\n");
    } else {
        printf("不包含相同结构子树\n");
    }
    return 0;
}
