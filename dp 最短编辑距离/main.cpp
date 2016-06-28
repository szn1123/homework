#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char a[1000],b[1000];
int dis[1000][1000];
int main()
{
    scanf("%s%s",a,b);
    int la = strlen(a);
    int lb = strlen(b);
    dis[0][0]=0;
    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dis[i][j] = dis[i-1][j-1];
            }
            else
            {
                dis[i][j] = min(dis[i-1][j],dis[i][j-1])+1;
            }
        }
    }
    printf("%d",dis[la][lb]);
    return 0;
}
