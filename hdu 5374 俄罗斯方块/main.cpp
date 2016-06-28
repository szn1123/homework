#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool map[15][20];
char op[1200];
int token[1010];
int score;
int t[3][4][4][2]={
   {{0,0,0,1,1,0,1,1},{0,0,0,1,1,0,1,1},{0,0,0,1,1,0,1,1},{0,0,0,1,1,0,1,1}},//0
   {{0,0,0,1,0,2,0,3},{0,0,1,0,2,0,3,0},{0,0,0,1,0,2,0,3},{0,0,1,0,2,0,3,0}},
   {{0,0,0,1,1,0,2,0},{0,0,0,1,0,2,1,2},{0,1,1,1,2,1,2,0},{0,0,1,0,1,1,1,2}}
   };//type s 4 xy
bool check(int type,int s,int x,int y)
{
    int newx,newy;
    for(int i=0;i<4;i++)
    {
        newx=x+t[type][s][i][0];
        newy=y+t[type][s][i][1];
        if(newx<1||newx>9||newy<1||newy>12||map[newx][newy]==1)
            return 0;
    }
    return 1;

}
void print()
{
    for(int i=12;i>=1;i--)
    {
        for(int j=1;j<=9;j++)
        {
            if(map[j][i]==1)
            printf("@");
            else printf(" ");
        }
        printf("\n");
    }

}
void change(int type,int s,int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int newx=x+t[type][s][i][0],
            newy=y+t[type][s][i][1];
        map[newx][newy]=1;
    }
    for(int i=1;i<=12;)
    {
        int c=0;
        for(int j=1;j<=9;j++)
        {
            if(map[j][i]==1)  c++;
        }
        if(c==9)
        {
            score++;
            for(int yy=i;yy<=11;yy++)
            {
                for(int xx=1;xx<=9;xx++)
                {
                    map[xx][yy]=map[xx][yy+1];
                }
            }

        }
        else i++;
    }
}
int main()
{
    int t,n,x,y,state,pos;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int T=1;T<=t;T++)
    {
        memset(map,0,sizeof(map));
        memset(op,0,sizeof(op));
        score=0;
        scanf("%d",&n);
        scanf("%s",op);
        x=4;y=9;state=0;pos=0;
        for(int i=0;i<n;i++)
        {
           scanf("%d",&token[i]);
        }
        int len=strlen(op);
        for(int i=0;i<len;i++)
        {
            if(op[i]=='w'&&check(token[pos],(state+1)%4,x,y))
            {
                state=(state+1)%4;
            }
            else if(op[i]=='s'&&check(token[pos],state,x,y-1))
            {
                y--;
            }
            else if(op[i]=='a'&&check(token[pos],state,x-1,y))
                x--;
            else if(op[i]=='d'&&check(token[pos],state,x+1,y))
                x++;
            if(check(token[pos],state,x,y-1))
               y--;
            else
            {
              //  printf("x=%d y=%d\n",x,y);
                change(token[pos],state,x,y);
               print();
                x=4;y=9;state=0;pos++;
                if(pos>n) break;
            }

        }
        printf("Case %d: %d\n",T,score);

    }
    return 0;
}
