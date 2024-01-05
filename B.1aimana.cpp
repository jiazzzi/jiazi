#include <stdio.h>
#include <string.h>
int main()
{
	char s[1000];  // �����ַ���
	char t[1000];  // �������ַ���
	int p[1000];  // ���İ뾶����
    scanf("%s",s);
    int n=strlen(s);
    // �����ַ���
    t[0]='#';
    for(int i=0;i<n;i++)
	{
        t[i*2+1]=s[i];
        t[i*2+2]='#';
    }
    int len=n*2+1;
    t[len]='\0';
    // Manacher�㷨
    int max_len=0;
    int max_pos=0;
    int index=0;
    int max=0;
    for (int i=0;i<len;i++)
	{
        if(i<max)
		{
            p[i]=p[2*index-i]<max-i?p[2*index-i]:max-i;
        }else
		{
            p[i]=1;
        }
        while(t[i+p[i]]==t[i-p[i]])
		{
            p[i]++;
        }
        if(i+p[i]>max)
		{
            index=i;
            max=i+p[i];
        }
        if(p[i]>max_len)
		{
            max_len=p[i];
            max_pos=i;
        }
    }
    // ������
    printf("����������г���Ϊ%d\n", max_len-1);
    printf("�����������Ϊ");
    for(int i=max_pos-max_len+2;i< max_pos+max_len;i+=2)
	{
        printf("%c",t[i]);
    }
    printf("\n");
    return 0;
}
