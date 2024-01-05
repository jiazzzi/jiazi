#include <stdio.h>
#include<stdlib.h>
int panduan(int num[],int n)
{
	int i=0;
	for(i=1;i<n-1;i++)
	{
		if(num[i-1]<num[i])
			{
				if(num[i]<=num[i+1])
					return 0;
			}
		else if(num[i-1]>num[i])
		{
			if(num[i]>=num[i+1])
				return 0;
		}
		else
			return 0;
	}
	return 1;
}
int shan(int* nums, int numsSize){
    int *tmp = (int*)malloc(sizeof(int) * numsSize);
    int ret = numsSize;
    for(int i = 1; i < numsSize; i++) {
        tmp[i] = nums[i] - nums[i - 1];
        if (tmp[i] == 0) {
            ret--;
            if (i > 1) {
                tmp[i] = tmp[i - 1];
            }
        }
        tmp[i] = tmp[i] > 0 ? 1 : -1;
        if (tmp[i] == tmp[i - 1]) {
            ret--;
        }
    }
    return numsSize-ret;
}
int main() {
    int nums1[] = {1,7,4,9,2,5};
    int n1=sizeof(nums1)/sizeof(int);
    int nums2[] = {1,2,3,4,5};
	int n2=sizeof(nums2)/sizeof(int);
	for(int i=0;i<n1;i++)
		printf("%d",nums1[i]);
    if (panduan(nums1,n1))
	{
        printf("是摆动序列\n");
    }
	else
	{
        printf("非摆动序列,需要删除%d个元素\n",shan(nums1,n1));
    }
	for(int i=0;i<n2;i++)
		printf("%d",nums2[i]);
    if (panduan(nums2,n2))
	{
        printf("是摆动序列\n");
    }
	else
	{
        printf("非摆动序列,需要删除%d个元素\n",shan(nums2,n2));
    }
    return 0;
}
