#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
int n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
ll m;
ll dp[510][2][2][2];
ll dfs(int num,int cr,int b,int c)
{

	if(num>n)
		return 0;
	if(num+a[1]==n&&cr==1&&b==1&&c==1)
		return 1;
	if(num==n)
	{
		if(cr==0&&b==1&&c==1)
			return 1;
		return 0;
	}
	if(dp[num][cr][b][c]!=-1)
		return dp[num][cr][b][c];
	dp[num][cr][b][c]=0;
	if(b==0)
	{
		if(c==0)
		{
			for(int i=0;i<10;i++)
				for(int j=0;j<10;j++)
				{
					int t=a[i]+a[j]+a[(i+j+cr)%10];
					dp[num][cr][b][c]+=dfs(num+t,(i+j+cr)/10,0,0);
					if(i!=0)
						dp[num][cr][b][c]+=dfs(num+t,(i+j+cr)/10,1,0);
					if(j!=0)
						dp[num][cr][b][c]+=dfs(num+t,(i+j+cr)/10,0,1);
					if(i!=0&&j!=0)
						dp[num][cr][b][c]+=dfs(num+t,(i+j+cr)/10,1,1);
					dp[num][cr][b][c]%=m;
				}
		}
		else
		{
			for(int i=0;i<10;i++)
			{
				int t=a[i]+a[(i+cr)%10];
				dp[num][cr][b][c]+=dfs(num+t,(i+cr)/10,0,1);
				if(i!=0)
					dp[num][cr][b][c]+=dfs(num+t,(i+cr)/10,1,1);
			}
		}
	}
	else
	{
		if(c==0)
		{
			for(int i=0;i<10;i++)
			{
				int t=a[i]+a[(i+cr)%10];
				dp[num][cr][b][c]+=dfs(num+t,(i+cr)/10,1,0);
				if(i!=0)
					dp[num][cr][b][c]+=dfs(num+t,(i+cr)/10,1,1);
			}
		}
	}
	return dp[num][cr][b][c]%=m;
}
int main()
{
	int T;
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		cin>>n>>m;
		n-=3;
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %d\n",cs,int(dfs(0,0,0,0)));
	}
}
