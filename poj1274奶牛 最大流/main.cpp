#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define inf 10000
using namespace std;
const int M = 200+10;
const int N = 200+10;
int cap[M+N][M+N];
int flow[M+N][M+N];
int a[M+N];
int p[M+N];
int m,n;
queue<int> q;
int maxFlow(int s,int t)
{
    int u,v,f;
    f=0;
    memset(flow,0,sizeof(flow));
    memset(p,0,sizeof(p));
    while(1)
    {
        memset(a,0,sizeof(a));
        a[s]=inf;
        q.push(s);
        while(!q.empty())
        {
            u=q.front();q.pop();
            for(v=0;v<=n+m+1;v++)
            {
                if(cap[u][v]>flow[u][v]&&a[v]==0)
                {
                    p[v]=u;
                    q.push(v);
                    if(a[u]<cap[u][v]-flow[u][v])
                        a[v]=a[u];
                    else
                        a[v]=cap[u][v]-flow[u][v];
                }
            }
        }
        if(a[t]==0) break;
        for(v=t;v!=s;v=p[v])
        {
            flow[p[v]][v]+=a[t];
            flow[v][p[v]]-=a[t];
        }
        f+=a[t];
    }
    return f;
}
int main()
{
    int x,y;
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(cap,0,sizeof(cap));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            cap[0][i]=1;
            for(int j=0;j<x;j++)
            {
                scanf("%d",&y);
                cap[i][n+y]+=1;
            }
        }
        for(int i=n+1;i<=n+m;i++)
            cap[i][n+m+1]=1;
        int ans=maxFlow(0,n+m+1);
        printf("%d\n",ans);
    }
    return 0;
}
