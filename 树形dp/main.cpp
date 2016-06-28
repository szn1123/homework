#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N =6005;
int pre[N],suf[N],root,n;
int dp[N][2];
int haha[N];
void Dp(int root)
{
    int dp0=0,dp1=0;
    if(suf[root]==-1)
    {
        dp[root][0]=0;
        dp[root][1]=haha[root];
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(pre[i]==root)
        {
            Dp(i);
            dp0+=max(dp[i][0],dp[i][1]);
            dp1+=dp[i][0];

        }
    }
    dp[root][0]=dp0;
    dp[root][1]=dp1+haha[root];
}
int main()
{
    int father,child;
   // freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        root=-1;
        memset(haha,0,sizeof(haha));
        memset(dp,0,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        memset(suf,-1,sizeof(suf));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&haha[i]);
        }
        scanf("%d%d",&child,&father);
        while(child!=0&&father!=0)
        {
            pre[child]=father;
            suf[father]=child;
            if(root==-1||child==root) root=father;
            scanf("%d%d",&child,&father);
        }

        Dp(root);
        printf("%d\n",max(dp[root][0],dp[root][1]));
    }
    return 0;
}
