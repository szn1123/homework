#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[25];
long long n;
long long dp[25][3];//0�����ڣ�1�����ڵ���һλ��9��2����
void pre()
{
    memset(dp,0,sizeof(0));
    dp[0][0]=1;
    for(int i=1;i<=19;i++)
    {
        dp[i][0]=10*dp[i-1][0]-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1]+10*dp[i-1][2];
       // printf("dp[%d][0]=%I64d\ndp[%d][1]=%I64d\ndp[%d][2]=%I64d\n",i,dp[i][0],i,dp[i][1],i,dp[i][2]);
    }
}
int main()
{
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    pre();
    while(t--)
    {
        int len=0;
        memset(a,0,sizeof(a));
         cin>>n;
         n++;//������㷨û����n����������Ҫ+1
         while(n)
         {
             a[++len]=n%10;
             n/=10;
         }
         long long ans=0;
         a[len+1]=0;
         bool flag=0;
         for(int i=len;i>=1;i--)
         {
             ans+=a[i]*dp[i-1][2];
             if(flag) ans+=a[i]*dp[i-1][0];
             if(!flag&&a[i]>4) ans+=dp[i-1][1];
          //   if(!flag&&a[i+1]==4&&a[i]>9)  ans+=dp[i-1][1];
             if(a[i+1]==4&&a[i]==9)
             {
                 flag=1;
                 //ans+=dp[i-1][0];�Ѿ���>4������¼ӹ��� �����ټ�
             }

         }
         cout<<ans<<endl;

    }
    return 0;
}
