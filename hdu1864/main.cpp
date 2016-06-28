#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[35];
int dp[3000050];
double xx;
char s;
int main()
{
    double q;
    int n,m;
    freopen("in.txt","r",stdin);
    scanf("%lf%d",&q,&n);


    while(n!=0)
    {
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        int qq=(int)(q*100);//printf("qq=%d\n",qq);
        int x=0;//printf("%f %d\n",q,n);
        for(int i=1;i<=n;i++)
        {
            bool flag=1;
            scanf("%d",&m);//printf("m=%d\n",m);
            int  sum=0;
            int A=0,B=0,C=0;
            for(int j=1;j<=m;j++)
            {
                getchar();
                scanf("%c",&s);//printf("s=%c\n",s);
                getchar();
                scanf("%lf",&xx);
                a[x]=(int)(xx*100);

                if(s=='A'||s=='B'||s=='C')
                {

                    if(s=='A') A+=a[x];
                    else if(s=='B') B+=a[x];
                    else C+=a[x];
                    if(A>60000||B>60000||C>60000) {flag=0;break;}
                   // printf("a[%d]=%f\n",x,a[x]);
                }
                else
                {
                    flag=0;
                    break;
                }

            }
            if(A+B+C<=100000&&flag==1)
            {
                a[x++]=A+B+C;

            }
           // printf("a[%d]=%d\n",x-1,a[x-1]);

        }
        for(int i=0;i<x;i++)
        {
            for(int j=qq;j>=a[i];j--)
            {
                if(dp[j-a[i]]+a[i]>dp[j])
                    dp[j]=dp[j-a[i]]+a[i];
            }
        }
        double ans=(double)dp[qq];
        printf("%.2lf\n",ans/100.0);
        scanf("%lf%d",&q,&n);

    }
    return 0;
}
