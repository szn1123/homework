#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100];
char pan[10][10];
int lala[2][10][10][2];
char qizi[2][6]={
    {'k','q','r','b','n','p'},
    {'K','Q','R','B','N','P'}};
int main()
{
    freopen("in.txt","r",stdin);
    gets(s);
    {
        int num[2][6];
        memset(num,0,sizeof(num));
        memset(lala,0,sizeof(lala));
        for(int i=8;i>=1;i--)
        {
           // getchar();
           // cout<<i<<" ";
            for(int j=0;j<8;j++)
            {
                getchar();getchar();
                scanf("%c",&pan[i][j]);
               // printf("%c",pan[i][j]);
              //  printf("i=%d j=%d ",i,j);
            getchar();
            }
            getchar();
            getchar();
            gets(s);
        }
      for(int i=1;i<=4;i++)
      {
            for(int j=0;j<8;j++)
            {
                for(int k=0;k<6;k++)
                {
                    for(int m=0;m<2;m++)
                    if(pan[i][j]==qizi[m][k])
                    {
                        lala[m][k][num[m][k]][0]=i;
                        lala[m][k][num[m][k]++][1]=j;
                       // printf("num[%d][%d]=%d\n ",m,k,num[m][k]);
                    }

                }
            }
        }
      for(int i=8;i>4;i--)
      {
            for(int j=0;j<8;j++)
            {
                for(int k=0;k<6;k++)
                {
                    for(int m=0;m<2;m++)
                    if(pan[i][j]==qizi[m][k])
                    {
                        lala[m][k][num[m][k]][0]=i;
                        lala[m][k][num[m][k]++][1]=j;
                       // printf("num[%d][%d]=%d\n ",m,k,num[m][k]);
                    }

                }
            }
        }

        printf("White: ");
        int flag=0;
        for(int i=0;i<6;i++)
        {


            for(int j=0;j<num[1][i];j++)
            {
                if(flag==0)
                {

                        if(i<5)
                     {
                         printf("%c",qizi[1][i]);
                         printf("%c",lala[1][i][j][1]+'a');
                     }
                     else
                     {
                         printf("%c",lala[1][i][j][1]+'a');
                     }
                     flag=1;
                }
                else
                {
                    printf(",");
                    if(i<5)
                     {
                         printf("%c",qizi[1][i]);
                         printf("%c",lala[1][i][j][1]+'a');
                     }
                     else
                     {
                         printf("%c",lala[1][i][j][1]+'a');
                     }
                    // flag=1;

                }



                printf("%d",lala[1][i][j][0]);
            }
        }
        flag=0;
        printf("\nBlack: ");
         for(int i=0;i<6;i++)
        {

            for(int j=0;j<num[0][i];j++)
            {
                 if(flag==0)
                {

                        if(i<5)
                     {
                         printf("%c",qizi[1][i]);
                         printf("%c",lala[0][i][j][1]+'a');
                     }
                     else
                     {
                         printf("%c",lala[0][i][j][1]+'a');
                     }
                     flag=1;
                }
                else
                {
                    printf(",");
                    if(i<5)
                     {
                         printf("%c",qizi[1][i]);
                         printf("%c",lala[0][i][j][1]+'a');
                     }
                     else
                     {
                         printf("%c",lala[0][i][j][1]+'a');
                     }
                    // flag=1;

                }   printf("%d",lala[0][i][j][0]);

            }
        }
        printf("\n");



    }
    return 0;
}
