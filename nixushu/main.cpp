#include <iostream>
#include <cstdio>
#define max 10010
using namespace std;

long long a[max],b[max];
int count;
void Merge(long long a[], int start, int mid , int end)  //�鲢����ĺϲ�����
{
    int i = start,j = mid + 1,k = start;
    while(i <= mid&&j <= end)
    {
        if(a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            count += j - k;
            b[k++] = a[j++];
        }
    }
    while(i <= mid)
    {
        b[k++] = a[i++];
    }
    while(j <= end)
    {
        b[k++] = a[j++];
    }
    for(int i = start; i <= end; i++)
    {
        a[i] = b[i];
    }
}

void MergeSort(long long a[], int start, int end)  //�鲢����
{
    if(start < end)
    {
        int mid = (start + end)/2;
        MergeSort(a,start,mid);     // ��ǰ�벿������
        MergeSort(a,mid+1,end);     // ����벿������
        Merge(a,start,mid,end);     // �ϲ�ǰ����������
    }
}  int main()
{
   int T;
   scanf("%d",&T);
   while(T--){
       int n;
       scanf("%d",&n);
       for(int i=0;i<n;i++)
       {
           scanf("%d",&a[i]);
       }
       MergeSort(a,0,n-1);
       printf("%d\n",count);
   }
    return 0;
}
