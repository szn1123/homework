#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
using namespace std;
char s1[1000],s2[1000];
int len[1000][1000];
int main()
{

    s1={'a','b','c','d','c','d','k','a'};
    int n = strlen(s1);
    len[0][0]=0;
    for(int i=0;i<n;i++)
    {
        s2[i] = s1[n-i-1];
    }
    cout<<s2<<endl;
    for(int i=1;i<=n;i++)  //注意 从1-》n 因为i-1
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                len[i][j] = len[i-1][j-1] + 1;
            if(s1[i-1]!=s2[j-1])
                len[i][j] = max(len[i-1][j],len[i][j-1]);

        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<"len["<<i<<"]"<<"["<<j<<"]="<<len[i][j]<<endl;
        }
    }
    for(int i=n,j=n;i>0,j>0;)
    {

        if(s1[i-1]==s2[j-1])
        {
            printf("%c",s1[i-1]);
            i--;j--;
        }
        if(s1[i-1]!=s2[j-1])
        {
            if(len[i-1][j]>len[i][j-1]) i--;
            else j--;
        }
    }

    return 0;
}
