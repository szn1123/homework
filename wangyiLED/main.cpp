#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int number[10][10]={{4},{1,2,4,5,7},{2,6},{2,5},{1,5,7},{3,5},{3},{2,4,5,7},{},{5}};
int nct[10]={1,5,2,2,3,2,1,4,0,1};
int main()
{
    int s;
    freopen("in.txt","r",stdin);
    scanf("%d",&s);
    while(s--)
    {
        int k,n;
        scanf("%d%d",&k,&n);
        char num[100];
        int kable[5][10];
        int kablect[10];
        memset(kable,0,sizeof(0));
        getchar();
        for(int i=0;i<k;i++)
        {
            gets(num);
            int led[10],x=0;
            int l=strlen(num);
            for(int j=0;j<l;j++)
            {
                if(num[j]==' ') continue;
                led[x++]=num[j]-'0';
            }
           // printf("i=%d x=%d %s\n",i,x,num);
            if(x==0)
            {
                for(int ii=0;ii<10;ii++)
                {
                    kable[i][ii]=i;
                }
            }
            else
            {
                int m=0;
                for(int j=0;j<10;j++)
                {
                    bool flag1=1;
                    for(int ledx=0;ledx<x;ledx++)
                    {
                        bool flag2 = 1;
                        for(int nn=0;nn<nct[j];nn++)
                        {
                            if(led[ledx]==number[j][nn])
                            {
                                 flag2 = 0;
                                 break;
                            }

                        }
                        if(flag2==0)
                        {
                            flag1 = 0;
                            break;
                        }
                    }
                    if(flag1==1)
                    {
                        kable[i][m++]=j;

                 //   printf("kable[%d][%d]=%d\n",i,m-1,j);
                    }
                }
                 kablect[i]=m;
               //  printf("kablect[%d]=%d\n",i,kablect[i]);
            }

        }
        int nmax[5];
        for(int i=k-1;i>=0;i--)
        {
            nmax[i] = n % 10;
            n = n / 10;
          //  printf("nmax[%d]=%d\n",i,nmax[i]);
        }
        int ans=0;
        bool isok=0;
        for(int i=0;i<k;i++)
        {

            int ct=kablect[i];
            for(int j=kablect[i]-1;j>=0;j--)
            {
                if(kable[i][j]>nmax[i]) ct--;
               // printf("kable[i][j]=%d\n nmax[i]=%d\n",kable[i][j],nmax[i]);
            }
          //  printf("ct=%d\n",ct);
            if(ct==0&&isok==0)
            {
                ans = 0;
                break;
            }
            else
            {
                int mul = 1;
                for(int j=i+1;j<k;j++)
                {
                    mul*=kablect[j];
                }
               // printf("mul=%d\n",mul);
              //  printf("equal??nmax[%d]=%d kable[%d][%d]=%d\n",i,nmax[i],i,ct,kable[i][ct]);
                if(nmax[i]==kable[i][ct-1])
                {
                    ans += (ct-1) * mul;

                }
                else
                {
                    ans += ct * mul;
                }
       //          printf("ans=%d\n",ans);
                isok = 1;

            }


        }
        printf("%d\n",ans);


    }
    return 0;
}
