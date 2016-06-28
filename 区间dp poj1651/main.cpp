#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 20000000
using namespace std;
const int MAXN = 100+10;
int dp[MAXN][MAXN];
int num[MAXN];
int main()
{
    int n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        memset(dp,0,sizeof(0));
        for(int l=2;l<n;l++)
        {
            for(int i=1;i<n;i++)
            {
                int j=i+l;
                if(j>n) break;
                dp[i][j]=inf;
                for(int k=i+1;k<j;k++)
                {
                    if(dp[i][j]>dp[i][k]+dp[k][j]+num[i]*num[k]*num[j])
                    {
                        dp[i][j]=dp[i][k]+dp[k][j]+num[i]*num[k]*num[j];
                    }

                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
