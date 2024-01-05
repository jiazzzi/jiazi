#include<stdio.h>
#include<string.h>
int pipei(char a[],char b[])
{
	int lengtha=strlen(a), lengthb=strlen(b);
	int i,j=0;
	char c;
	for(i=0;i<lengtha;i++)
	{
		switch(b[j])
		{
			case '.':break;
			case '*':if(j==0&&b[j]!=a[i]){return 0;}
					else if(j!=0)
					{
						c=b[j-1];
						if(c!=a[i]&&c!='.')
						return 0;
					}break;
			default:if(a[i]!=b[j]){return 0;}break;
		}
		if(b[j]!='*')
			j++;
	}
	if(i==lengtha&&j==lengthb)
		return 1;
	else if(i==lengtha&&b[j]=='*'&&j==lengthb-1)
		return 1;
	else
		return 0;
}
int main()
{
	char a[100],b[100];
	scanf("%s",a);
	scanf("%s",b);
	if(pipei(a,b)==1)
	printf("true");
	else if(pipei(a,b)==0)
	printf("false");
	return 0;
}
