#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[100];
char s[100];
int main()
{
    printf("请输入要查找的参数名称：");
    gets(a);
    int la=strlen(a);
    freopen("in.txt","r",stdin);
    while(gets(s))
    {
        bool flag=1;
        if(s[1]=='*') continue;
        for(int i=0;i<la;i++)
        {
            if(s[i+1]!=a[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            int ls=strlen(s);
            for(int i=1+la+2;i<ls;i++)
            {
                printf("%c",s[i]);
            }
        }
        memset(s,0,sizeof(s));
    }

    return 0;
}
