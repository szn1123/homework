#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define MaxInt 100000
double map[105][105],low[105];
int visited[105];
int n;
int prim()
{
    int i,j,pos,min,result=0;
    memset(visited,0,sizeof(visited));
    visited[1]=1;pos=1;
    for(i=1;i<=n;i++)
        if(i!=pos) low[i]=map[pos][i];
    for(i=1;i<n;i++)
    {
        min=MaxInt;
        for(j=1;j<=n;j++)
        {
            if(visited[j]==0&&min>low[j])
            {
                min=low[j];pos=j;

            }

        }
        result+=min;
        visited[pos]=1;
        for(j=1;j<=n;j++)
        {
            if(visited[j]==0&&low[j]>map[pos][j])
                low[j]=map[pos][j];
        }

    }
    return result;
}
double x[105],y[105];
int main()
{
    int i,j;
    cin>>n;
    while(n!=0)
    {
        for(i=1;i<=n;i++)
        cin>>x[i]>>y[i];
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            map[i][j]=map[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
        }
        cout<<prim()<<endl;
        cin>>n;
    }
    return 0;
}
