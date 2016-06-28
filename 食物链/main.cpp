#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=50000+100;
int n,m;
int father[maxn],vis[maxn];
int find(int p)
{
    if(father[p]==p) return p;
    father[p]=find(father[p]);
    return(father[p]);
}
int main()
{
    int a,b,c;
    while(cin>>n>>m)
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) father[i]=i;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b>>c;
            find(b);
            find(c);
            if(vis[b]==0||vis[c]==0)
            {
                if(a==1) father[father[b]]=father[c];
                else if(a==2)
            }
        }
    }


    return 0;
}
