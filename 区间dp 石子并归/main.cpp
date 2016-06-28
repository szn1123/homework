#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define inf 200000001
using namespace std;
const int MAXN = 200+10;
int dp[MAXN][MAXN];
int sum[MAXN];
int main()
{
    int n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        int a;
        memset(sum,0,sizeof(sum));
        scanf("%d",&sum[1]);
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&a);
            sum[i]=sum[i-1]+a;
        }
        memset(dp,0,sizeof(dp));
        for(int l=2;l<=n;l++)
        {
            for(int i=1;i<=n;i++)
            {
                int j=i+l-1;
                dp[i][j]=inf;
                for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);

            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
