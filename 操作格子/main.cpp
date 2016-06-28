#include <iostream>
#include <cstdio>
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
        max[rt]=sum[rt];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
