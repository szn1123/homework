#include <iostream>
#include <cstdio>
using namespace std;
int a[20],b[20],c[40],d[40],n,t,i,j,k;//t记录解的个数

void output()
{
    t++;
    printf("%d ",t);
    for(k=1;k<=n;k++)
    {
        printf("%d ",a[k]);
    }
    printf("\n");
}
void try0(int i)
{
    int j;
    for(j=1;j<=n;j++)                       //第i个皇后有n种可能位置
    {
        if(b[j]==0&&c[i+j]==0&&d[i-j+n]==0) //判断位置是否冲突
        {
            a[i]=j;                         //摆放皇后
            b[j]=1;                         //占领第j列
            c[i+j]=1;                       //占领两个对角线
            d[i-j+n]=1;
            if(i<n)
                try0(i+1);                  //递归摆放下一个皇后
            else
                output();                   //完成任务，打印结果
            b[j]=0;                         //回溯
            c[i+j]=0;
            d[i-j+n]=0;

        }
    }
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        b[i]=0;
        c[i]=0;
        c[n+1]=0;
        d[i]=0;
        d[n+1]=0;
    }
    try0(1);
    return 0;
}
