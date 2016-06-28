#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[50];
int b[50];
int main()
{
    int t,n,q[50];
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        memset(s,0,sizeof(s));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        int x=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&q[i]);
            if(i==0)
            {
                for(int j=0;j<q[i];j++)
                {
                    s[x++]='(';
                }
            }
            else
            {
                for(int j=0;j<q[i]-q[i-1];j++)
                {
                    s[x++]='(';
                }
            }
            s[x++]=')';
        }
        bool flag=0;
        for(int i=0;i<n*2;i++)
        {
           // printf("%c",s[i]);
            if(s[i]==')')
            {
                int y=0;
                for(int j=i-1;j>=0;j--)
                {
                    if(s[j]=='(')
                    {
                         y++;
                         if(b[j]==0)
                         {
                             if(flag==0)
                             {
                                 printf("%d",y);
                                 flag=1;
                                 b[j]=1;
                                 break;
                             }
                             else
                             {
                                 printf(" %d",y);
                                 b[j]=1;
                                 break;
                             }

                         }

                    }

                }
            }
        }

        printf("\n");

    }
    return 0;
}
