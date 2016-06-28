#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
    int data;
    int w;
    int e;
}p[1100];
char lu[1100][1100];
int main()
{
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    lu[0][0]='\0';
    while(t--)
    {
        int n;
        memset(p,0,sizeof(p));
        memset(lu,0,sizeof(lu));
        scanf("%d",&n);
        int x;
        for(int i=0;i<n;i++)
        {
            int m=0;int y=0;
            scanf("%d",&x);

            while(1)
            {if(p[m].data==0) break;
                //printf("while x=%d p[%d]=%d w=%d e=%d\n",x,m,p[m].data,p[m].w,p[m].e);
                if(x>p[m].data)
                {
                   // printf("heh");
                    if(p[m].w==0)
                    {
                        p[m].w=i;//printf(" x=%d p[%d]=%d w=%d e=%d\n",x,m,p[m].data,p[m].w,p[m].e);
                        lu[x][y++]='W';//printf("lu[%d][%d]=%c\n",x,y-1,lu[x][y-1]);
                        break;
                    }
                    else
                    {    m=p[m].w;//printf(" x=%d p[%d]=%d w=%d e=%d\n",x,m,p[m].data,p[m].w,p[m].e);
                        lu[x][y++]='W';//printf("lu[%d][%d]=%c\n",x,y-1,lu[x][y-1]);
                    }

                }
                else if(x<p[m].data)
                {
                   // printf("lala");
                    if(p[m].e==0)
                    {
                        p[m].e=i;//printf(" x=%d p[%d]=%d w=%d e=%d\n",x,m,p[m].data,p[m].w,p[m].e);
                        lu[x][y++]='E';//printf("lu[%d][%d]=%c\n",x,y-1,lu[x][y-1]);
                        break;
                    }
                    else
                    {
                        m=p[m].e;//printf(" x=%d p[%d]=%d w=%d e=%d\n",x,m,p[m].data,p[m].w,p[m].e);
                        lu[x][y++]='E';//printf("lu[%d][%d]=%c\n",x,y-1,lu[x][y-1]);
                    }

                }

            }
            lu[x][y]='\0';
            p[i].data=x;//printf("p[%d]=%d w=%d e=%d\n",i,p[i].data,p[i].w,p[i].e);

        }
        int q,a;
        scanf("%d",&q);//printf("q=%d\n",q);
        while(q--)
        {
            scanf("%d",&a);//printf("a=%d\n",a);
            printf("%s",lu[a]);
            printf("\n");
        }
    }
    return 0;
}
