#include <iostream>
#include <cstring>
#include <cstdio >
using namespace std;
void getnext()
{
    int i,j;
    next[1]=0;
    next[0]=1;
    i=1;j=0;
    int l=strlen(S);
    while(i<l)
    {
        if(j==0||s[i]==s[j])
        {
            i++;j++;
            next[i]=j;
        }
        else j=next[j];
    }
}
int main()
{

    return 0;
}
