#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a[2005],b[2005];
char ans[2005];
int main()
{
    int T;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&T)!=EOF)
    {
        for(int t=1;t<=T;t++)
        {
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            scanf("%s%s",a,b);
            int la,lb;
            la=strlen(a);
            lb=strlen(b);
            memset(ans,0,sizeof(ans));
            int lmin,lmax;
            if(la>lb)
            {
                lmin=lb;lmax=la;
            }
            else
            {
                lmin=la;lmax=lb;
            }
            for(int i=0;i<lmin;i++)
            {
                if(ans[i]+a[la-i-1]-'0'+b[lb-i-1]-'0'>=10)
                {
                    ans[i]+=a[la-i-1]-'0'+b[lb-i-1]-'0'-10;
                    ans[i+1]++;
                }
                else ans[i]+=a[la-i-1]-'0'+b[lb-i-1]-'0';
            }
            if(la>lb)
                for(int i=lmin;i<lmax;i++)
                {
                    if(ans[i]+a[la-i-1]-'0'>=10)
                    {
                        ans[i]+=a[la-i-1]-'0'-10;
                        ans[i+1]++;
                    }
                    else ans[i]+=a[la-i-1]-'0';
                }
            else
             for(int i=lmin;i<lmax;i++)
                {
                    if(ans[i]+b[lb-i-1]-'0'>=10)
                    {
                        ans[i]+=b[lb-i-1]-'0'-10;
                        ans[i+1]++;
                    }
                    else ans[i]+=b[lb-i-1]-'0';
                }
                printf("Case %d:\n",t);
                printf("%s + %s = ",a,b);
                if(ans[lmax]==0)
                {
                    for(int i=lmax-1;i>=0;i--)
                       printf("%c",ans[i]+'0');
                }
                else
                {
                    for(int i=lmax;i>=0;i--)
                        printf("%c",ans[i]+'0');
                }
                puts("");
                if(t!=T) printf("\n");
            }


    }
    return 0;
}
