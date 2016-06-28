#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 220;
const int INF = 0x3fffffff;
int  n;
int  t[N], d[N];
int  dp[N][N][2], next[N][N][2];

int main()
{
    freopen("in.txt","r",stdin);
    while ( scanf("%d", &n) != EOF )
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &t[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &d[i]);

        memset(dp, 0, sizeof(dp));
        for (int l = 2; l <= n; l++)
        {
            for (int i = 1; i+l-1 <= n; i++)
            {
                int j = i + l - 1;
                // º∆À„dp[i][j][0]
                 //printf("dp[%d+1][%d][0]=%d\n",i,j,dp[i+1][j][0]);
                //printf("dp[%d+1][%d][1]=%d\n",i,j,dp[i+1][j][1]);
                if ( dp[i+1][j][0] + d[i+1] - d[i] < dp[i+1][j][1] + d[j] - d[i] )
                {
                    dp[i][j][0] = dp[i+1][j][0] + d[i+1] - d[i];
                    next[i][j][0] = 0;
                }
                else
                {
                    dp[i][j][0] = dp[i+1][j][1] + d[j] - d[i];
                    next[i][j][0] = 1;
                }
                if ( dp[i][j][0] >= t[i] || dp[i][j][0] > INF )
                {
                    dp[i][j][0] = INF;
                }
                // º∆À„dp[i][j][1]
                if ( dp[i][j-1][0] + d[j] - d[i] < dp[i][j-1][1] + d[j] - d[j-1] )
                {
                    dp[i][j][1] = dp[i][j-1][0] + d[j] - d[i];
                    next[i][j][1] = 0;
                }
                else
                {
                    dp[i][j][1] = dp[i][j-1][1] + d[j] - d[j-1];
                    next[i][j][1] = 1;
                }
                if ( dp[i][j][1] >= t[j] || dp[i][j][1] > INF )
                {
                    dp[i][j][1] = INF;
                }
            }
        }
        int l, r, m;
        if ( dp[1][n][0] < INF )
        {
            l = 2;
            r = n;
            m = next[1][n][0];
            printf("1");
        }
        else if ( dp[1][n][1] < INF )
        {
            l = 1;
            r = n - 1;
            m = next[1][n][1];
            printf("%d", n);
        }
        else
        {
            printf("Mission Impossible\n");
            continue;
        }
        while ( l <= r )
        {
            if ( m == 0 )
            {
                printf(" %d", l);
                m = next[l][r][m];
                l++;
            }
            else if ( m == 1 )
            {
                printf(" %d", r);
                m = next[l][r][m];
                r--;
            }
        }
        printf("\n");
    }
    return 0;
}

