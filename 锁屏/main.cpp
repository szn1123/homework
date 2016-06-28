#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
int vis[10],ans[10],a[10],lala[500000][10];
int ex,sum;
bool test(int x,int y)
{
    if(vis[2]==0&&x==1&&y==3||vis[2]==0&&x==3&&y==1) return 0;
    else if(vis[4]==0&&(x==1&&y==7||x==7&&y==1)) return 0;
    else if(vis[8]==0&&(x==9&&y==7||x==7&&y==9)) return 0;
    else if(vis[6]==0&&(x==3&&y==9||x==9&&y==3)) return 0;
    else if(vis[5]==0&&(x==1&&y==9||x==9&&y==1||
                        x==4&&y==6||x==6&&y==4||
                        x==3&&y==7||x==7&&y==3||
                        x==2&&y==8||x==8&&y==2))  return 0;
    else return 1;
}
void dfs(int p,int n)
{

    if(p==n)
    {
        for(int i=0;i<n;i++)
        {
            lala[sum][i]=ans[i];
           // cout<<ans[i]<<" ";
        }
       // cout<<endl;
        sum++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[a[i]]==0&&(p==0||test(ans[p-1],a[i])==1))
        {
            ans[p]=a[i];//printf("ans[%d]=%d\n",p,ans[p]);
            //printf("Ex=%d\n",ex);
            vis[a[i]]=1;

            dfs(p+1,n);
            vis[a[i]]=0;
        }
    }
}
int main()
{
    int t,n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            sum=0;
            memset(a,0,sizeof(a));
            memset(lala,0,sizeof(0));
            memset(vis,0,sizeof(vis));
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                //cout<<a[i]<<" ";
               // cout<<endl;

            }
            sort(a,a+n);

            ex=0;
            dfs(0,n);
            printf("%d\n",sum);
            for(int i=0;i<sum;i++)
            {
                printf("%d",lala[i][0]);
                   for(int j=1;j<n;j++)
                {
                    printf(" %d",lala[i][j]);
                }
                printf("\n");
            }


        }
    }
    return 0;
}
