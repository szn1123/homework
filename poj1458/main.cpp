#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char x[5001],y[5001];
short dp[5001][5001];
int main()
{
    int n;
    while(cin>>n)
    {
        scanf("%s",x);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
         y[n-i-1]=x[i];
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i%2][j]=dp[(i-1)%2][j-1]+1;
            }
            else dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);

        }
        cout<<n-dp[n%2][n]<<endl;
    }
    return 0;
}
