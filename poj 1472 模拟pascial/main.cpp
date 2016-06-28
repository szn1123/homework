#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m;
int n[15];
/*
char s[20];
bool solve(int *n)
{
    scanf("%s",s);
    if(s[0]=='E') return 0;
    else if(s[0]=='B')
        while(solve(n));
    else if(s[0]=='O')
    {
        int a;
        scanf("%d",&a);
        n[0]+=a;
        return solve(n);
    }
    else
    {
        int lala[15];
        scanf("%s",s);
        while(solve(lala));
        if(s[0]=='n')
        {
            for(int i=10;i>0;i--)
                lala[i]=lala[i-1];
            lala[0]=0;
        }
        else
        {
            int x=s[0];printf("x=%c ",x);
            for(int i=0;i<11;i++)
                lala[i]*=x;
        }
        for(int i=0;i<11;i++)
        {
            n[i]+=lala[i];
        }
        return 1;
    }
}*/
int StrToNum(char* s)
{
    int digit=0;
    for(int i=0;s[i];i++)
        digit=digit*10+(s[i]-'0');

    return digit;
}
bool solve(int* exp)
{
    char s[30];
    cin>>s;

    if(s[0]=='E')    //END
        return false;
    else if(s[0]=='B')  //BEGIN
        while(solve(exp));   //若因为OP返回，则继续；若因为END返回，则结束
    else if(s[0]=='O')  //0P
    {
        cin>>s;
        exp[0]+=StrToNum(s);
        return solve(exp);
    }
    else     //LOOP
    {
        int TempExp[11]={0};  //临时exp[]
        cin>>s;
        while(solve(TempExp));

        if(s[0]=='n')   //LOOP n
        {
            for(int i=10;i>0;i--)
                TempExp[i]=TempExp[i-1];  //表达式乘以n，则所有项的次数+1
            TempExp[0]=0;
        }
        else  //LOOP Num
        {
            int x=StrToNum(s);
            for(int i=0;i<11;i++)
                TempExp[i]*=x; //表达式乘以const，则所有项的系数*const
        }
        for(int i=0;i<11;i++)
            exp[i]+=TempExp[i];
    }
    return true;
}
int main()
{
    int T;
    freopen("in.txt","r",stdin);
    scanf("%d",&T);

    for(int t=1;t<=T;t++)
    { memset(n,0,sizeof(n));
       solve(n);
       printf("Program #%d\n",t);
       printf("Runtime = ");
       bool flag=0;
       for(int i=10;i>=0;i--)
       {
           if(n[i]!=0&&n[i]!=1)
           {
               if(flag==0) flag=1;
               else printf("+");
               if(i>1)
                printf("%d*n^%d",n[i],i);
               else if(i==1)
                printf("%d*n",n[1]);
               else
               {
                   printf("%d",n[0]);
               }
           }
           else if(n[i]==1)
           {
               if(flag==0) flag=1;
               else printf("+");
               if(i>1)
                printf("n^%d",i);
               else if(i==1)
                printf("n");
               else
               {
                   printf("%d",n[0]);
               }
           }

       }
       printf("\n\n");
    }
    return 0;
}
