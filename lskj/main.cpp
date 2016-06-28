#include <iostream>
#include <stdio.h>　
#include <cstring>
using namespace std;
const int MAXN = 1000;
int main()
{
    int n;
    int a[MAXN];
    scanf("%d",&n);
    int h[MAXN]; //饼干数
    int maxx[MAXN]; //极大值点
    int minn[MAXN]; //极小值点
    int x = 0,y = 0;
    memset(a,0,sizeof(0));
    memset(h,0,sizeof(0));
    if(n<0) printf("n must>=0!\n");
    else if(n==1) printf("1\n");
    else
    {

        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        if(a[0]<a[1])
        {
            h[0] = 1;
            minn[x++] = 0;
        }
        else maxx[y++] = 0;

         if(a[n-2]>a[n-1]) h[n-1] = 1;
         for(int i=1;i<n-1;i++)
         {
             if(a[i]<a[i-1]&&a[i]>a[i+1])
             {
                  h[i]=1;

             }

         }

         for(int i=1;i<n;i++)
         {
              if(a[i]>a[i-1])
              {
                  h[i]=h[i-1]++;
              }

         }
         for(int i=n-2;i>=0;i--)
         {
             if(a[i]>a[i+1])
             {
                 if(h[i]==0)
                 h[i] = h[i+1]++;
                 else h[i] = h[i]>h[i+1]++?h[i]:h[i+1]++;
             }

         }
         int ans=0;
         for(int i = 0;i<n;i++)
            ans+=h[i];
        printf("%d\n",ans);
    }


    return 0;
}
