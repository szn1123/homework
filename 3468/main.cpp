#include <iostream>
#include <cstdio>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[100050],lazy[100050];
int n;
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]); return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void pushdown(int rt,int m)
{
    if(lazy[rt])
    {
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        sum[rt<<1]+=(m-(m>>1))*lazy[rt];
        sum[rt<<1|1]+=(m>>1)*lazy[rt];
        lazy[rt]=0;
    }
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        sum[rt]+=(r-l+1)*c;
        lazy[rt]=c;
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(R>m) ret+=query(L,R,rson);
    return ret;
}
int main()
{
    int q,a,b,c,i;
    while(cin>>n>>q)
    {
        build(1,n,1);
        char x;
        for(i=0;i<q;i++)
        {
             cin>>x;
            if(x=='Q')
            {
                cin>>a>>b;
                int ans=query(a,b,1,n,1);
                cout<<ans<<endl;
            }
            else
            {
                cin>>a>>b>>c;
                update(a,b,c,1,n,1);
            }
        }


    }

    return 0;
}

