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
    return a.d>b.d;//»òÕßÆäËû

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
        //for(int i=0;i<n;i++)
        //    printf("%d %d\n",node[i].l,node[i].d);
        for(int i=0;i<n;i++)
        {
            haha[node[i].l]+=node[i].d;
            ct[node[i].l]+=1;
        }
        int max=0;
        for(int i=1;i<=3;i++)
        {
           // printf("haha[%d]=%d",i,haha[i]);
            if(haha[i]==0) continue;
            for(int j=0,m=0;j<n&&m<ct[i]-1;j++)
            {
                if(node[j].l<i)
                {
                    haha[i]+=node[j].d;
                    m++;
                }

            }
        }

        for(int i=1;i<=100000;i++)
        {
            if(max<haha[i]) max=haha[i];
        }
        int ans = sum - max;
        printf("%d\n",ans);

    }
    return 0;
}
