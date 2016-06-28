#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int a1,a2,h1,h2;
   // freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&a1,&h1,&a2,&h2);
            if(a1==0) {printf("Invalid\n");continue;}
            else if(h1-a2>0) printf("%d %d ",a1,h1-a2);
            else printf("Discard ");
            if(h2-a1>0) printf("%d %d\n",a2,h2-a1);
            else printf("Discard\n");
        }


    }
    return 0;
}
