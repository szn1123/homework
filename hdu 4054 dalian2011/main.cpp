#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[5000];
char a[20];
int main()
{
    int len;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
   // gets(s);

    while(gets(s))
    {
        memset(a,0,sizeof(a));
       // memset(s,0,sizeof(s));
        printf("0000: ");
        int row=0;
        len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]>=16) printf("%x%x",s[i]/16,s[i]%16);
            else printf("0%x",s[i]);

            if(s[i]>='a'&&s[i]<='z')
            {
                 a[i%16]=s[i]-'a'+'A';
            }
            else if(s[i]>='A'&&s[i]<='Z')
            {
                a[i%16]=s[i]-'A'+'a';
            }
            else
            {
                a[i%16]=s[i];
            }// if(s[i]=='\\')
            {
              //  printf("\\\\\\\\");
             //   a[i%16]=s[i];
              //  printf("s[i]=%c a[i]=%c\n",s[i],a[i%16]);
            }
            a[16]='\0';
            if(i%2==1) printf(" ");
            if(i%16==15&&i!=len-1)
            {
                puts(a);
                memset(a,0,sizeof(a));
                row+=16;
              //  printf("\n");
               printf("%04x: ",row);
            }
        }
          // printf("len=%d",len);
            for(int i=0;i<16-len%16;i++)
            {
               // putchar(' ');
                //putchar(' ');
                printf("  ");
                if(i%2==0) printf(" ");
            }
           // printf(" ");
            puts(a);
          //  printf("\n");
          //  gets(s);

    }
    return 0;
}
