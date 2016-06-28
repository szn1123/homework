#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int haha[100010];
int ct[100010];
struct Node{
    int l;
    int d;
}node[100010];
int cmp(Node a,Node b){
    return a.d<b.d;//或者其他

}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(haha,0,sizeof(haha));
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&node[i].l);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&node[i].d);
            sum+=node[i].d;
        }
        sort(node,node+n,cmp);
       // for(int i=0;i<n;i++)
        //    printf("%d %d\n",node[i].l,node[i].d);
        for(int i=0;i<n;i++)
        {
            haha[node[i].l]+=node[i].d;
            ct[node[i].l]+=1;
        }
        int max=0; int x=0;
        for(int i=0;i<100000;i++)
        {
            if(max<haha[i])
            {
                max = haha[i];
                x = i;
            }
        }
        int j=0;
        for(int i=0;i<ct[x]-1&&j<n;j++)
        {
            if(node[i].l<x)
            {
                max+=node[i].d;
                i++;
            }
        }
        int ans = sum - max;
        printf("%d %d %d\n",sum,max,ans);

    }
    return 0;
}
