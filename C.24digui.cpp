#include<stdio.h>
void two(int n)
{
	if(n==0)
		return;
	two(n/2);    
	printf("%c",n%2+'0');
}
void eight(int n)
{
	if(n==0)
		return;
	eight(n/8); 
	printf("%c",n%8+'0'); 
}
void sixteen(int n)
{
	if(n==0)
		return;
	sixteen(n/16); 
	if (n%16>9)
		printf("%c",n%16-10+'A');
	else
		printf("%c",n%16+'0');
}
int main()
{
	int n;
	scanf("%d",&n);
	two(n);
	printf("\n");
	eight(n);
	printf("\n");
	sixteen(n);
	printf("\n");
	return 0;
}
