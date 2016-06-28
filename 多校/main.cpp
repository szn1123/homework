#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+10;
int father[maxn];
int sum[maxn];
int main()
{
    int n,k,x,y;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(father,-1,sizeof(father));
        memset(sum,0,sizeof(sum));
        int ans=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            father[y]=x;
            int m;
            m=y;
            while(father[m]!=-1)
            {
                sum[father[m]]++;
                m=father[m];
            }
        }
        for(int i=1;i<=n;i++)
            if(sum[i]==k)
                ans++;
        printf("%d\n",ans);

    }


    return 0;
}
