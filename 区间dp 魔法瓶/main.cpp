#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define inf 200000001
using namespace std;
const int MAXN = 200+10;
int smoke[MAXN][MAXN];
int sum[MAXN];
int color[MAXN][MAXN];
int main()
{
    int n;
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        int a;
        memset(smoke,0,sizeof(smoke));
        memset(color,0,sizeof(color));
        for(int i=1;i<=n;i++)
        scanf("%d",&color[i][i]);

        for(int l=2;l<=n;l++)
        {
            for(int i=1;i<=n;i++)
            {
                int j=i+l-1;
                smoke[i][j]=inf;
                for(int k=i;k<j;k++)
                if(smoke[i][j]>smoke[i][k]+smoke[k+1][j]+color[i][k]*color[k+1][j])
                {
                    smoke[i][j]=smoke[i][k]+smoke[k+1][j]+color[i][k]*color[k+1][j];
                    color[i][j]=(color[i][k]+color[k+1][j])%100;
                }

            }
        }
        printf("%d\n",smoke[1][n]);
    }
    return 0;
}
