#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10 // ɢ�б�Ĵ�С
// �û���Ϣ�ṹ��
typedef struct {
    char name[20]; // �û���
    char address[100]; // ��ַ
} UserInfo;

// ��ϣ�ڵ�ṹ��
typedef struct {
    char phoneNumber[12]; // �绰����
    UserInfo info; // �û���Ϣ
} HashNode;

// ɢ�б�ṹ��
typedef struct {
    HashNode* nodes[TABLE_SIZE]; // ��ϣ�ڵ�����
} HashTable;

// ��ʼ��ɢ�б�
void initHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->nodes[i] = NULL;
    }
}

// ��ϣ����1�����绰�����ÿһλ���ȡ��
unsigned int hashFunction1(const char* phoneNumber) {
    unsigned int sum = 0;
    int len = strlen(phoneNumber);
    for (int i = 0; i < len; i++) {
        sum += phoneNumber[i] - '0';
    }
    return sum % TABLE_SIZE;
}

// ��ϣ����2�����绰�����ASCII�����ȡ��
unsigned int hashFunction2(const char* phoneNumber) {
    unsigned int sum = 0;
    int len = strlen(phoneNumber);
    for (int i = 0; i < len; i++) {
        sum += phoneNumber[i];
    }
    return sum % TABLE_SIZE;
}

// ��ϣ����3�����绰����ÿһλ��ƽ�������ȡ��
unsigned int hashFunction3(const char* phoneNumber) {
    unsigned int sum = 0;
    int len = strlen(phoneNumber);
    for (int i = 0; i < len; i++) {
        sum += (phoneNumber[i] - '0') * (phoneNumber[i] - '0');
    }
    return sum % TABLE_SIZE;
}

// ����̽�ⷨ�����ͻ
int linearProbe(HashTable* hashTable, unsigned int index) {
    for (int i = 1; i < TABLE_SIZE; i++) {
        int j = (index + i) % TABLE_SIZE;
        if (hashTable->nodes[j] == NULL) {
            return j;
        }
    }
    return -1; // ɢ�б�����
}

// ƽ��̽�ⷨ�����ͻ
int squareProbe(HashTable* hashTable, unsigned int index) {
    for (int i = 1; i < TABLE_SIZE; i++) {
        int j = (index + i*i) % TABLE_SIZE;
        if (hashTable->nodes[j] == NULL) {
            return j;
        }
    }
    return -1; // ɢ�б�����
}

// ����û���Ϣ��ɢ�б�
void addUserInfo(HashTable* hashTable, const char* phoneNumber, const char* name, const char* address, unsigned int(*hashFunction)(const char*)) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    strcpy(newNode->phoneNumber, phoneNumber);
    strcpy(newNode->info.name, name);
    strcpy(newNode->info.address, address);
    
    unsigned int index = hashFunction(phoneNumber);
    if (hashTable->nodes[index] == NULL) {
        hashTable->nodes[index] = newNode;
    } else {
        int newIndex = linearProbe(hashTable, index);
         //int newIndex = squareProbe(hashTable, index);
        if (newIndex == -1) {
            printf("ɢ�б�����\n");
            free(newNode);
            return;
        }
        hashTable->nodes[newIndex] = newNode;
    }
}

// ���ݵ绰��������û���Ϣ
void findUserInfo(const HashTable* hashTable, const char* phoneNumber, unsigned int(*hashFunction)(const char*)) {
    int count = 0;
    unsigned int index = hashFunction(phoneNumber);
    while (count < TABLE_SIZE && hashTable->nodes[index] != NULL) {
        if (strcmp(hashTable->nodes[index]->phoneNumber, phoneNumber) == 0) {
            printf("�û�����%s\n", hashTable->nodes[index]->info.name);
            printf("��ַ��%s\n", hashTable->nodes[index]->info.address);
            return;
        }
        count++;
        index = (index + 1) % TABLE_SIZE; // ����̽�ⷨ��Ҫ����̽����һ��λ��
    }
    printf("δ�ҵ����û���Ϣ\n");
}

// �����ͻ��
float calculateConflictRate(const HashTable* hashTable) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable->nodes[i] != NULL) {
            count++;
        }
    }
    return (float)count / TABLE_SIZE;
}

// ����ƽ�����ҳ���
float calculateAverageSearchLength(const HashTable* hashTable, unsigned int(*hashFunction)(const char*)) {
    float sum = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable->nodes[i] != NULL) {
            int count = 0;
            unsigned int index = hashFunction(hashTable->nodes[i]->phoneNumber);
            while (count < TABLE_SIZE && hashTable->nodes[index] != NULL) {
                if (strcmp(hashTable->nodes[index]->phoneNumber, hashTable->nodes[i]->phoneNumber) == 0) {
                    break;
                }
                count++;
                index = (index + 1) % TABLE_SIZE; // ����̽�ⷨ��Ҫ����̽����һ��λ��
                 //index = (index + i*i) % TABLE_SIZE; // ƽ��̽�ⷨ��Ҫ����ƽ����������̽����һ��λ��
            }
            sum += count;
        }
    }
    return sum / TABLE_SIZE;
}

int main() {
    HashTable hashTable;
    initHashTable(&hashTable);

    addUserInfo(&hashTable, "1234567890", "Alice", "Address1", hashFunction1);
    addUserInfo(&hashTable, "0987654321", "Bob", "Address2", hashFunction1);
    addUserInfo(&hashTable, "1357924680", "Charlie", "Address3", hashFunction1);
    addUserInfo(&hashTable, "2468135790", "David", "Address4", hashFunction1);
    
    printf("��ͻ�ʣ�%f\n", calculateConflictRate(&hashTable));
    printf("ƽ�����ҳ��ȣ�%f\n", calculateAverageSearchLength(&hashTable, hashFunction1));

    findUserInfo(&hashTable, "1234567890", hashFunction1);
    findUserInfo(&hashTable, "0987654321", hashFunction1);
    findUserInfo(&hashTable, "1357924680", hashFunction1);
    findUserInfo(&hashTable, "2468135790", hashFunction1);
    findUserInfo(&hashTable, "9999999999", hashFunction1);

    return 0;
}
