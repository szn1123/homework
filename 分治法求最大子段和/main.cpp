#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
const int MAXN=100;
int a[MAXN];
int LSS_Recursion(int a[], int l, int r)           //����Ӷκͣ������㷨��O(nlgn)
{
int m = (l + r) / 2, t = 0, L = 0, R = 0;          //LΪ��������ȡ�������RΪ��������ȡ�������

if (l == r)                  //�߼�������������Ԫ��ֻ��һ����ʱ�򷵻�����
   return a[m];

if (r - l == 1)                 //�߼�������������Ԫ��ֻ��������ʱ�򷵻����ҡ�������������е����ֵ
   return max(max(a[l], a[r]), a[l] + a[r]);

int LMax = LSS_Recursion(a, l, m);            //�ݹ�������
int RMax = LSS_Recursion(a, m + 1, r);           //�ݹ�������

for (int i = m; i >= 1; i--)             //�����һ�����ĺ�
{
   t += a[i];
   if (t > L)
    L = t;
}

t = 0;

for (int i = m + 1; i <= r; i++)            //�ұ���һ�����ĺ�
{
   t += a[i];
   if (t > R)
    R = t;
}

return max(max(LMax, RMax), L + R);            //����������ĺ͡�������ĺ͡������������ĺ�������
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
