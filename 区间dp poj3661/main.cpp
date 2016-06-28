#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 10000+10;
const int MAXM = 500+10;
int dp[MAXN][MAXM];
int dis[MAXN];
int main()
{
    int n,m;
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",&dis[i]);
       dp[1][1]=dis[1];
       dp[1][0]=0;
       for(int i=1;i<n;i++)
       {
          for(int j=0;j<=m&&j<=i;j++)
          {
              if(j==0)
              {
                  dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+dis[i+1]);
                  dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                  //printf("dp1[%d][%d]=%d\n",i+1,j+1,dp[i+1][j+1]);
                 // printf("dp2[%d][%d]=%d\n",i+1,j,dp[i+1][j]);
              }
              else if(j==m)
              {
                 if(i+m<=n)
                 {
                     dp[i+m][j-m]=max(dp[i+m][j-m],dp[i][j]);
                  //printf("dp3[%d][%d]=%d\n",i+m,j-m,dp[i+m][j-m]);
                 }

              }
              else
              {
                  dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+dis[i+1]);
                  if(i+j<=n)
                  dp[i+j][j-j]=max(dp[i+j][j-j],dp[i][j]);
                 // printf("dp4[%d][%d]=%d\n",i+1,j+1,dp[i+1][j+1]);
                  //printf("dp5[%d][%d]=%d\n",i+1,j-1,dp[i+1][j-1]);
              }

          }
       }
       printf("%d\n",dp[n][0]);
    }
    return 0;
}
