#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[2000010];
int main()
{
    int n;
    int m,x;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        int y=0;
        while(n--)
        {
            scanf("%d",&m);
            switch(m)
            {
                case 1:
                    scanf("%d",&x);
                    if(y==0) a[y++]=x;
                    else
                    {
                        for(int i=0;i<y;i++)
                        {
                            if(a[i]>x) continue;
                            else
                            {
                                for(int j=y-1;j>=i;j--)
                                {
                                    a[j+1]=a[j];
                                }
                                a[i]=x;
                                break;
                            }
                        }
                    }
                    break;
                case 2:
                   if(y!=0)
                   a[y-1]=0;y--;
                    break;
                case 3:
                   if(y!=0)
                   printf("%d\n",a[0]);
                   else printf("0\n");
                   break;


            }
        }
    }


    return 0;
}
