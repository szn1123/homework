#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dx[]={0,0,1,-1},
    dy[]={1,-1,0,0};
bool vis[20][20];
char map[20][20];
int dfs(int x,int y,int ans)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int newx=x+dx[i],
            newy=y+dy[i];
        if(vis[newx][newy]==0&&map[newx][newy]==map[x][y]
           &&newx>=1&&newx<=10&&newy>=1&&newy<=15)
        {
            //printf("(%d,%d,%c) ",newx,newy,map[newx][newy]);
            ans=dfs(newx,newy,ans)+1;
        }
    }
    return ans;
}
void print()
{
    for(int i=10;i>=1;i--)
    {
        for(int j=1;j<=15;j++)
        {
            cout<<map[i][j];
        }
        cout<<endl;
    }
}
void gxmap1(int x,int y)
{
    char s=map[x][y];
    map[x][y]=0;
    for(int i=0;i<4;i++)
    {
        int newx=x+dx[i],
            newy=y+dy[i];
        if(map[newx][newy]==s
           &&newx>=1&&newx<=10&&newy>=1&&newy<=15)
        {
            gxmap1(newx,newy);
        }
    }
}
void gxmap2()
{
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=15;j++)
        {
            if(map[i][j]==0)
            {
                int k=i+1;
                while(map[k][j]==0&&k<=10)
                {
                        k++;
                }
                if(map[k][j]!=0)
                {
                    map[i][j]=map[k][j];
                    map[k][j]=0;
                }

            }
        }
    }
}

void gxmap3()
{
    for(int j=1;j<=15;j++)
    {
        // printf("j=%d%c",j,map[1][j]);
       //  printf("lala");
        if(map[1][j]==0)
        {
          //  printf("haha");
           // printf("\nhhhj=%d",j);
            int k=j+1;

            while(map[1][k]==0&&k<=15)
            {
                k++;
            }
            if(map[1][k]!=0)
            {
                for(int i=1;i<=10;i++)
                {
                    map[i][j]=map[i][k];
                    map[i][k]=0;
                }
            }
        }
    }
}


int main()
{
    int T;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int area,m,px,py,point;
    for(int t=1;t<=T;t++)
    {
        memset(map,0,sizeof(map));
        m=0;
        int score=0;
        int ball=150;
        getchar();
        printf("Game %d:\n\n",t);
        for(int i=10;i>=1;i--)
        {
            getchar();
            for(int j=1;j<=15;j++)
            {
                 scanf("%c",&map[i][j]);
                // cout<<map[i][j];
            }
         // getchar();
            //cout<<endl;
        }
       // getchar();
        int op=0;
        int n=6;
        while(1)
        {
            m=0;
            memset(vis,0,sizeof(vis));
            for(int j=1;j<=15;j++)
            {
                for(int i=1;i<=10;i++)
                {
                    if(vis[i][j]==0&&map[i][j]!=0)
                    {
                        area=dfs(i,j,1);
                        if(m<area)
                        {
                            m=area;
                            px=i;
                            py=j;
                        }
                    }
                }
            }
            if(m<=1) break;
            point=(m-2)*(m-2);score+=point;ball-=m;
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",++op,px,py,m,map[px][py],point);
           // memset(vis,0,sizeof(vis));
           gxmap1(px,py);//print();cout<<endl;
           gxmap2();//print();cout<<endl;
           gxmap3();//print();cout<<endl;
          // DelMaxArea(px,py);
		//	RefreshMap();
        }
        if(ball==0) score+=1000;
        printf("Final score: %d, with %d balls remaining.\n\n",score,ball);

    }
   // cout<<endl;
    return 0;
}
