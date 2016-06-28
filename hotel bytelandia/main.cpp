#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 100+10;
int a[MAXN],b[MAXN];
int sum[1010];
int main()
{
    int t,n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            for(int i=0;i<n;i++)
            {
                scanf("%d",&b[i]);
            }
            sort(a,a+n);
            sort(b,b+n);
            int x=0,y=0;
            int ret=0,ans=0;
            int m=max(a[n-1],b[n-1]);
            for(int i=1;i<=m;i++)
            {
                if(i==a[x])
                {
                    ret++;cout<<"i="<<i<<" ret="<<ret<<endl;
                    x++;
                }
                if(i==b[y])
                {
                    ret--;
                    y++;
                }
                ans=max(ans,ret);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
