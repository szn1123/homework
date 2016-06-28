#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <climits>//形如INT_MAX一类的
#define MAX 10500
#define INF 0x7FFFFFFF
# define eps 1e-5
using namespace std;
int par[MAX],n,m,maxedge,cnt;
struct Edge
{
    int s,e;
    int value;
}edge[MAX],index[MAX];
bool cmp(Edge a, Edge b)
{
    return a.value < b.value;
}

int find(int x)//查
{
    while(par[x] != x)
        x = par[x];
    return x;
}
void connect(int a,int b)//并
{
    if(a < b)
    {
        par[b] = a;
    }
    else
    {
        par[a] = b;
    }
}
void kruskal()
{
    int i,j;
    maxedge = 0;
    cnt = 0;
    for(i=1; i<=m; i++)
    {
        int a = find(edge[i].s);
        int b = find(edge[i].e);
        if(a != b)
        {
            connect(a,b);
            if(maxedge < edge[i].value);
                maxedge = edge[i].value;
            cnt ++;
            index[cnt].s = edge[i].s;
            index[cnt].e = edge[i].e;
        }
        if(cnt >= n-1)
            break;
    }
}
int main()
{
   int i,j;
   freopen("in.txt","r",stdin);
   while(scanf("%d%d",&n,&m) != EOF)
   {
       for(i=1; i<=m; i++)
       {
           scanf("%d%d%d",&edge[i].s,&edge[i].e,&edge[i].value);
       }
       sort(edge+1,edge+1+m,cmp);
       for(i=1; i<=n; i++)
       {
           par[i] = i;
       }
       memset(index,0,sizeof(index));
       kruskal();
       printf("%d\n%d\n",maxedge,cnt);
       for(i=1; i<=cnt; i++)
       {
           printf("%d %d\n",index[i].s,index[i].e);
       }
   }
   return 0;
}
