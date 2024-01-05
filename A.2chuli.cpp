#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10 // 散列表的大小
// 用户信息结构体
typedef struct {
    char name[20]; // 用户名
    char address[100]; // 地址
} UserInfo;

// 哈希节点结构体
typedef struct {
    char phoneNumber[12]; // 电话号码
    UserInfo info; // 用户信息
} HashNode;

// 散列表结构体
typedef struct {
    HashNode* nodes[TABLE_SIZE]; // 哈希节点数组
} HashTable;

// 初始化散列表
void initHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->nodes[i] = NULL;
    }
}

// 哈希函数1：将电话号码的每一位相加取余
unsigned int hashFunction1(const char* phoneNumber) {
    unsigned int sum = 0;
    int len = strlen(phoneNumber);
    for (int i = 0; i < len; i++) {
        sum += phoneNumber[i] - '0';
    }
    return sum % TABLE_SIZE;
}

// 哈希函数2：将电话号码的ASCII码相加取余
unsigned int hashFunction2(const char* phoneNumber) {
    unsigned int sum = 0;
    int len = strlen(phoneNumber);
    for (int i = 0; i < len; i++) {
        sum += phoneNumber[i];
    }
    return sum % TABLE_SIZE;
}

// 哈希函数3：将电话号码每一位的平方和相加取余
unsigned int hashFunction3(const char* phoneNumber) {
    unsigned int sum = 0;
    int len = strlen(phoneNumber);
    for (int i = 0; i < len; i++) {
        sum += (phoneNumber[i] - '0') * (phoneNumber[i] - '0');
    }
    return sum % TABLE_SIZE;
}

// 线性探测法处理冲突
int linearProbe(HashTable* hashTable, unsigned int index) {
    for (int i = 1; i < TABLE_SIZE; i++) {
        int j = (index + i) % TABLE_SIZE;
        if (hashTable->nodes[j] == NULL) {
            return j;
        }
    }
    return -1; // 散列表已满
}

// 平方探测法处理冲突
int squareProbe(HashTable* hashTable, unsigned int index) {
    for (int i = 1; i < TABLE_SIZE; i++) {
        int j = (index + i*i) % TABLE_SIZE;
        if (hashTable->nodes[j] == NULL) {
            return j;
        }
    }
    return -1; // 散列表已满
}

// 添加用户信息到散列表
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
            printf("散列表已满\n");
            free(newNode);
            return;
        }
        hashTable->nodes[newIndex] = newNode;
    }
}

// 根据电话号码查找用户信息
void findUserInfo(const HashTable* hashTable, const char* phoneNumber, unsigned int(*hashFunction)(const char*)) {
    int count = 0;
    unsigned int index = hashFunction(phoneNumber);
    while (count < TABLE_SIZE && hashTable->nodes[index] != NULL) {
        if (strcmp(hashTable->nodes[index]->phoneNumber, phoneNumber) == 0) {
            printf("用户名：%s\n", hashTable->nodes[index]->info.name);
            printf("地址：%s\n", hashTable->nodes[index]->info.address);
            return;
        }
        count++;
        index = (index + 1) % TABLE_SIZE; // 线性探测法需要继续探测下一个位置
    }
    printf("未找到该用户信息\n");
}

// 计算冲突率
float calculateConflictRate(const HashTable* hashTable) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable->nodes[i] != NULL) {
            count++;
        }
    }
    return (float)count / TABLE_SIZE;
}

// 计算平均查找长度
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
                index = (index + 1) % TABLE_SIZE; // 线性探测法需要继续探测下一个位置
                 //index = (index + i*i) % TABLE_SIZE; // 平方探测法需要按照平方步长继续探测下一个位置
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
    
    printf("冲突率：%f\n", calculateConflictRate(&hashTable));
    printf("平均查找长度：%f\n", calculateAverageSearchLength(&hashTable, hashFunction1));

    findUserInfo(&hashTable, "1234567890", hashFunction1);
    findUserInfo(&hashTable, "0987654321", hashFunction1);
    findUserInfo(&hashTable, "1357924680", hashFunction1);
    findUserInfo(&hashTable, "2468135790", hashFunction1);
    findUserInfo(&hashTable, "9999999999", hashFunction1);

    return 0;
}
