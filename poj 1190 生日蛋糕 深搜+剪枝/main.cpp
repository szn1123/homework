#include <iostream>
#include <cstdio>
#include <cmath>
#define inf 100000000
using namespace std;
int mv[25],ms[25];
int ans;
int N,M;
int get3h(int i)
{
    int ret=i*i*(i+1)*(i+1)/4;
    return ret;
}
void dfs(int m,int v,int mr,int mh,int s)
{
    if(v<mv[m]) return;
    if(s+2*v/mr>=ans) return;//¼ôÖ¦
    if(m==0)
    {
        if(v==0)
            ans=min(ans,s);
        return;
    }
    for(int r=m;r<mr;r++)
    {
        for(int h=m;h<mh;h++)
        {
            if(r*r*h<v/m) continue;
            if(r*r*h>v) break;
            if(m==M) s=r*r;
            dfs(m-1,v-r*r*h,r,h,s+2*r*h);
        }
    }


}
int main()
{
    for(int i=1;i<=20;i++)
    {
        mv[i]=get3h(i);
       // ms[i]=2*i*i+i*i;
    }
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        ans=inf;
        dfs(M,N,sqrt(1.0*N)+1,N/(M*M)+1,0);
        if(ans==inf) printf("0\n");
        else printf("%d\n",ans);

    }
    return 0;
}
