#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double dp[105];
int p[105];
 int n,c,t,l,vr,vt1,vt2;
double run(int i,int j)
{
    double ret = 0;
    if(j!=0)
    {
        ret += t;
    }
        if(p[i]-p[j]<=c)
        {
            ret += (p[i]-p[j])*1.0/vt1;
        }
        else
        {
            ret += c*1.0/vt1 + (p[i]-p[j]-c)*1.0/vt2;
        }

    return ret;
}
int main()
{

    freopen("in.txt","r",stdin);
    while(scanf("%d",&l)!=EOF){
        scanf("%d%d%d",&n,&c,&t);
        scanf("%d%d%d",&vr,&vt1,&vt2);
        memset(dp,0,sizeof(dp));
        p[0] = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            //printf("p[%d]=%d\n",i,p[i]);
            dp[i] = (double)p[i]*1.0/vt2;
           // printf("dp[%d]=%f\n",i,dp[i]);
        }
        p[n+1] = l;
        dp[n+1] = (double)l*1.0/vt2;
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i] = min(dp[i],dp[j]+run(i,j));
               // printf("dp[%d]=%f\n",i,dp[i]);
            }
        }
        if(dp[n+1]<(double)l/vr)
        {
            printf("What a pity rabbit!\n");
        }
        else printf("Good job,rabbit!\n");



    }
    return 0;
}
