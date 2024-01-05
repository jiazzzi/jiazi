#include <stdio.h> 
#include <stdlib.h>
// 图的顶点结构体 
typedef struct 
{ 
	int value; 
	int visited; 
	int indegree; 
	int* adjacentVertices; 
	int adjacentCount; 
} Vertex;
// 图结构体 
typedef struct 
{ 
	Vertex* vertices[100]; 
	int vertexCount; 
} Graph;
// 创建顶点 
Vertex* createVertex(int value) 
{ 
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex)); 
	vertex->value = value; vertex->visited = 0; 
	vertex->indegree = 0; 
	vertex->adjacentVertices = NULL; 
	vertex->adjacentCount = 0;
	return vertex; 
}
// 添加顶点到图中 
void addVertex(Graph* graph, Vertex* vertex) 
{ 
	graph->vertices[graph->vertexCount++] = vertex;
}

// 添加边到图中 
void addEdge(Graph* graph, int from, int to) 
{ 
	Vertex* fromVertex = NULL; 
	Vertex* toVertex = NULL;
	// 查找起点和终点的顶点 
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
	// 添加边 
	if (fromVertex != NULL && toVertex != NULL) 
	{ 
		fromVertex->adjacentVertices = (int*)realloc(fromVertex->adjacentVertices, (fromVertex->adjacentCount + 1) * sizeof(int)); 
		fromVertex->adjacentVertices[fromVertex->adjacentCount++] = to; 
		toVertex->indegree++; 
	} 
}
// 拓扑排序 
void topologicalSort(Graph* graph) 
{ 
	int sortedCount = 0;
	while (sortedCount < graph->vertexCount) 
	{ 
	// 查找入度为0的顶点 
		int found = 0; 
		for (int i = 0; i < graph->vertexCount; i++) 
		{ 
			if (graph->vertices[i]->indegree == 0 && graph->vertices[i]->visited == 0) 
			{ 
				found = 1; 
				graph->vertices[i]->visited = 1; 
				printf("%d ", graph->vertices[i]->value); 
				// 更新相邻顶点的入度 
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
			printf("图中存在环，无法进行拓扑排序\n"); 
			break; 
		} 
	} 
	printf("\n"); 
}
int main() 
{ 
	// 创建图 
	Graph* graph = (Graph*)malloc(sizeof(Graph)); 
	graph->vertexCount = 0;
	// 创建顶点 
	Vertex* vertex1 = createVertex(1); 
	Vertex* vertex2 = createVertex(2); 
	Vertex* vertex3 = createVertex(3); 
	Vertex* vertex4 = createVertex(4);
	Vertex* vertex5 = createVertex(5); 
	Vertex* vertex6 = createVertex(6); 
	Vertex* vertex7 = createVertex(7); 
	// 添加顶点到图中 
	addVertex(graph, vertex1); addVertex(graph, vertex2); 
	addVertex(graph, vertex3); addVertex(graph, vertex4); 
	addVertex(graph, vertex5); addVertex(graph, vertex6); 
	addVertex(graph, vertex7); 
	// 添加边到图中 
	addEdge(graph, 1, 2); addEdge(graph, 1, 3); 
	addEdge(graph, 2, 3); addEdge(graph, 2, 4); 
	addEdge(graph, 3, 4); addEdge(graph, 3, 5); 
	addEdge(graph, 4, 6); addEdge(graph, 5, 6); 
	addEdge(graph, 6, 7); 
	// 执行拓扑排序 
	topologicalSort(graph); 
	return 0; 
}
