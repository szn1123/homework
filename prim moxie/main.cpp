#include <iostream>
#include <cstdio>
#include <cstring>
#define MaxInf 10000000
using namespace std;
int map[10005][10005],low[10005],visit[10005],pos;
int a[10005];
int prim()
{
    int i,min=MaxInf;
    int result=0;
    memset(visit,0,sizeof(visit));
    pos=1;visit[1]=1;
    for(i=1;i<=n;i++)
        if(i!=pos) low[i]=map[pos][i];
    for(i=1;i<n;i++)
    {
        if(visit[i]==0&&min>low[i])
           min=low[i];pos=i;
    }
    result+=min;
}
int main()
{
    int n,p,i;
    int s,e,l;
    cin>>n>>p;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<p;i++)
    {
        cin>>s,e,l;
        map[s][e]=map[e][s]=l;
    }


    return 0;
}
