#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
const int MAXN=100;
int a[MAXN];
int LSS_Recursion(int a[], int l, int r)           //最大子段和，分治算法，O(nlgn)
{
int m = (l + r) / 2, t = 0, L = 0, R = 0;          //L为左区间能取到的最大，R为右区间能取到的最大

if (l == r)                  //边际条件：当区间元素只有一个的时候返回自身
   return a[m];

if (r - l == 1)                 //边际条件：当区间元素只有两个的时候返回左、右、左右相加三者中的最大值
   return max(max(a[l], a[r]), a[l] + a[r]);

int LMax = LSS_Recursion(a, l, m);            //递归左区间
int RMax = LSS_Recursion(a, m + 1, r);           //递归右区间

for (int i = m; i >= 1; i--)             //左边找一个最大的和
{
   t += a[i];
   if (t > L)
    L = t;
}

t = 0;

for (int i = m + 1; i <= r; i++)            //右边找一个最大的和
{
   t += a[i];
   if (t > R)
    R = t;
}

return max(max(LMax, RMax), L + R);            //返回左区间的和、右区间的和、两者连起来的和中最大的
}
int main()
{
    int n,i,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    ans=LSS_Recursion(a,0,n-1);
    printf("%d\n",ans);
    return 0;
}
