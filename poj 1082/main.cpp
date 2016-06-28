#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    int y,m,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&y,&m,&d);
        if(m==9&&d==30||m==11&&d==30)
        {
            printf("YES\n");
        }
        else if((m+d)%2==0)
        {
            printf("YES\n");
        }
        else printf("NO\n");

    }
    return 0;
}
