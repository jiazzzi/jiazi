#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
void jia(char* num1, char* num2, char* result) 
{ 
	int carry = 0; 
	int len1 = strlen(num1); 
	int len2 = strlen(num2); 
	int maxLen = len1 > len2 ? len1 : len2;
	for (int i = 0; i < maxLen; i++) 
	{ 
		int digit1 = i < len1 ? num1[len1 - 1 - i] - '0' : 0; 
		int digit2 = i < len2 ? num2[len2 - 1 - i] - '0' : 0; 
		int sum = digit1 + digit2 + carry; result[maxLen - 1 - i] = sum % 10 + '0'; 
		carry = sum / 10; 
	} 
	if (carry > 0) 
	{ 
		memmove(result + 1, result, maxLen); 
		result[0] = carry + '0'; 
		result[maxLen + 1] = '\0'; 
	} 
}
void jian(char* num1, char* num2, char* result) 
{ 
	int borrow = 0; int len1 = strlen(num1); 
	int len2 = strlen(num2); int maxLen = len1 > len2 ? len1 : len2;
	for (int i = 0; i < maxLen; i++) 
	{ 
		int digit1 = i < len1 ? num1[len1 - 1 - i] - '0' : 0; 
		int digit2 = i < len2 ? num2[len2 - 1 - i] - '0' : 0; 
		int diff = digit1 - digit2 - borrow; 
		if (diff < 0) 
		{ 
		diff += 10;
		borrow = 1; 
		} 
		else 
		{ 
		borrow = 0; 
		} 
		result[maxLen - 1 - i] = diff + '0'; 
	}
	result[maxLen] = '\0'; 
}
void cheng(char* num1, char* num2, char* result) 
{
	int len1 = strlen(num1); int len2 = strlen(num2); 
	int len = len1 + len2; 
	int* product = (int*)malloc(len * sizeof(int)); 
	memset(product, 0, len * sizeof(int));
	for (int i = len1 - 1; i >= 0; i--) 
	{ 
		for (int j = len2 - 1; j >= 0; j--) 
		{
		int digit1 = num1[i] - '0'; 
		int digit2 = num2[j] - '0'; 
		product[i + j + 1] += digit1 * digit2; 
		} 
	} 
	for (int i = len - 1; i > 0; i--) 
	{ 
		product[i - 1] += product[i] / 10; 
		product[i] %= 10; 
	} 
	for (int i = 0; i < len; i++) 
	{ 
		result[i] = product[i] + '0'; 
	} 
	result[len] = '\0'; 
	free(product); 
}
int main() 
{
	char num1[100] = "12345678901234567890"; 
	char num2[100] = "98765432109876543210"; 
	char result[200];
	printf("测试数据1：\n12345678901234567890\n98765432109876543210\n"); 
	jia(num1, num2, result); 
	printf("相加结果：%s\n", result); 
	jian(num1, num2, result); 
	printf("相减结果：%s\n", result); 
	cheng(num1, num2, result); 
	printf("相乘结果：%s\n", result); 
	strcpy(num1, "11223344556677889900"); 
	strcpy(num2, "99887766554433221100");
	printf("测试数据2：\n11223344556677889900\n99887766554433221100\n"); 
	jia(num1, num2, result); 
	printf("相加结果：%s\n", result); 
	jian(num1, num2, result); 
	printf("相减结果：%s\n", result); 
	cheng(num1, num2, result); 
	printf("相乘结果：%s\n", result); 
	return 0; 
}
