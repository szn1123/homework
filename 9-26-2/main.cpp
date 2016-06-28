#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define mod 1000000007
using namespace std;
struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
    int v;
}a[10100];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int blank;
struct node2
{
    int v;
    int c;
}map[10010][10010];
int mzx;
int sum[10010][12];//最大为v的第c层有多少个
int m,n,h,w;
struct node3
{
    int c;
    int v;
}mz[10];
long long cal(int ceng,int cnt,int v,int mm)
{
    int rest=mm-cnt;
    long long ans;
    long long a1=pow(v,cnt),a2=pow(v-1,cnt),a3=pow(v,rest);
    ans=(a1-a2)%mod*a3%mod;
    if(ceng==1)
    {
        ans+=(a1-a2)%mod;

    }

        ans+=cal(ceng-1,sum[v][ceng-1],v,mm)%mod;

     return ans;
}
long long solve()
{
    long long ans;
    for(int i=0;i<=mzx;i++)
    {
        for(int j=1;j<=mz[i].c;j++)
            sum[mz[i].v][11]+=sum[mz[i].v][j];
        blank-=sum[mz[i].v][11];
        ans*=cal(mz[i].c,sum[mz[i].v][mz[i].c],mz[i].v,sum[mz[i].v][11])%mod;
        long long a1=pow(m,blank);
        ans*=a1%mod;
    }
    return ans;

}
void pre()
{
    for(int i=0;i<n;i++)
        {

            if(i==0) mz[i].v=a[i].v;
            else{if(a[i].v!=mz[mzx].v) mz[++mzx].v=a[i].v;}
            if(a[i].v==1)
            for(int x=a[i].x1;x<=a[i].x2;x++)
            {
                for(int y=a[i].y1;y<=a[i].y2;y++)
                {
                    map[x][y].v=1;
                }
            }
            else
            {
                  for(int x=a[i].x1;x<=a[i].x2;x++)
                {
                    for(int y=a[i].y1;y<=a[i].y2;y++)
                    {
                        if(map[x][y].v==0)
                        {
                            map[x][y].v=a[i].v;
                            map[x][y].c++;
                            mz[mzx].c=max(mz[mzx].c,map[x][y].c);
                            sum[a[i].v][map[x][y].c]++;

                        }
                        else if(map[x][y].v==a[i].v)
                        {
                            mz[mzx].c++;
                            map[x][y].c++;
                            sum[a[i].v][map[x][y].c]++;
                            sum[a[i].v][map[x][y].c-1]--;
                        }

                    }
                }
            }
        }
}
int main()
{
    int T;
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d%d%d",&h,&w,&m,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&a[i].v);
        }
        blank=h*w;
        sort(a,a+n,cmp);
        memset(map,0,sizeof(map));
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        memset(mz,0,sizeof(mz));
        mzx=0;
        pre();
        long long ans=solve()%mod;
        printf("%I64d\n",ans);

    }
    return 0;
}
