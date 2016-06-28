#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define LL long long

const LL maxm=1e7;
LL m1[maxm];
LL m2[maxm];
LL n,a,b;
LL dfs(LL *c1,LL *c2)
{
    LL ans1,ans2;
    LL M1=-maxm*maxm;
    LL w;
    for(LL i=0;i<n;i++)
    {
        if(c1[i]>M1)
        {
            M1=c1[i];
            w=i;
        }
    }
  LL  M2=-maxm*maxm;
    for(LL i=0;i<n;i++)
    {
        if(c2[i]>M2&&i!=w)
        {
            M2=c2[i];
        }
    }

    return ans1;


}
int main()
{
    LL t;
    LL k=1;
    freopen("in.txt","r",stdin);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&a,&b);
        LL temp;
        for(LL i=0;i<n;i++)
        {
            scanf("%lld",&temp);
            m1[i]=temp*temp*a;
            m2[i]=temp*b;
        }
        printf("Case #%lld: %lld\n",k++,dfs(m1,m2));
    }
    return 0;
}
