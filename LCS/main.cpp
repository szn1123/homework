#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[1000],b[1000];
int dp[1050][1050];
int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%s%s",a,b)!=EOF)
    {
        int la = strlen(a);
        int lb = strlen(b);
        int max = 0,maxi=1,maxj=1;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=la;i++)
        {
            for(int j=1;j<=lb;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    if(i==1||j==1)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    if(dp[i][j]>max)
                    {
                        max = dp[i][j];
                        maxi = i;
                        maxj = j;
                    }
                }
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        printf("max=%d\n",max);
        for(int i = maxi-max;i<maxi;i++)
        {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
