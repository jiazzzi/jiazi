#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// �����û���Ϣ�ṹ�� 
typedef struct UserInfo 
{ 
	char phoneNumber[11]; 
	char username[50]; 
	char address[100]; 
}UserInfo;
// �����ϣ��ڵ�ṹ�� 
typedef struct HashNode 
{ 
	UserInfo* data; 
	struct HashNode* next; 
}HashNode;
// ����һ���µ��û���Ϣ 
UserInfo* createUserInfo(char phoneNumber[], char username[], char address[]) 
{ 
	UserInfo* newUserInfo = (UserInfo*)malloc(sizeof(UserInfo)); 
	strcpy(newUserInfo->phoneNumber, phoneNumber); 
	strcpy(newUserInfo->username, username); 
	strcpy(newUserInfo->address, address); 
	return newUserInfo; 
}
// ����һ���µĹ�ϣ�ڵ� 
HashNode* createHashNode(UserInfo* data) 
{ 
	HashNode* newHashNode = (HashNode*)malloc(sizeof(HashNode)); 
	newHashNode->data = data; 
	newHashNode->next = NULL; 
	return newHashNode; 
}
// ��ϣ����2�����绰�����ÿ���������ȡģ 
int hashFunction2(char phoneNumber[]) 
{ 
	int product = 1; 
	for (int i = 0; i < strlen(phoneNumber); i++) 
	{ 
		product *= phoneNumber[i] - '0'; 
	} 
	return product % 10; 
}
// �����û���Ϣ����ϣ�� 
void insertUserInfo(HashNode* hashTable[], UserInfo* userInfo, int(*hashFunction)(char[])) 
{ 
	int index = hashFunction(userInfo->phoneNumber);
	// �����λ��Ϊ�գ���ֱ�Ӳ��� 
	if (hashTable[index] == NULL) 
	{ 
		hashTable[index] = createHashNode(userInfo); 
	} 
	// �����λ���Ѿ��нڵ㣬��ʹ�������������ͻ 
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
// �����û���Ϣ
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
	// ������ϣ�� 
	HashNode* hashTable2[10] = {NULL}; 
	// �����û���Ϣ 
	insertUserInfo(hashTable2, createUserInfo("1234567890", "СС", "С·123��"), hashFunction2); 
	insertUserInfo(hashTable2, createUserInfo("1111111111", "����", "��·456��"), hashFunction2); 
	insertUserInfo(hashTable2, createUserInfo("4444887777", "����", "��·487��"), hashFunction2); 
	char phoneNumber[100];
	scanf("%s",&phoneNumber);
	UserInfo* userInfo2 = findUserInfo(hashTable2, phoneNumber, hashFunction2); 
	if (userInfo2 != NULL) 
	{ 
		printf("�绰���룺%s���û�����%s��סַ��%s\n", userInfo2->phoneNumber, userInfo2->username, userInfo2->address); 
	} 
	else
		printf("δ�ҵ��û���Ϣ");
	return 0;
}
