#include <iostream>
#include <cstdio>
using namespace std;
int a[20],b[20],c[40],d[40],n,t,i,j,k;//t��¼��ĸ���

void output()
{
    t++;
    printf("%d ",t);
    for(k=1;k<=n;k++)
    {
        printf("%d ",a[k]);
    }
    printf("\n");
}
void try0(int i)
{
    int j;
    for(j=1;j<=n;j++)                       //��i���ʺ���n�ֿ���λ��
    {
        if(b[j]==0&&c[i+j]==0&&d[i-j+n]==0) //�ж�λ���Ƿ��ͻ
        {
            a[i]=j;                         //�ڷŻʺ�
            b[j]=1;                         //ռ���j��
            c[i+j]=1;                       //ռ�������Խ���
            d[i-j+n]=1;
            if(i<n)
                try0(i+1);                  //�ݹ�ڷ���һ���ʺ�
            else
                output();                   //������񣬴�ӡ���
            b[j]=0;                         //����
            c[i+j]=0;
            d[i-j+n]=0;

        }
    }
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        b[i]=0;
        c[i]=0;
        c[n+1]=0;
        d[i]=0;
        d[n+1]=0;
    }
    try0(1);
    return 0;
}
