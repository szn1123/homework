#include <iostream>
#include <cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int dp[1005];
int a[1005];
int main()
{
    int n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        dp[1]=1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int m=0;
            for(int j=1;j<i;j++)
            {

                if(a[j]<a[i])
                m=max(m,dp[j]);
            }
            dp[i]=m+1;
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);


    }
    return 0;
}
