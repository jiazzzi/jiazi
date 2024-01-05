#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// 邻接表的节点结构
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 创建节点
Node* createNode(int v) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 添加边到邻接表中
void addEdge(Node** adjList, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// 深度优先搜索函数
void dfs(Node** adjList, int* visited, int vertex) {
    visited[vertex] = 1;
    Node* temp = adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(adjList, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

// 判断有向图是否是强连通图
int isStronglyConnectedGraph(Node** adjList, int vertices) {
    int* visited = (int *)malloc(vertices * sizeof(int));
    int i;
    // 使用深度优先搜索遍历图，从第一个节点开始
    dfs(adjList, visited, 0);
    // 检查所有节点是否被访问到
    for (i = 0; i < vertices; i++) {
        if (!visited[i]) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int vertices = 5;
    Node** adjList = (Node **)calloc(vertices, sizeof(Node*));
    
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 0);
    addEdge(adjList, 3, 2);
    addEdge(adjList, 4, 2);
    printf("输入：\n0->1,4\n1->3\n2->1,4\n3->0,2\n4->2\n");
    if (isStronglyConnectedGraph(adjList, vertices)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
