#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define inf 1000000000
const int MAXN = 200+20;
int dp[MAXN][MAXN][2];
int next[MAXN][MAXN][2];
int dis[MAXN];
int t[MAXN];
int main()
{
    int n;
   freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&t[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&dis[i]);
       // dp[1][1][0]=0;
       memset(dp,0,sizeof(dp));
        for(int l=2;l<=n;l++)
        {
for(int i=1;i<=n;i++)
            {
                int j=i+l-1;if(j>n) break;
               // printf("dp[%d+1][%d][0]=%d\n",i,j,dp[i+1][j][0]);
                          //  printf("dp[%d+1][%d][1]=%d\n",i,j,dp[i+1][j][1]);
                if(dp[i+1][j][0]+dis[i+1]-dis[i]>=dp[i+1][j][1]+dis[j]-dis[i])
                {
                    dp[i][j][0]=dp[i+1][j][1]+dis[j]-dis[i];
                    next[i][j][0]=1;
                  //  printf("dp[%d][%d][0]=%d\nnext=1\n",i,j,dp[i][j][0]);

                }
                else
                {
                    dp[i][j][0]=dp[i+1][j][0]+dis[i+1]-dis[i];
                    next[i][j][0]=0;
                   // printf("dp[%d][%d][0]=%d\nnext=0\n",i,j,dp[i][j][0]);
                }if(dp[i][j][0]>=t[i]||dp[i][j][1]>inf)
                {
                    dp[i][j][0]=inf;
                 //   printf("dp[%d][%d][0]=%d\n",i,j,dp[i][j][0]);
                }
              //   printf("dp[%d][%d-1][0]=%d\n",i,j,dp[i][j-1][0]);
              //  printf("dp[%d][%d-1][1]=%d\n",i,j,dp[i][j-1][1]);

                if(dp[i][j-1][0]+dis[j]-dis[i]>=dp[i][j-1][1]+dis[j]-dis[j-1])
                {
                    dp[i][j][1]=dp[i][j-1][1]+dis[j]-dis[j-1];
                    next[i][j][1]=1;
                   // printf("dp[%d][%d][1]=%d\nnext=1\n",i,j,dp[i][j][1]);
                }
                else
                {
                    dp[i][j][1]=dp[i][j-1][0]+dis[j]-dis[i];
                    next[i][j][1]=0;
                   // printf("dp[%d][%d][1]=%d\nnext=0\n",i,j,dp[i][j][1]);
                }

                if(dp[i][j][1]>=t[j]||dp[i][j][1]>inf)
                {
                    dp[i][j][1]=inf;
                   // printf("dp[%d][%d][1]=%d\n",i,j,dp[i][j][1]);
                }

            }
        }
        int l,r,m;
        if(dp[1][n][0]<inf)
        {
            printf("1");
            l=2;
            r=n;
            m=next[1][n][0];
        }
        else if(dp[1][n][1]<inf)
        {
            printf("%d",n);
            l=1;
            r=n-1;
            m=next[1][n][1];
        }
        else
        {printf("Mission Impossible\n");continue;}
        while(l<=r)
        {
            if(m==0)
            {
                printf(" %d",l);
                l=l+1;
                m=next[l][r][0];
            }
            else
            {
                printf(" %d",r);
                r=r-1;
                m=next[l][r][1];
            }
        }
        printf("\n");
    }
    return 0;
}
