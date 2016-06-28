#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define inf 1000
using namespace std;
int cap[550][550];
int flow[550][550];
int a[550],p[550];
int n,f,d;
queue<int> q;
int maxFlow(int s,int t)
{
    int u,v,f=0;
    memset(p,0,sizeof(p));
    memset(flow,0,sizeof(flow));
    while(1)
    {

        q.push(s);
        memset(a,0,sizeof(a));
        a[s]=inf;
        while(!q.empty())
        {
            u=q.front();q.pop();
            for(v=0;v<=3*n+f+d+1;v++)
            {
                if(cap[u][v]>flow[u][v]&&a[v]==0)
                {
                    p[v]=u;
                    q.push(v);
                    a[v]=a[u]>cap[u][v]-flow[u][v]?cap[u][v]-flow[u][v]:a[u];
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
    int x,y,c;
    freopen("in.txt","r",stdin);
    while(scanf("%d%d%d",&n,&f,&d)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            cap[0][i]=2;
            cap[i][n+i*2-1]=1;
            cap[i][n+i*2]=1;
            scanf("%d%d",&x,&y);
            for(int j=0;j<x;j++)
            {
                scanf("%d",&c);
                cap[n+i*2-1][3*n+c]=1;
            }
            for(int j=0;j<y;j++)
            {
                scanf("%d",&c);
                cap[n+i*2][3*n+f+c]=1;
            }
        }
        for(int i=3*n+1;i<=3*n+f;i++)
        {
            cap[i][3*n+f+d+1]=1;
        }
        for(int i=3*n+f+1;i<=3*n+f+d;i++)
        {
            cap[i][3*n+f+d+1]=1;
        }
        for(int i=0;i<=3*n+f+d+1;i++)
        {
            for(int j=0;j<=3*n+f+d+1;j++)
            {
                if(cap[i][j]>0)
                    printf("cap[%d][%d]=%d\n",i,j,cap[i][j]);
            }
        }
        int ans=maxFlow(0,3*n+f+d+1);
        if(ans%2==0) ans/=2;
        else ans=(ans-1)/2;
        printf("%d\n",ans);
    }
    return 0;
}
