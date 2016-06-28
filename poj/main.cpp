#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int t1,t2,blank1,blank2,i;
    char tmp1[20],tmp2[20],s;
    scanf("%s",tmp1);
    printf("%s\n",tmp1);
    s=tmp1[0];
    t1=strlen(tmp1);
    blank1=0;
    while(~scanf("%s",tmp2))
    {

        blank2=0;
        if(tmp2[0]!=s)
        {
            s=tmp2[0];
            printf("%s\n",tmp2);
            blank2=0;
        }
        else
        {
            t2=strlen(tmp2);
            for(i=0;i<t2&&i<t1&&i<blank1+1;i++)
            {
                if(tmp1[i]==tmp2[i]) {printf(" ");blank2++;}
                else break;
            }
            printf("%s\n",tmp2);

        }
          memcpy(tmp1,tmp2,sizeof(tmp2));
            t1=strlen(tmp1);
            blank1=blank2;

    }
    return 0;
}
