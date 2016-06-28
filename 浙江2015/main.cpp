#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct dish{
    char name[55];
    int price;
}d[3][105];
char ans[3][55];
int cmp(dish a,dish b){
    return a.price<b.price;
}
int main()
{
  //  freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        int s[3];
           scanf("%d%d%d",&s[0],&s[1],&s[2]);
       for(int i=0;i<3;i++)
       {
           int n=s[i];
           for(int j=0;j<n;j++)
           {
               scanf("%s%d",d[i][j].name,&d[i][j].price);
           }
           sort(d[i],d[i]+n,cmp);
           //if(n%2==0)
           {
               strcpy(ans[i],d[i][n/2].name);
               sum+=d[i][n/2].price;
           }

       }
       printf("%d %s %s %s\n",sum,ans[0],ans[1],ans[2]);
    }
    return 0;
}
