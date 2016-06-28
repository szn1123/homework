#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[20][15][3];//0noting，1 0&&以1结尾，2含有13
int a[20];
int dfs(int pos,int mod,int s,bool lim)
{
    if(pos<=0)
    {
       if(mod==0&&s==2)
        return 1;
       return 0;
    }
    if(!lim&&dp[pos][mod][s]!=-1)//有上限也需要再次访问
        return dp[pos][mod][s];
    int num;
    if(lim==0) num=9;
    else num=a[pos];
    int ans=0;
    int s1,mod1;bool lim1=0;
   // s1=s;
    for(int i=0;i<=num;i++)
    {

        mod1=(mod*10+i)%13;
        s1=s;//要每次更新s
        if(s==0&&i==1) s1=1;
        if(s==1&&i!=1&&i!=3) s1=0;
        if(s==1&&i==3) s1=2;
        //~~

        if(lim==1&&i==num) lim1=1;
        ans+=dfs(pos-1,mod1,s1,lim1);
    }
   // printf("aa");
    if(!lim)//有上限的情况不同
        dp[pos][mod][s]=ans;
    return ans;
}
int main()
{
    int n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        memset(a,0,sizeof(a));
        //printf("n=%d\n",n);
        int len=0;
        while(n)
        {
            a[++len]=n%10;
            n/=10;
        }
        printf("%d\n",dfs(len,0,0,1));
    }
    return 0;
}
