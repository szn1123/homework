#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[5][5];
int main()
{
    while(scanf("%s%s%s",a[0],a[1],a[2])!=EOF){
        int x=0,o=0;
        if(strlen(a[0])!=3||strlen(a[1])!=3||strlen(a[2])!=3)
        {
            printf("x\n");
            continue;
        }
        bool xwin=0,owin=0;
        bool flag=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(a[i][j]=='X') x++;
                else if(a[i][j]=='0') o++;
                else if(a[i][j]=='.') ;
                else{
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0) {printf("x\n");continue;}
            for(int i=0;i<3;i++)
            {
                if(a[i][0]=='X'&&a[i][1]=='X'&&a[i][2]=='X'||a[0][i]=='X'&&a[1][i]=='X'&&a[2][i]=='X')
                    xwin=1;
                if(a[i][0]=='0'&&a[i][1]=='0'&&a[i][2]=='0'||a[0][i]=='0'&&a[1][i]=='0'&&a[2][i]=='0')
                    owin=1;
            }
            if(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X'||a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X')
                xwin=1;
            if(a[0][0]=='0'&&a[1][1]=='0'&&a[2][2]=='0'||a[0][2]=='0'&&a[1][1]=='0'&&a[2][0]=='0')
                owin=1;
            if(x==o+1||x==o)
            {
                if(xwin==1&&owin==0)
                {
                    printf("1 won\n");
                }
                else if(xwin==0&&owin==1)
                {
                    printf("2 won\n");

                }
                else if(xwin==0&&owin==0)
                {
                    if(x+o==9)
                        printf("Draw\n");
                    else
                    {
                        if(x==o) printf("1\n");
                        else if(x==o+1) printf("2\n");
                        else printf("x\n");
                    }

                }

                else printf("x\n");

            }
            else printf("x\n");


    }
    return 0;
}
