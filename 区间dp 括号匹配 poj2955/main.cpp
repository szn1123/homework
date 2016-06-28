#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[125][125];
int main()
{
    char s[125];
    freopen("in.txt","r",stdin);
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='e') break;
        int n=strlen(s);
        memset(dp,0,sizeof(dp));

        for(int l=1;l<n;l++)
        {
            for(int i=0;i<n;i++)
            {
                int j=l+i;
                if(j>=n) break;
                 if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']')
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                    //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
                }
                for(int k=i;k<j;k++)
                {
                    if(dp[i][j]<dp[i][k]+dp[k+1][j])
                    dp[i][j]=dp[i][k]+dp[k+1][j];

                }

            }

        }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
