#include <stdio.h> 
#include <stdlib.h>
// ͼ�Ķ���ṹ�� 
typedef struct 
{ 
	int value; 
	int visited; 
	int indegree; 
	int* adjacentVertices; 
	int adjacentCount; 
} Vertex;
// ͼ�ṹ�� 
typedef struct 
{ 
	Vertex* vertices[100]; 
	int vertexCount; 
} Graph;
// �������� 
Vertex* createVertex(int value) 
{ 
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex)); 
	vertex->value = value; vertex->visited = 0; 
	vertex->indegree = 0; 
	vertex->adjacentVertices = NULL; 
	vertex->adjacentCount = 0;
	return vertex; 
}
// ��Ӷ��㵽ͼ�� 
void addVertex(Graph* graph, Vertex* vertex) 
{ 
	graph->vertices[graph->vertexCount++] = vertex;
}

// ��ӱߵ�ͼ�� 
void addEdge(Graph* graph, int from, int to) 
{ 
	Vertex* fromVertex = NULL; 
	Vertex* toVertex = NULL;
	// ���������յ�Ķ��� 
	for (int i = 0; i < graph->vertexCount; i++) 
	{ 
		if (graph->vertices[i]->value == from) 
		{ 
			fromVertex = graph->vertices[i]; 
		} 
		if (graph->vertices[i]->value == to) 
		{ 
			toVertex = graph->vertices[i]; 
		} 
	} 
	// ��ӱ� 
	if (fromVertex != NULL && toVertex != NULL) 
	{ 
		fromVertex->adjacentVertices = (int*)realloc(fromVertex->adjacentVertices, (fromVertex->adjacentCount + 1) * sizeof(int)); 
		fromVertex->adjacentVertices[fromVertex->adjacentCount++] = to; 
		toVertex->indegree++; 
	} 
}
// �������� 
void topologicalSort(Graph* graph) 
{ 
	int sortedCount = 0;
	while (sortedCount < graph->vertexCount) 
	{ 
	// �������Ϊ0�Ķ��� 
		int found = 0; 
		for (int i = 0; i < graph->vertexCount; i++) 
		{ 
			if (graph->vertices[i]->indegree == 0 && graph->vertices[i]->visited == 0) 
			{ 
				found = 1; 
				graph->vertices[i]->visited = 1; 
				printf("%d ", graph->vertices[i]->value); 
				// �������ڶ������� 
				for (int j = 0; j < graph->vertices[i]->adjacentCount; j++) 
				{ 
					int adjacentValue = graph->vertices[i]->adjacentVertices[j]; 
					for (int k = 0; k < graph->vertexCount; k++) 
					{ 
						if (graph->vertices[k]->value == adjacentValue) 
						{ 
							graph->vertices[k]->indegree--; 
							break; 
						} 
					} 
				} 
				sortedCount++; 
				break; 
			} 
		} 
		if (!found) 
		{ 
			printf("ͼ�д��ڻ����޷�������������\n"); 
			break; 
		} 
	} 
	printf("\n"); 
}
int main() 
{ 
	// ����ͼ 
	Graph* graph = (Graph*)malloc(sizeof(Graph)); 
	graph->vertexCount = 0;
	// �������� 
	Vertex* vertex1 = createVertex(1); 
	Vertex* vertex2 = createVertex(2); 
	Vertex* vertex3 = createVertex(3); 
	Vertex* vertex4 = createVertex(4);
	Vertex* vertex5 = createVertex(5); 
	Vertex* vertex6 = createVertex(6); 
	Vertex* vertex7 = createVertex(7); 
	// ��Ӷ��㵽ͼ�� 
	addVertex(graph, vertex1); addVertex(graph, vertex2); 
	addVertex(graph, vertex3); addVertex(graph, vertex4); 
	addVertex(graph, vertex5); addVertex(graph, vertex6); 
	addVertex(graph, vertex7); 
	// ��ӱߵ�ͼ�� 
	addEdge(graph, 1, 2); addEdge(graph, 1, 3); 
	addEdge(graph, 2, 3); addEdge(graph, 2, 4); 
	addEdge(graph, 3, 4); addEdge(graph, 3, 5); 
	addEdge(graph, 4, 6); addEdge(graph, 5, 6); 
	addEdge(graph, 6, 7); 
	// ִ���������� 
	topologicalSort(graph); 
	return 0; 
}
