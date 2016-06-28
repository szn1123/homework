#include <iostream>
#include <cstdio>
using namespace std;
int n;
int map1[105][105],map2[105][105];
void Floyd(int graph[][])
{
    int i,j,k;
    for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        if((graph[i][k]==-1||graph[k][j]==-1)) continue;
        if((graph[i][j]==-1||graph[i][j]>graph[i][k]+graph[k][j]))
        {
            graph[i][j]=graph[i][k]+graph[k][j];
        }
    }
}
int main()
{
    int i,j,k;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {

        }
    }
    return 0;
}
