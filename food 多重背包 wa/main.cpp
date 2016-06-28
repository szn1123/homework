#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int inf=10000000;
int size[210],en[210],pre[210];
int carry[210],cost[210],z[210];
int f1[50050],f2[50050];
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int main()
{
    int t,n,m,p;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&p);
        int maxp=0;
        int countn=0,countm=0;
        int s,e,pp;

        while(n--)
        {
            scanf("%d%d%d",&e,&s,&pp);
            maxp+=e*pp;
            for(int k=1;k<=pp;k<<=1)
            {
                en[countn]=k*e;
                size[countn++]=k*s;
                //printf("en[%d]=%d size[%d]=%d\n",countn-1,en[countn-1],countn-1,size[countn-1]);
                pp-=k;
            }
            if(pp>0)
            {
                en[countn]=pp*e;
                size[countn++]=pp*s;
            }
        }
        for(int i=0;i<=maxp;i++)
        {
            f1[i]=inf;
        }
        f1[0]=0;
       // printf("maxp=%d\n",maxp);
        for(int i=0;i<countn;i++)
        {// printf("aaa");

            for(int j=maxp;j>=en[i];j--)
            {// printf("aaa");
                f1[j]=min(f1[j],f1[j-en[i]]+size[i]);
            }
        }
        int nsize=f1[p];
        for(int i=p;i<=maxp;i++)
        {

            nsize=min(f1[i],nsize);
        }
        //printf("%d\n",nsize);
        int maxz=0;

        int cr,ct,zz;
        while(m--)
        {
            scanf("%d%d%d",&cr,&ct,&zz);
            maxz+=ct*zz;
            for(int k=1;k<=zz;k<<=1)
            {
                carry[countm]=k*cr;
                cost[countm++]=k*ct;
                zz-=k;
            }
            if(zz>0)
            {
                carry[countm]=zz*cr;
                cost[countm++]=zz*ct;
            }
        }
        for(int i=0;i<=maxz;i++)
        {
            f2[i]=inf;
        }
        f2[0]=0;
        for(int i=0;i<countm;i++)
        {
            for(int j=maxz;j>=carry[i];j--)
            {
                f2[j]=min(f2[j],f2[j-carry[i]]+cost[i]);
            }
        }
        int ans=inf;
        for(int i=nsize;i<=maxz;i++)
        {
            ans=min(ans,f2[i]);
        }






        if(ans==inf) printf("TAT\n");
        else
        printf("%d\n",ans);

    }
    return 0;
}
