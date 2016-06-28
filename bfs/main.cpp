#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct node{
    int x;
    int y;
    int suger;
    int step;
};
char map[105][105];
int vis[105][105];
int to[4][2]= {1,0,-1,0,0,1,0,-1};
int n,m,sx,sy,ex,ey,ans,step;
int check(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return 1;
    if(vis[x][y] || map[x][y]=='1')
        return 1;
    return 0;
}

int bfs()
{
    int i;
    queue<node> Q;
    node a,next;
    a.x = sx;
    a.y = sy;
    if(map[sx][sy]=='2') a.suger = 1;
    else a.suger = 0;
    a.step = step;
    vis[a.x][a.y]=1;
    Q.push(a);
    while(!Q.empty()&&next.step>=0)
    {
        a = Q.front();
        Q.pop();

        for(i = 0; i<4; i++)
        {
            next = a;
            next.x+=to[i][0];
            next.y+=to[i][1];
            if(check(next.x,next.y))
                continue;
            next.step=a.step-1;

            if(map[next.x][next.y]=='2')
            {
                next.suger=a.suger+1;
                vis[next.x][next.y] = 1;
            }
            Q.push(next);
        }
    }
    int max=a.suger;
    while(!Q.empty())
    {
         a = Q.front();
        Q.pop();
         if(a.suger>max) max = a.suger;
    }
    return max;
}
int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
         scanf("%d%d",&sx,&sy);
         scanf("%d",&step);
          memset(vis,0,sizeof(vis));
          if(map[sx][sy]=='1') ans = 0;
           else ans = bfs();
        printf("%d\n",ans);
    }
    return 0;
}
