#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	int i,j;
	gets(s);
	{
		for(i=0;s[i]==' ';i++) ;
		j=0;
		for(;i<strlen(s);i++)
		{
			if(s[i]!=' ')
			{
				s[j++] = s[i]; 
			}
			else
			{
			if(s[i-1] != ' ')
				s[j++] = ' '; 
			}
		}
		if(j>0&&s[j-1]==' ')
			s[j-1]='\0'; 
		else
			s[j] = '\0';
		puts(s);
	}
	return 0;
}
