#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define inf 2000000000
using namespace std;
const int maxn = 200+10;
int cap[maxn][maxn];
int flow[maxn][maxn];
int a[maxn];
int p[maxn];
queue<int> q;
int m,n;
int maxFlow(int s,int t)
{
    int f=0;
    int u;
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
            for(int v=1;v<=m;v++)
            {
                if(cap[u][v]>flow[u][v]&&a[v]==0)
                {
                    p[v]=u;
                    q.push(v);
                    if(a[u]>cap[u][v]-flow[u][v])
                        a[v]=cap[u][v]-flow[u][v];
                    else
                        a[v]=a[u];

                }
            }
        }
        if(a[t]==0) break;
        for(int v=t;v!=s;v=p[v])
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
    int x,y,z;
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int T=1;T<=t;T++)
    {
        scanf("%d%d",&m,&n);
        memset(cap,0,sizeof(cap));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            cap[x][y]+=z;
        }
        int ans=maxFlow(1,m);
        printf("Case %d: %d\n",T,ans);
    }
    return 0;
}
