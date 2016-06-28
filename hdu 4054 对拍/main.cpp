#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//const double eps=1e-7;
//const double INF=1e50;
//const double pi=acos(-1);

#define N 5000
#define M 10000

char s[N];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while (gets(s))
    {
        int l=strlen(s);
        int i,j,n=0;
        for (i=0;i<l;i+=16)
        {
            if (n<16) printf("00");
            else if (n<256) printf("0");
            printf("%x0:",n);

            for (j=i;j<=(i+15);j++)
            {
                if (j%2==0) printf(" ");

                if (j<l) printf("%x",s[j]);
                else printf("  ");
            }

            printf(" ");
            for (j=i;j<=(i+15) && j<l;j++)
            if (s[j]>='a' && s[j]<='z') printf("%c",s[j]-'a'+'A');
            else if (s[j]>='A' && s[j]<='Z') printf("%c",s[j]-'A'+'a');
            else printf("%c",s[j]);

            printf("\n");

            n+=1;
        }
    }

    return 0;
}
