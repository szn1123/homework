#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr){//Ïàµ±ÓÚ char a[]
    char a[5],b[5];
    char c;
    memset(a,0,sizeof(a));
    const char *p = pInputStr;
    int x=0,y=0,ct=0;
    int flag = 0;
    while(*p!='\0')
    {
       // cout<<"*P="<<*p<<endl;
        if(flag==0)
        {
              if(*p<='9'&&*p>='0')
             {
                a[x++]=*p;
             }
             else if(*p==' ')
             {
                 flag=1;
             }
              else
              {
                  pOutputStr[ct++]='0';
                  break;
              }
        }
        else if(flag==1)
        {
            if(*p=='+'||*p=='-'||*p=='*'||*p=='/')
            {
                c=*p;
                flag=2;
            }
            else
            {
                pOutputStr[ct++]='0';
                  break;
            }

        }
        else if(flag==2)
        {
            if(*p!=' ')
            {
                 pOutputStr[ct++]='0';
                  break;
            }
            else
            {
                flag=3;
            }
        }
        else if(flag==3)
        {
              if(*p<='9'&&*p>='0')
             {
                b[y++]=*p;
             }
             else if(*p==' ')
             {
                 flag=1;
             }
              else
              {
                  pOutputStr[ct++]='0';
                  break;
              }
        }


       p++;
    }
     if(pOutputStr[0]=='0')
        {
            pOutputStr[1]='\0';
            return;
        }
        int aa=0,bb=0;
    int ten[3]={1,10,100};
     for(int i=x-1;i>=0;i--)
     {
         aa+=(a[i]-'0')*ten[x-i-1];
     }
     for(int i=y-1;i>=0;i--)
     {
         bb+=(b[i]-'0')*ten[y-i-1];
     }
     int ans;
     if(c=='+')
     {
         ans=aa+bb;
     }
     if(c=='-')
     {
         ans=aa-bb;
     }
     if(c=='*')
     {
         ans=aa*bb;
     }
     if(c=='/')
     {
         ans=aa/bb;
     }
     itoa(ans,pOutputStr,10);


}
int main()
{
    char a[1000];
    gets(a);
    char b[1000];
    char *p=a;
    char *q=b;
    //printf("%c %c %c",*p,*p+1,*(p+5));
    stringFilter(p,strlen(a),q);
    printf("%s",b);
    return 0;
}
