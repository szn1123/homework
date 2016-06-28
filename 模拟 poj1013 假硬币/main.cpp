#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[10],b[10],c[10];
bool v[15],q[15],z[15],e[15];
int s[15];
int main()
{
    int t,i,j;
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(v,0,sizeof(v));
        memset(q,0,sizeof(q));
        memset(z,0,sizeof(z));
        memset(e,0,sizeof(e));
        for(i=0;i<3;i++)
        {
            scanf("%s%s%s",a,b,c);
            if(strcmp(c,"even")==0)
            {
                for(j=0;j<strlen(a);j++)
                {
                    v[a[j]-'A']=1;
                    v[b[j]-'A']=1;
                    s[a[j]-'A']=1;
                    s[b[j]-'A']=1;
                    e[a[j]-'A']=1;
                    e[b[j]-'A']=1;
                }
            }
            else if(strcmp(c,"up")==0)
            {
                int x=0;
                for(j=0;j<strlen(a);j++)
                {if(e[a[j]-'A']==1) x++;
                   if(e[b[j]-'A']==1) x++;

                   if(v[a[j]-'A']==0)
                    {
                        z[a[j]-'A']=1;
                        v[a[j]-'A']=1;
                    }
                     else
                    {
                        if(q[a[j]-'A']==1)
                        {
                            q[a[j]-'A']=0;
                            e[a[j]-'A']=1;
                            s[a[j]-'A']=1;
                        }
                        if(z[a[j]-'A']==1)
                        {
                            if(s[a[j]-'A']==2)
                                {
                                    s[a[j]-'A']=3;
                                }
                            else
                            s[a[j]-'A']=2;
                        }

                    }
                    if(v[b[j]-'A']==0)
                    {
                        q[b[j]-'A']=1;
                        v[b[j]-'A']=1;
                    }
                     else
                    {
                        if(z[b[j]-'A']==1)
                        {
                            z[b[j]-'A']=0;
                            e[b[j]-'A']=1;
                            s[b[j]-'A']=1;
                        }
                        if(q[b[j]-'A']==1)
                        {
                            if(s[b[j]-'A']==2)
                                {
                                    s[b[j]-'A']=3;
                                }
                            else
                            s[b[j]-'A']=2;
                        }
                    }
                }
                if(x==strlen(a)*2-1)
                {
                    for(j=0;j<strlen(a);j++)
                    {
                        if(e[a[j]-'A']==0) s[a[j]-'A']=1;
                        if(e[a[j]-'A']==0) s[a[j]-'A']=1;
                    }
                }

            }
            else if(strcmp(c,"down")==0)
            {
                int x=0;
                for(j=0;j<strlen(a);j++)
                {
                    if(e[a[j]-'A']==1) x++;
                   if(e[b[j]-'A']==1) x++;
                    if(v[a[j]-'A']==0)
                    {
                        q[a[j]-'A']=1;
                        v[a[j]-'A']=1;

                    }
                    else
                    {
                        if(z[a[j]-'A']==1)
                        {
                            z[a[j]-'A']=0;
                            e[a[j]-'A']=1;
                            s[a[j]-'A']=1;
                        }
                        if(q[a[j]-'A']==1)
                        {
                            if(s[a[j]-'A']==2)
                                {
                                    s[a[j]-'A']=3;
                                }
                            else
                            s[a[j]-'A']=2;
                        }
                    }
                    if(v[b[j]-'A']==0)
                    {
                        z[b[j]-'A']=1;
                        v[b[j]-'A']=1;
                    }
                     else
                    {
                        if(q[b[j]-'A']==1)
                        {
                            q[b[j]-'A']=0;
                            e[b[j]-'A']=1;
                            s[b[j]-'A']=1;
                        }
                        if(z[b[j]-'A']==1)
                        {
                            if(s[b[j]-'A']==2)
                                {
                                    s[b[j]-'A']=3;
                                }
                            else
                            s[b[j]-'A']=2;
                        }
                    }
                }
                 if(x==strlen(a)*2-1)
                {
                    for(j=0;j<strlen(a);j++)
                    {
                        if(e[a[j]-'A']==0) s[a[j]-'A']=1;
                        if(e[a[j]-'A']==0) s[a[j]-'A']=1;
                    }
                }

            }

        }
        int x=0;
        int ans[15],ans2[15];
        memset(ans,0,sizeof(ans));
        for(i=0;i<12;i++)
        {
            if(e[i]==0&&(q[i]==1||z[i]==1))
            {
                ans[x++]=i;
                //printf("ans[%d]=%c\n",x,'A'+i);

            }
        }
        int y=0;
        if(x==1)
        {
            printf("%c is the counterfeit coin and it is ",'A'+ans[0]);
             if(q[ans[0]]==1)
                {
                    printf("light.\n");
                }
                else if(z[ans[0]]==1)
                {
                    printf("heavy.\n");
                }
        }
        else
        {
            for(i=0;i<x;i++)
            {
                if(s[ans[i]]>1) {ans2[y++]=ans[i];}
            }
            if(y==1)
            {
                printf("%c is the counterfeit coin and it is ",'A'+ans2[0]);
             if(q[ans2[0]]==1)
                {
                    printf("light.\n");
                }
                else if(z[ans2[0]]==1)
                {
                    printf("heavy.\n");
                }
            }
            else
            {
                for(i=0;i<y;i++)
                {
                    if(s[ans2[i]]==3)
                    {
                        printf("%c is the counterfeit coin and it is ",'A'+ans2[i]);
             if(q[ans2[i]]==1)
                {
                    printf("light.\n");
                }
                else if(z[ans2[i]]==1)
                {
                    printf("heavy.\n");
                }
                    }
                }
            }
        }
      //  printf("x=%d y=%d\n",x,y);

    }
    return 0;
}
