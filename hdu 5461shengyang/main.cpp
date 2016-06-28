#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long ai[10000010],bj[10000050];
int main()
{
    int T;
    long long n,a,b;
    long long ans1,ans2,ans,x;
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%lld%lld%lld",&n,&a,&b);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            ai[i]=a*x*x;
            bj[i]=b*x;
        }
        int w;
        long long m1,m2;
        m1=-1e18;m2=-1e18;
        for(int i=0;i<n;i++)
        {
            if(ai[i]>m1)
            {
                m1=ai[i];
                w=i;
            }
        }
        for(int j=0;j<n;j++)
        {
            if(bj[j]>m2&&w!=j)
            {
                m2=bj[j];
            }
        }
        ans1=m1+m2;
        m1=-1e18;m2=-1e18;
          for(int i=0;i<n;i++)
        {
            if(bj[i]>m1)
            {
                m1=bj[i];
                w=i;
            }
        }
        for(int j=0;j<n;j++)
        {
            if(ai[j]>m2&&w!=j)
            {
                m2=ai[j];
            }
        }
        ans2=m1+m2;
        if(ans1>ans2) printf("Case #%d: %lld\n",t,ans1);
        else printf("Case #%d: %lld\n",t,ans2);
    }
    return 0;
}
