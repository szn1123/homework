#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=500+10;
const int inf=10000000;
int map[maxn][maxn];
int vis[maxn];
int low[maxn];
int n;
int prim()
{
    int i,j,pos,min,ans=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;pos=1;
    for(i=1;i<=n;i++)
    {
        if(i!=pos)
            low[i]=map[pos][i];
    }
    for(i=1;i<n;i++)
    {
        min=inf;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0&&min>low[j])
            {
                min=low[j];
                pos=j;
            }
        }
        if(ans<min) ans=min;
        vis[pos]=1;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0&&low[j]>map[pos][j])
                low[j]=map[pos][j];
        }
    }
    return ans;
}
void input()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        cin>>map[i][j];
    }
}
int main()
{
    int t;
    freopen("in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        input();
        cout<<prim()<<endl;
    }
    return 0;
}
