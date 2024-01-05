#include<stdio.h>
int place[8]={0};
int flag[8]={1,1,1,1,1,1,1,1};
int d1[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int d2[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int number=0;
void print()
{
	int i,j;                         
	number++;   
	printf("%2d:",number); 
	int table[8][8]={0}; 
	for(i=0;i<8;i++) 
		table[i][place[i]]=1;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(table[j][i]==1)
			printf("(%d,%d)",j,i);
		}
	}
	printf("\n");
}
void generate(int n)
{
	int i;
	for (i=0;i<8;i++) 
	{                          
		if(flag[i]&&d1[n-i+7]&&d2[n+i])    //����ûʺ��λ���Ǻ����
		{
			place[n]=i;              //��ס����
			flag[i]=0;               //ռ�����
			d1[n-i+7] =0;            //ռ���϶Խ���
			d2[n+i]=0;               //ռ���¶Խ���
			if(n<7)                  //������һ���ʺ�
				generate(n+1);
			else
			{
				print();
			}
			flag[i] =1;                        
			d1[n-i+7] =1;
			d2[n+i] =1;
		}
	}
}
int main() 
{
	generate(0);
	return 0;
}

