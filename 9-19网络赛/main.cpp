#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 10000000;
int main()
{
    int t,b,a,n,x,y;
    int max1,max2,min1,min2,abs,absi,max1i,max2i,min1i,min2i;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        max1=0;max2=0;min1=inf;min2=inf;abs=inf;
        scanf("%d%d%d",&n,&a,&b);
        int ans1,ans2,ans;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x<0) y=-x;
            else y=x;
            if(y<abs)
            {
                abs=y;
                absi=i;
            }
            if(x>max1)
            {
                max1=x;max1i=i;
            }
           else  if(x<=max1&&x>max2)
            {
                max2=x;max2i=i;
            }
            if(x<min1)
            {
                min1=x;min1i=i;
            }
            else if(x>=min1&&x<min2)
            {
                min2=x;min2i=i;
            }

        }
        printf("max1=%d,max2=%d,min1=%d,min2=%d\n",max1,max2,min1,min2);
        if(a>=0&&b>=0)
            {
                if(min1<0&&-min1>max1)
                {
                    ans1=a*min1*min1+b*max1;
                }
                else
                {
                    ans1=a*max1*max1+b*max2;printf("max1=%d,max2=%d\n",max1,max2);
                }
            }
            else if(a>=0&&b<0)
            {

                if(min1<0&&-min1>max1)
                {
                    ans=a*min1*min1+b*min2;
                }
                else
                {
                    ans=a*max1*max1+b*min1;
                }
            }
            else if(a<0&&b>=0)
            {
                if(absi!=max1i)
                {
                    ans=a*abs*abs+b*max1;
                }
                else
                {
                    ans=a*abs*abs+b*max2;
                }
            }
            else if(a<0&&b<0)
            {
                if(absi!=min1i)
                {
                    ans=a*abs*abs+b*min1;
                }
                else
                {
                    ans=a*abs*abs+b*min2;
                }
            }
            printf("%d\n",ans);
    }
    return 0;
}
