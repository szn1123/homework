#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
    char s[5000];
    int a[1000];
    int dp[1000];
    int b[1000];
    int c[1000];
    int lis;
    int y;
    int LIS(int * arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if(dp[i] > lis)
                {
                    lis = dp[i];
                }
            }
        }
    }
    return lis;
}

void outputLIS(int * arr, int index)
{
    bool isLIS = 0;
    if(index < 0 || lis == 0)
    {
        return;
    }
    if(dp[index] == lis)
    {
        --lis;
        isLIS = 1;
    }

    outputLIS(arr,--index);

    if(isLIS)
    {
        b[y++]=arr[index+1];
    }
}
int main()
{
    int num,pow,x;
    freopen("in.txt","r",stdin);
    while(gets(s))
    {
        y=0;
        int len=strlen(s);
        num=0;pow=1;
        x=0;
        int ans=1;
        memset(dp,0,sizeof(dp));
        for(int i=len-1;i>=0;i--)
        {
            if(!(s[i]>='0'&&s[i]<='9'||s[i]==' '))
            {
                printf("error\n");
                ans=0;
                break;
            }
            if(s[i]!=' ')
            {
                num+=(s[i]-'0')*pow;
                pow=pow*10;
            }
            else
            {
                a[x++]=num;
                pow=1;
                num=0;
            }
        }
        if(ans==0) break;
        a[x++]=num;
        for(int i=0;i<x;i++)
            c[i] = a[x-i-1];
        //for(int i=0;i<x;i++)
           // printf("%d ",c[i])
        LIS(c,sizeof(c)/sizeof(int));
       outputLIS(c,sizeof(c)/sizeof(int) - 1);
       printf("%d",b[0]);
       for(int i=1;i<y;i++)
      printf(" %d",b[i]);
       printf("\n");
    }
    return 0;
}
