#include <iostream>
#include <cstdio>
#include <cstring>
#define m 1000000007
using namespace std;
long long l,r;
int a[20];
long long dp[20][10][10][2];//0:nothing,1:7
int dfs(long long num,int pos,int sum,int mod,int s,int lim)
{
    printf("aaa=%I64d pos=%d s=%d lim=%d ",num,pos,s,lim);
   // if(num==8)
        printf("\ndp=%I64d\n",dp[pos][sum][mod][s]);
    if(pos<=0)
    {
        if(mod==0||s==1||sum==0)
        {

            return 0;
        }
        printf("num=%I64d\n",num);
        return (num%m)*(num%m)%m;
    }
    if(!lim&&dp[pos][sum][mod][s]!=-1)
        return dp[pos][sum][mod][s];
    int n;
    n=lim?a[pos]:9;
    long long ans=0;
    int sum1,mod1,s1,lim1=0;
    long long num1;
    for(int i=0;i<=n;i++)
    {
        num1=(num*10+i)%m;
        sum1=(sum+i)%7;
        mod1=(mod%10+i)%7;
        s1=s;
        if(i==7&&s==0) s1=1;

        if(lim==1&&i==n) lim1=1;
        printf("aa=%I64d i=%d pos=%d s=%d ",num1,i,pos,s);
        ans+=dfs(num1,pos-1,sum1,mod1,s1,lim1);
    }
    if(!lim)
        dp[pos][sum][mod][s]=ans;
    return ans;

}

int main()
{
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        memset(a,0,sizeof(a));
        scanf("%I64d%I64d",&l,&r);
        int len=0;
        l--;
        while(l)
        {
            a[++len]=l%10;
            l/=10;
        }
        long long ans1=dfs(0,len,0,0,0,1);
        len=0;
        memset(dp,-1,sizeof(dp));
        memset(a,0,sizeof(a));
        while(r)
        {
            a[++len]=r%10;
            r/=10;
        }
        long long ans2=dfs(0,len,0,0,0,1);
        printf("%I64d\n",ans2-ans1);

    }
    return 0;
}
