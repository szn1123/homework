#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 15000
#define lson rt<<1,left,m
#define rson rt<<1|1,m+1,right
int sum[MAXN<<2],level[MAXN<<2];
void update(int rt,int left,int right,int x)
{
    sum[rt]++;
    if(left==right) return;
    int m=(left+right)>>1;
    if(x<=m) update(lson,x);
    else  update(rson,x);

}
int query(int rt,int left,int right,int l,int r)
{
    if(left==l&&right==r) return sum[rt];
    int m=(left+right)>>1;
    if(r<=m) return query(lson,l,r);
    else if(l>m) return query(rson,l,r);
    else return query(lson,l,m)+query(rson,m+1,r);
}
int main()
{
    int n;
   while(cin>>n)
   {
       int x,y;
       int i;
       memset(sum,0,sizeof(sum));
       memset(level,0,sizeof(level));
       for(i=0;i<n;i++)
       {
           cin>>x>>y;
           ++x;
           ++level[query(1,1,MAXN,1,x)];
           update(1,1,MAXN,x);
       }
       for(i=0;i<n;i++)
       cout<<level[i]<<endl;

   }
    return 0;
}
