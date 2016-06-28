#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=10000+10;
const int maxm=100000+100;
const int inf=100000000;
struct node
{
    int to,next,l,c;
}edge[2*maxm];
int box[maxn];
int ent;
int n,m;
void add(int f,int t,int l,int c)
{
    edge[ent].to=t;
    edge[ent].l=l;
    edge[ent].c=c;
    edge[ent].next=box[f];
    box[f]=ent++;
}
int suml,sumc;
int low_dis[maxn],low_cos[maxn];
bool vis[maxn];
void prim()
{   int i,j,minl,minc,next,now;
    for(i=1;i<=n;i++)
        low_cos[i]=low_dis[i]=inf;
    suml=0;sumc=0;
    low_cos[1]=0;low_dis[1]=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;now=1;
    for(i=1;i<n;i++)
    {
        minl=inf;minc=inf;
        next=-1;
        for(j=box[now];j!=-1;j=edge[j].next)
        {
            if(vis[edge[j].to]==0&&edge[j].l<low_dis[edge[j].to])
            {
                low_dis[edge[j].to]=edge[j].l;
                low_cos[edge[j].to]=edge[j].c;
            }
            else if(vis[edge[j].to]==0&&edge[j].l==low_dis[edge[j].to]&&edge[j].c<low_cos[edge[j].to])
            low_cos[edge[j].to]=edge[j].c;
        }
        for(j=1;j<=n;j++)
        {
            if(vis[j]==0&&minl>low_dis[j])
            {
                minl=low_dis[j];minc=low_cos[j];
                next=j;
            }
            else if(vis[j]==0&&minl==low_dis[j]&&minc>low_cos[j])
            {
                minc=low_cos[j];
                next=j;
            }
            //cout<<next<<" ";
        }
       // cout<<endl;
         if(next==-1)
        {
            sumc=-1;suml=-1;
            return;
        }
        sumc+=minc;suml+=minl;
        vis[next]=1;
        now=next;
     }

    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            suml=-1;sumc=-1;
            return;
        }
    }
}
void input()
{
    ent=0;
    memset(box,-1,sizeof(box));
    int f,t,l,c;
    for(int i=0;i<m;i++)
    {
        cin>>f>>t>>l>>c;
        add(f,t,l,c);
        add(t,f,l,c);
    }

}
int main()
{
   // freopen("in.txt","r",stdin);
    while(cin>>n>>m)
    {
        input();
        prim();
        printf("%d %d\n",suml,sumc);
    }

    return 0;
}
