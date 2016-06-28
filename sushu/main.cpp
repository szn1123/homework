#include <iostream>
#include <cstdio>
using namespace std;
bool prime[1000005];
int primelist[1000005];
int prim(int n){
    int ct=0;
    for(int i=2;i<=n;i++) prime[i]=1;
   // prime[1]=0;
    for(int i=2;i<=n;i++)
    {

        if(prime[i])
        {
            ct++;
            primelist[ct]=i;

        }

            for(int j=1;j<=ct;j++)
            {

                if(i*primelist[j]>n)
                    break;
                prime[i*primelist[j]]=0;

                if(i%primelist[j]==0)
                    break;

            }

    }
    return ct;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
    int ans=prim(n);
    printf("%d\n",ans);
    }
    return 0;
}
