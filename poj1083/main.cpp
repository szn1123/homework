#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
int a[220];
int minn,maxx;
void pushdown(int x,int y)
{
    if(x>y)
    {
        int m=x;
        x=y;
        y=m;
    }
    if(x%2==0) x=x/2;
    else x=x/2+1;
    if(y%2==0) y=y/2;
    else y=y/2+1;
    if(minn>x) minn=x;
    if(maxx<y) maxx=y;
    for(int i=x;i<=y;i++)
    {
        a[i]++;
    }
}
int main()
{
    int t,n,x,y;
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        maxx=200;
        minn=1;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            pushdown(x,y);
        }
        for(int i=minn;i<=maxx;i++)
        {
            if(ans<a[i]) ans=a[i];
        }
        printf("%d\n",ans*10);
    }
    return 0;
}
