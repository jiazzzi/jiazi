#include <stdio.h> 
#include <stdlib.h>
// �ڽӾ���ת��Ϊ�ڽӱ� 
void matrixToList(int matrix[100][100], int vertices) 
{ 	// �����ڽӱ����� 
	int** list = (int**)malloc(vertices * sizeof(int*)); 
	for (int i = 0; i < vertices; i++) 
	{ 
		list[i] = (int*)malloc(vertices * sizeof(int)); 
	}
	// ���ڽӾ���ת��Ϊ�ڽӱ� 
	for (int i = 0; i < vertices; i++) 
	{ 
		int count = 0; for (int j = 0; j < vertices; j++) 
		{ 
			if (matrix[i][j] == 1) 
			{ 
				list[i][count] = j; 
				count++; 
			} 
		} 
		list[i][count] = -1; } // ��ӡ�ڽӱ� 
		printf("�ڽӱ�\n"); 
		for (int i = 0; i < vertices; i++) 
		{
			printf("%d: ", i); 
			int j = 0; 
			while (list[i][j] != -1) 
			{ 
				printf("%d ", list[i][j]); 
				j++; 
			} 
			printf("\n"); 
		}
}
// �ڽӱ�ת��Ϊ�ڽӾ��� 
void listToMatrix(int** list, int vertices) 
{ // �����ڽӾ������� 
	int matrix[100][100] = {0};
	// ���ڽӱ�ת��Ϊ�ڽӾ��� 
	for (int i = 0; i < vertices; i++) 
	{ 
		int j = 0; 
		while (list[i][j] != -1) 
		{ 
			matrix[i][list[i][j]] = 1; 
			j++;
		}
	} // ��ӡ�ڽӾ��� 
	printf("�ڽӾ���\n"); 
	for (int i = 0; i < vertices; i++) 
	{ 
		for (int j = 0; j < vertices; j++) 
		{ 
			printf("%d ", matrix[i][j]);
		} 
		printf("\n"); 
	} 
}
int main() 
{ 
	int vertices = 4; 
	// ��������1���ڽӾ���ת��Ϊ�ڽӱ� 
	int matrix[100][100] = 
	{ 
		{0, 1, 0, 0}, 
		{1, 0, 1, 1}, 
		{0, 1, 0, 0}, 
		{0, 1, 0, 0} 
	}; 
	matrixToList(matrix, vertices);
	// ��������2���ڽӱ�ת��Ϊ�ڽӾ��� 
	int** list = (int**)malloc(vertices * sizeof(int*)); 
	list[0] = (int*)malloc(2 * sizeof(int)); 
	list[0][0] = 1; 
	list[0][1] = -1; 
	list[1] = (int*)malloc(4 * sizeof(int)); 
	list[1][0] = 0; list[1][1] = 2; 
	list[1][2] = 3; list[1][3] = -1; 
	list[2] = (int*)malloc(2 * sizeof(int)); 
	list[2][0] = 1; list[2][1] = -1; 
	list[3] = (int*)malloc(2 * sizeof(int)); 
	list[3][0] = 1; list[3][1] = -1; 
	listToMatrix(list, vertices);  
	return 0; 
}
