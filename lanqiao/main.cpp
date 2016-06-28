#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
   long long x;
   char a[20];
   int i,l;
   long long b[20];
   b[0]=1;
   for(i=0;i<15;i++)
      {
          b[i+1]=b[i]*16;
          printf("b[%d]=%lld\n",i,b[i]);
      }
   while(scanf("%s",a)!=EOF)
   {

       x=0;
       l=strlen(a);
       for(i=0;i<l;i++)
       {
           if(a[i]>='0'&&a[i]<='9')
                x=x*16+a[i]-'0';
           else
                x=x*16+a[i]-'A'+10;
       }
       printf("%lld\n",x);
   }






    return 0;
}
