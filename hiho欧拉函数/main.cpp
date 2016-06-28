#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool isPrime[5000010];
int primeList[5000010];
int phi[5000010];
void pre()
{
    int primeCount = 0;
    memset(isPrime,1,sizeof(isPrime));
    for(int i=2;i<=5000000;i++)
    {
        if(isPrime[i])
        {
            primeCount++;
            primeList[primeCount] = i;
            phi[i] = i - 1;
        }
        for(int j=1;j<=primeCount;j++)
        {
            if(i*primeList[j]>5000000) break;
            isPrime[i*primeList[j]] = 0;
            if(i%primeList[j]==0)
            {
                phi[i*primeList[j]] = phi[i]*primeList[j];
                break;
                //因为24这种数有2*12 4*6 3*8等多种表示方法 这里只需要用2*12(最小的质数和i的乘积求得)
            }
            else
            {
                phi[i*primeList[j]] = phi[i]*(primeList[j]-1);
            }
        }
    }
}
int main()
{
    int l,r;

    pre();
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&l,&r)!=EOF)
    {
        int min=5000010,ans;
        for(int i=l;i<=r;i++)
        {
            if(phi[i]<min)
            {
                min=phi[i];
                ans=i;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
