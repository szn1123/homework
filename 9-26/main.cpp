#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int rode[10100];
int main()
{
    int L;
    int n,a,b;
    int T;
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int e=0;int ans=0;
        int l,r;
        memset(rode,0,sizeof(rode));
        scanf("%d%d%d%d",&n,&a,&b,&L);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&l,&r);
            for(int j=l;j<r;j++)
            {
                rode[j]=1;
            }
        }
        for(int i=0;i<L;i++)
        {
            if(rode[i]==0) e+=b;
            else e-=a;
            if(e<0) {ans+=-e;e=0;}
           // printf("e=%d ans=%d\n",e,ans);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
