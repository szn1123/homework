#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m,n;
char map[10][10];
bool vis[10][10];
int fx[4]={1,-1,0,0},
    fy[4]={0,0,1,-1};
bool ans;
void dfs(int x,int y,int t)
{
    if(ans==1) { return;}
    if(t<0) return;
        vis[x][y]=1;
    if(map[x][y]=='D'&&t!=0) return;
        if(t==0)
        {
            if(map[x][y]=='D') ans=1;
            return;
        }
        int newx,newy;
        for(int i=0;i<4;i++)
        {
            newx=x+fx[i];
            newy=y+fy[i];
            if(newx>=0&&newx<n&&newy>=0&&newy<m&&
               vis[newx][newy]==0&&map[newx][newy]!='X')
            {
               // t--;
              //  printf("map[%d][%d]=%c t=%d\n",newx,newy,map[newx][newy],t);
                dfs(newx,newy,t-1);
                vis[newx][newy]=0;
               // t++;
            }
        }


}
int main()
{
    freopen("in.txt","r",stdin);
    int t,sx,sy,dx,dy;
    scanf("%d%d%d",&n,&m,&t);
    while(m!=0)
    {
        getchar();
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j]=='S')
                {
                    sx=i;sy=j;
                }
                else if(map[i][j]=='D')
                {
                    dx=i;dy=j;
                }
            }
            getchar();
        }
        int l=dx-sx+dy-sy;
        if(l<0) l=-l;
        ans=0;
       // printf("sx=%d sy=%d\n",sx,sy);
        if(l%2==0&&t%2==0||l%2==1&&t%2==1||t<l)
            dfs(sx,sy,t);
        if(ans==1) printf("YES\n");
        else printf("NO\n");
        scanf("%d%d%d",&n,&m,&t);


    }
    return 0;
}
