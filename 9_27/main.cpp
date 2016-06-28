#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define maxn 110000
#define mod 1000000007
#define LL long long
int q;
struct matrix
{
    LL mat[15][15];
    matrix()
    {
        memset(mat,0,sizeof(mat));
    }
};
int a[11];
int n;
int mulxx(matrix A,matrix B)
{
    LL ans=0;
    int i;
    for(i=1;i<=n+1;i++)
    {
        if(i==1)
        {
            ans+=A.mat[i][1]*B.mat[n+1][i]/q%mod;
        }
        else
        {
            ans+=A.mat[i][1]*B.mat[n+1][i]%mod;
        }
    }
    return ans;
}
matrix mul(matrix A,matrix B)
{
    matrix C;
    int i,j,k;
    for(i=1; i<=n+1; i++)
    {
        for(j=1; j<=n+1; j++)
        {
            for(k=1; k<=n+1; k++)
            {

                C.mat[i][j]=(C.mat[i][j]+A.mat[i][k]*B.mat[k][j])%mod;
            }
        }
    }
    return C;
}
matrix powmul(matrix A,int k)
{
    matrix B;
    for(int i=1;i<=n+1;i++)B.mat[i][i]=1;
    while(k>=1)
    {
        if(k&1)B=mul(B,A);
        A=mul(A,A);
        k=k/2;
    }
    return B;
}
void print(matrix A)
{
    cout<<"matrix A"<<endl;
    for(int i=1;i<=n+2;i++)
    {
        for(int j=1;j<=n+2;j++)
        {
            cout<<A.mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int m,d,a1,b1;
    int T;
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d%d%d%d%d",&b1,&q,&a1,&d,&n,&m);
        matrix A,B;
        A.mat[1][1]=b1;
        for(int i=1;i<=n;i++)
        {
            A.mat[i+1][1]=a1+(i-1)*d;
        }
      //  A.mat[n+2][1]=0;
        for(int i=1;i<=n+1;i++)B.mat[i][1]=q;
       // for(int i=1;i<=n+2;i++)B.mat[i][n+2]=1;
        for(int i=2;i<=n+1;i++)
        {
            for(int j=2;j<=i;j++)B.mat[i][j]=1;
        }
        //print(A);
        //print(B);
        B=powmul(B,m);
        //print(B);
        LL ans;
        ans=mulxx(A,B);
        //print(A);
        printf("Case #%d: %I64d\n",t,ans);
    }
    return 0;
}
