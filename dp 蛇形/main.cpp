#include <iostream>
#include <cstdio>
using namespace std;
int a[1000][1000];
void snake(int num,int x,int y,int n)
{
    if(n==0) return;
    if(n==1)
    {
        a[x][y] = num;
        return;
    }
    for(int i=y;i<y+n;i++)
    {
        a[x][i] = num++;
    }
    for(int i=x+1;i<x+n;i++)
    {
        a[i][y+n-1] = num++;
    }
    for(int i=y+n-2;i>=y;i--)
    {
        a[x+n-1][i] = num++;
    }
    for(int i=x+n-2;i>x;i--)
    {
        a[i][y] = num++;
    }
    snake(num,x+1,y+1,n-2);

}
int main()
{
    int n;
    scanf("%d",&n);
    snake(1,0,0,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
      //  printf("\n");
    }

    return 0;
}
