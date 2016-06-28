#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int const num=100;
char a[num],b[num],str[num];
int c[num][num];
int main()
{
    int m,n,k;
    scanf("%s%s",a,b);
    m=strlen(a);
    n=strlen(b);
    for(int i=0;i<m;i++)
       c[i][0]=0;
    for(int j=0;j<n;j++)
        c[0][j]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
               c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    k=c[m][n];
    str[k]='\0';
    int i=m,j=n;
    while(k>0)
    {
        if(c[i][j]==c[i-1][j]) i--;
        else if(c[i][j]==c[i][j-1]) j--;
        else
        {
            k--;
            str[k]=a[i-1];
            i--;
            j--;
        }
    }
    printf("k=%d\n%s",k,str);
    return 0;
}
