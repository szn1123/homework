#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char map[110][110];
bool vis[110][110];
char per[4][4];
int h,w;
int ans;

bool check(int x,int y)
{
    if(x>=0&&x<h&&y>=0&&y<w&&
       (map[x][y]=='0'||map[x][y]=='/'||
        map[x][y]=='|'||map[x][y]=='\\'||
        map[x][y]==')'||map[x][y]=='(')) return 1;
    else return 0;
}
voi pos(int x,int y)
{

}
void dfs(int x,int y)
{
    if(!vis[x][y]&&check(x,y))
    {
        ans++;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(map[x+i][y+j]==per[i][j])
                {
                    vis[x+i][y+j]=1;
                }
            }
        }
    }

}
int main()
{
    per[0][0]='.';
    per[0][1]='0';
    per[0][2]='.';
    per[1][0]='/';
    per[1][1]='|';
    per[1][2]='\\';
    per[2][0]='(';
    per[2][1]='.';
    per[2][2]=')';
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        memset(vis,0,sizeof(vis));

        scanf("%d%d",&h,&w);
        for(int i=0;i<h;i++)
        {
            scanf("%s",map[i]);
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                dfs(i,j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
