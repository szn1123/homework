#include <iostream>
#include <cstdio>
using namespace std;

int d[1002],n,m;
int edges[1005][1005];
int queue[1000001];
#define MAX 999999999
#define N 1001
void dijkstra(int v)
{
        int i,j;
        bool s[N]={false};
        for(i=1;i<=n;i++)
                d[i]=edges[v][i];
        d[v]=0;s[v]=true;
        for(i=1;i<n;i++)
        {
                int temp=MAX;
                int u=v;
                for(j=1;j<=n;j++)
                        if((!s[j])&&(d[j]<temp))
                        {
                                u=j;
                                temp=d[j];
                        }
                        s[u]=true;
                        for(j=1;j<=n;j++)
                                if((!s[j])&&(edges[u][j]<MAX)&&(d[u]+edges[u][j])<d[j])
                                        d[j]=d[u]+edges[u][j];
        }

}

int main()
{
    int i,j,a,b,c;
    freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdin);
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        for(i=0;i<=1000;i++){
            for(j=0;j<=i;j++)
            {
                edges[i][j]=MAX;
                edges[j][i]=MAX;
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(edges[a][b]>c){
                edges[a][b]=c;
                edges[b][a]=c;
            }
        }

      //  SPFA(1);
        dijkstra(1);
        printf("%d\n",d[n]);
    }
    return 0;
}

