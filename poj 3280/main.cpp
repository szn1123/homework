#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define inf 200000000
using namespace std;
const int MAXM = 2000+10;
const int MAXN = 26 + 10;
int dp[MAXM][MAXM];
int z,s,minn[MAXN];
int main()
{
    int m,n;
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(minn,0,sizeof(minn));
        char a[MAXM],x;
        scanf("%s",a);
        for(int i=0;i<n;i++)
        {
            getchar();
            scanf("%c",&x);
            scanf("%d%d",&z,&s);
            minn[x-'a']=min(z,s);

            //printf("s[%d]=%d\n",x-'a',minn[x-'a']);
        }
        for(int i=m-1;i>=0;i--)
        for(int j=i+1;j<m;j++)
        {
            if(a[i]==a[j]) dp[i][j]=dp[i+1][j-1];
            else
            {
              dp[i][j]=min(dp[i+1][j]+minn[a[i]-'a'],dp[i][j-1]+minn[a[j]-'a']);
            }

        }
        printf("%d\n",dp[0][m-1]);
    }
    return 0;
}

