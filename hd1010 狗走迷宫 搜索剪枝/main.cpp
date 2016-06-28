#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char map[10][10];
bool vis[10][10];
int m,n;
struct node
{
    int x,y,t;
};
int xx[4]={1,-1,0,0},
    yy[4]={0,0,1,-1};
bool ans;
void bfs(int x,int y,int t)
{
    queue<node>Q;
    node a,next;
    a.x=x;
    a.y=y;
    a.t=t;
    vis[a.x][a.y]=1;
    Q.push(a);
    while(!Q.empty())
    {
        a=Q.front();
        Q.pop();
        if(t==0)
        {
            if(map[a.x][a.y]=='D')
            {
                ans=1;
                return;
            }
            return;
        }
        for(int i=0;i<4;i++)
        {
            next=a;
            next.x+=xx[i];
            next.y+=yy[i];
            if(next.x>=0&&next.y>=0&&
               next.x<n&&next.y<m&&map[next.x][next.y]=='.')
               {
                   vis[next.x][next.y]=1;
                   next.t=a.t+1;
                   Q.push(next);
               }
        }
    }

}
int main()
{
    int t;
    ans=0;
    //int w=3;
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&t);
    while(n!=0)
    {cout<<"n="<<n<<"m="<<m<<"t="<<t<<endl;
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        int sx,sy;
        getchar();
        for(int i=0;i<n;i++)
        {
             for(int j=0;j<m;j++)
            {
                scanf("%c",&map[i][j]);
                printf("%c",map[i][j]);
                if(map[i][j]=='S')
                {
                    sx=i;sy=j;
                }
            }
            getchar();
            printf("\n");
        }

        bfs(sx,sy,t);
        if(ans==1)
            printf("YES\n");
        else printf("NO\n");
        scanf("%d%d%d",&n,&m,&t);
    }
    return 0;
}
