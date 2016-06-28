#include <iostream>
#include <cstdio>
#define mod 530600414
using namespace std;
long long num[500000],sum[500000],len[500000],ans[500000];
int main()
{
    num[1]=1;num[2]=0;
    sum[1]=0;sum[2]=0;
    len[1]=1;len[2]=2;
    ans[1]=0;ans[2]=0;
    for(int i=3;i<=201314;i++)
    {
        num[i]=(num[i-2]+num[i-1])%mod;
        len[i]=(len[i-2]+len[i-1])%mod;
        sum[i]=(sum[i-2]+sum[i-1]+len[i-2]*num[i-1])%mod;
        ans[i]=((ans[i-2]+ans[i-1])%mod+(len[i-2]*num[i-2]%mod-sum[i-2]+mod)*num[i-1]%mod+sum[i-1]*num[i-2]%mod)%mod;
    }
    int T;
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %lld\n",t,ans[n]);
    }
    return 0;
}
