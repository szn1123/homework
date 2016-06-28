#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


int main()
{
   int m,s,n,i,j,k;
   int a[210][210],b[210][210],c[210][210];
   cin>>m>>s>>n;
   for(i=0;i<m;i++)
   for(j=0;j<s;j++)
    cin>>a[i][j];
   for(i=0;i<s;i++)
   for(j=0;j<n;j++)
    cin>>b[i][j];
   for(i=0;i<m;i++)
   for(j=0;j<n;j++)
   for(k=0;k<s;k++)
   {
       c[i][j]+=a[i][k]*b[k][j];
   }
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
        cout<<c[i][j]<<" ";
        cout<<endl;
   }










    return 0;
}
