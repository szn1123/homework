#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int l[50005];
int r[50005];
int a[50005];
int main()
{

    int t,n;
    int ans;
   // freopen("in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        l[0]=a[0];
        for(int i=1;i<n;i++)
        {
            if(l[i-1]<0)
                l[i]=a[i];
            else
                l[i]=l[i-1]+a[i];

        }
        for(int i=1;i<n;i++)
            l[i]=max(l[i-1],l[i]);
        r[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
            if(r[i+1]<0)
                r[i]=a[i];
            else r[i]=r[i+1]+a[i];
        for(int i=n-2;i>=0;i--)
            r[i]=max(r[i],r[i+1]);
        ans=-100000000;
        for(int i=1;i<n;i++)
            ans=max(l[i-1]+r[i],ans);
        printf("%d\n",ans);
    }
    return 0;
}
