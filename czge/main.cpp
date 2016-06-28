#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[400050],maxn[400050];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        maxn[rt]=sum[rt];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int a,int c,int l,int r,int rt)
{
    if(l==a&&r==a)
    {
        sum[rt]=c;
        maxn[rt]=c;
        return;
    }
    int m=(l+r)>>1;
    if(a<=m) update(a,c,lson);
    else update(a,c,rson);
    pushup(rt);
}
int query2(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
            return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m) ret+=query2(L,R,lson);
    if(m<R) ret+=query2(L,R,rson);
    return ret;
}
int query3(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R) return maxn[rt];
    int m=(l+r)>>1;
    int maxx=0;
    if(L<=m) maxx=max(maxx,query3(L,R,lson));
    if(m<R) maxx=max(maxx,query3(L,R,rson));
    return maxx;
}
int main()
{
    int n,q,a,b,c,i;
    int x;
    while(cin>>n>>q)
    {
        build(1,n,1);
        for(i=0;i<q;i++)
        {
            cin>>x;
            if(x==1)
            {
                cin>>a>>c;
                update(a,c,1,n,1);
            }
            else if(x==2)
            {
              -б╛бо  int ans=query2(a,b,1,n,1);
                cout<<ans<<endl;
            }
            else
            {
                cin>>a>>b;
                int ans=query3(a,b,1,n,1);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
