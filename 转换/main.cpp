#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100];
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdin);
    while(~scanf("%s",s))
    {
        int l=strlen(s);
        for(int i=0;i<l;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                s[i]=s[i]-'a'+'A';
        }
        puts(s);
    }
    return 0;
}
