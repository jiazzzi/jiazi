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
// 哈希函数2：将电话号码的每个数字相乘取模 
int hashFunction2(char phoneNumber[]) 
{ 
	int product = 1; 
	for (int i = 0; i < strlen(phoneNumber); i++) 
	{ 
		product *= phoneNumber[i] - '0'; 
	} 
	return product % 10; 
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
	HashNode* hashTable2[10] = {NULL}; 
	// 插入用户信息 
	insertUserInfo(hashTable2, createUserInfo("1234567890", "小小", "小路123号"), hashFunction2); 
	insertUserInfo(hashTable2, createUserInfo("1111111111", "果果", "大路456号"), hashFunction2); 
	insertUserInfo(hashTable2, createUserInfo("4444887777", "冻冻", "狼路487号"), hashFunction2); 
	char phoneNumber[100];
	scanf("%s",&phoneNumber);
	UserInfo* userInfo2 = findUserInfo(hashTable2, phoneNumber, hashFunction2); 
	if (userInfo2 != NULL) 
	{ 
		printf("电话号码：%s，用户名：%s，住址：%s\n", userInfo2->phoneNumber, userInfo2->username, userInfo2->address); 
	} 
	else
		printf("未找到用户信息");
	return 0;
}
