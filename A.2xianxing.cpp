#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// 定义用户信息结构体 
typedef struct UserInfo 
{ 
	char phoneNumber[11]; 
	char username[50]; 
	char address[100]; 
}UserInfo;
// 定义哈希表节点结构体 
typedef struct HashNode 
{ 
	UserInfo* data; 
	struct HashNode* next; 
}HashNode;
// 创建一个新的用户信息 
UserInfo* createUserInfo(char phoneNumber[], char username[], char address[]) 
{ 
	UserInfo* newUserInfo = (UserInfo*)malloc(sizeof(UserInfo)); 
	strcpy(newUserInfo->phoneNumber, phoneNumber); 
	strcpy(newUserInfo->username, username); 
	strcpy(newUserInfo->address, address); 
	return newUserInfo; 
}
// 创建一个新的哈希节点 
HashNode* createHashNode(UserInfo* data) 
{ 
	HashNode* newHashNode = (HashNode*)malloc(sizeof(HashNode)); 
	newHashNode->data = data; 
	newHashNode->next = NULL; 
	return newHashNode; 
}
// 哈希函数1：将电话号码的每个数字相加取模 
int hashFunction1(char phoneNumber[]) 
{ 
	int sum = 0; 
	for (int i = 0; i < strlen(phoneNumber); i++) 
	{ 
		sum += phoneNumber[i] - '0'; 
	} 
	return sum % 10; 
}
// 插入用户信息到哈希表 
void insertUserInfo(HashNode* hashTable[], UserInfo* userInfo, int(*hashFunction)(char[])) 
{ 
	int index = hashFunction(userInfo->phoneNumber);
	// 如果该位置为空，则直接插入 
	if (hashTable[index] == NULL) 
	{ 
		hashTable[index] = createHashNode(userInfo); 
	} 
	// 如果该位置已经有节点，则使用拉链法解决冲突 
	else 
	{ 
		HashNode* currentNode = hashTable[index]; 
		while (currentNode->next != NULL) 
		{ 
			currentNode = currentNode->next; 
		} 
		currentNode->next = createHashNode(userInfo); 
	} 
}

// 查找用户信息
UserInfo* findUserInfo(HashNode* hashTable[], char phoneNumber[], int(*hashFunction)(char[])) 
{ 
	int index = hashFunction(phoneNumber);
	HashNode* currentNode = hashTable[index]; 
	while (currentNode != NULL) 
	{ 
		if (strcmp(currentNode->data->phoneNumber, phoneNumber) == 0) 
		{ 
			return currentNode->data; 
		} 
		currentNode = currentNode->next; 
		} 
		return NULL; 
}
int main() 
{ 
	// 创建哈希表 
	HashNode* hashTable1[10] = {NULL}; 
	// 插入用户信息 
	insertUserInfo(hashTable1, createUserInfo("1234567890", "小小", "小路123号"), hashFunction1); 
	insertUserInfo(hashTable1, createUserInfo("1111111111", "果果", "大路456号"), hashFunction1); 
	insertUserInfo(hashTable1, createUserInfo("4444887777", "冻冻", "狼路487号"), hashFunction1); 
	char phoneNumber[100];
	scanf("%s",&phoneNumber);
	UserInfo* userInfo1 = findUserInfo(hashTable1, phoneNumber, hashFunction1); 
	if (userInfo1 != NULL) 
	{ 
		printf("电话号码：%s，用户名：%s，住址：%s\n", userInfo1->phoneNumber, userInfo1->username, userInfo1->address); 
	} 
	else
		printf("未找到用户信息");
	return 0;
}
