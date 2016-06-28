#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 10005;
struct Node{
    int v;int w;
        Node(int v,int w){this->v=v;this->w=w;}
};
bool vis[MAXN];
int dp[MAXN][2];
vector<Node>a[MAXN];
int dfs1(int u)
{
    vis[u]=1;
  //  dp[u][0]=0;//buzhidaoweisha
    for(int i=0;i<a[u].size();i++)
    {
        int v = a[u][i].v;
        int w = a[u][i].w;
        if(vis[v]) continue;
        if(dfs1(v)+w>dp[u][0]) dp[u][0]=dfs1(v)+w;
        //dp[u][0]=max(dp[u][0],dfs1(v)+w);
        //printf("dp[%d][0]=%d\n",u,dp[u][0]);
    }
    return dp[u][0];
}
void dfs2(int u)
{
    vis[u]=1;
    int max1=0,max2=0,tmp,v1=0,v2=0;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i].v;
        int w=a[u][i].w;
        if(vis[v]) continue;
        tmp = dp[v][0]+w;
        if(tmp>max1)
        {
            max2=max1;v2=v1;
            max1=tmp;v1=v;
        }
        else if(tmp==max1||tmp>max2)
        {
            v2=v;
            max2=tmp;
        }

    }
    if(u!=1)
    {
        int tmp=dp[u][1];
        int v=-1;
         if(tmp>max1)
        {
            max2=max1;v2=v1;
            max1=tmp;v1=v;
        }
        else if(tmp==max1||tmp>max2)
        {
            v2=v;
            max2=tmp;
        }
    }
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i].v;
        int w=a[u][i].w;
        if(vis[v])continue;
        if(v==v1) dp[v][1]=max2+w;
        else dp[v][1]=max1+w;
       // cout<<"dp["<<u<<"][1]="<<dp[u][1]<<endl;
        dfs2(v);
    }


}
int main()
{
    int n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        int v,w;
        for(int i=1;i<=n;i++) a[i].clear();
        for(int u=2;u<=n;u++)
        {
            scanf("%d%d",&v,&w);
            a[v].push_back(Node(u,w));
            a[u].push_back(Node(v,w));
        }
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        dfs1(1);
        memset(vis,0,sizeof(vis));
        dfs2(1);
        for(int i=1;i<=n;i++)
        {
            int ans;
            if(dp[i][0]>dp[i][1]) ans=dp[i][0];
            else ans=dp[i][1];
            //int ans=max(dp[i][0],dp[i][1]);
            printf("%d\n",ans);
        }
    }
    return 0;
}
