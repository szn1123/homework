#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 10000000
using namespace std;
const int maxn =1000+10;
char a[maxn][maxn];
char b[maxn];
int dp[maxn][maxn];
int main()
{
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
                scanf("%s",&a[i]);printf("%s\n",a[i]);
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j]=inf;
        int x=0;
        dp[0][0]=a[0][0]-'0';b[x]=a[0][0];x++;
        for(int k=0;k<2;k++)
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0&&dp[i-1][j]+a[i][j]-'0'<dp[i][j])
                {
                    dp[i][j]=dp[i-1][j]+a[i][j]-'0';
                    b[x]=a[i][j];
                }


                if(j-1>=0&&dp[i][j-1]+a[i][j]-'0'<dp[i][j])
                {
                    dp[i][j]=dp[i][j-1]+a[i][j]-'0';
                    b[x]=a[i][j];
                }
                if(i+1<n&&dp[i+1][j]+a[i][j]-'0'<dp[i][j])
                {
                    dp[i][j]=dp[i+1][j]+a[i][j]-'0';
                    b[x]=a[i][j];
                }
                if(j+1<m&&dp[i][j+1]+a[i][j]-'0'<dp[i][j])
                {
                    dp[i][j]=dp[i][j+1]+a[i][j]-'0';
                    b[x]=a[i][j];
                }
            }
            x++;
        }
        bool flag=0;
        for(int i=0;i<x;i++)
        {
            if(flag==0&&b[i]=='0') continue;
            printf("%c",b[i]);
        }
        printf("\n");

    }
    return 0;
}
