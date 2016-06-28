#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int ans1,ans2;
    int m,n,t1,t2,t3,t4;
    while(scanf("%d%d%d%d%d%d",&n,&m,&t1,&t2,&t3,&t4)!=EOF)
    {
        ans1=(n-1)*t4;
        int abs;
        if(m>n) abs=m-n;
        else abs=n-m;
        ans2=abs*t1+t2+t3+(n-1)*t1;
        if(ans1>ans2) printf("%d\n",ans2);
        else printf("%d\n",ans1);
    }
    return 0;
}
