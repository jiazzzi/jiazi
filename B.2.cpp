#include<stdio.h>
#define INF 0xffff 
int n, m;
int d[100]; 
int parent[100];
struct edge 
{
    int u, v, w;
}EG[1000];
int Bellman_Ford(int s)
{
    for(int i=1;i<=n;i++)
    {
        d[i]=INF;
        parent[i]=-1;
    }
    d[s]=0;
    int flag;
    for(int i=1;i<n;i++)
    {
        flag=0; 
        for(int j =0;j<m;j++)
            if(d[EG[j].v]>d[EG[j].u]+EG[j].w)
            {
                d[EG[j].v]=d[EG[j].u]+EG[j].w;
                parent[EG[j].v]=EG[j].u;
                flag=1;
            }
        if(!flag) 
			break;
    }
    for(int i=0;i<m;i++) 
    if(d[EG[i].v]>d[EG[i].u]+EG[i].w)
        return 0;
    return 1;
}
int main()
{
    int s;
    printf("请输入n和m:\n");
    scanf("%d%d", &n, &m);
    printf("请输入m条边(u, v, w)：\n");
    for(int i=0;i<m;i++)
        scanf("%d%d%d", &EG[i].u, &EG[i].v, &EG[i].w);
    printf("请输入起点：");
    scanf("%d",&s);
    if(Bellman_Ford(s))     
	{
        for(int i=1;i<=n;i++)
            printf("%d\n",d[i]);
        printf("\n");
    }
}
