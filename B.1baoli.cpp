#include<stdio.h>
#include<string.h>
void baoli(char s[])
{
    int len=strlen(s);                  //�ַ�������
    int maxlen=1;                      //������ַ�������
    int start=0;                       //������ַ�����ʼ��ַ
    int t1,t2;
    for(int i=0;i<len;i++)         //��ʼ��ַ
    {
        for(int j=i+1;j<len;j++) //������ַ
        {
            int t1=i,t2=j;
            while(t1<t2&&s[t1]==s[t2])//�ж��ǲ��ǻ���
            {
                t1++;
                t2--;
            }
            if(t1>=t2&&j-i+1>maxlen)
            {
                maxlen=j-i+1;
                start=i;
            }
        }
    }
    int c=0;
 	for(int i=start;c<maxlen;c++,i++)
 	{
 		printf("%c",s[i]);
	}
}
 
int main()
{
    char s[100];
    scanf("%s",s);
    baoli(s);
    return 0;
}
