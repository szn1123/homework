#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const int MAXN =10000;
char a[MAXN];
int c[MAXN];

int main()
{int max=0;
    memset(c,0,sizeof(c));
    scanf("%s",a);
    int l=strlen(a);
    for(int i=0;i<l;i++)
    {
        c[a[i]]++;
        if(max<a[i]) max=a[i];

    }
    for(int i=0;i<=max;i++)
    {

        if(c[i]==1)
        {
            printf("%c",i);
            break;
        }
    }
    return 0;
}
