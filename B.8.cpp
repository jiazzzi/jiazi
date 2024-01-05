#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// �ڽӱ�Ľڵ�ṹ
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// �����ڵ�
Node* createNode(int v) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// ��ӱߵ��ڽӱ���
void addEdge(Node** adjList, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// ���������������
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

// �ж�����ͼ�Ƿ���ǿ��ͨͼ
int isStronglyConnectedGraph(Node** adjList, int vertices) {
    int* visited = (int *)malloc(vertices * sizeof(int));
    int i;
    // ʹ�����������������ͼ���ӵ�һ���ڵ㿪ʼ
    dfs(adjList, visited, 0);
    // ������нڵ��Ƿ񱻷��ʵ�
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
    printf("���룺\n0->1,4\n1->3\n2->1,4\n3->0,2\n4->2\n");
    if (isStronglyConnectedGraph(adjList, vertices)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
