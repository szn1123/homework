#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void coverdata(char data[],int len){
    for(int i=0;i<len/2;i++){
        data[i] += data[len-i-1];
        data[len-i-1] = data[i] - data[len-i-1];
        data[i] -= data[len-i-1];
    }
}

void mutiply(char a[],int la,char b[],int lb)
{
    int c[100];
    memset(c,0,sizeof(c));
    for(int i = 0;i<la;i++)
    {
        for(int j = 0; j<lb;j++)
        {
            c[i+j]+=(a[i]-'0')*(b[j]-'0');
        }
    }
    for(int i=0;i<la+lb+1;i++){
        int d = c[i]/10;
        c[i]%=10;
        c[i+1] += d;
    }
    bool flag = 0;
    for(int i=la+lb;i>=0;i--)
    {
        if(c[i]<=0&&flag==0)
            continue;
        else{
            flag = 1;
            printf("%d",c[i]);
        }

    }
    printf("\n");
}
int main()
{
    char a[50],b[50];
    while(scanf("%s%s",a,b)!=EOF){
        int la = strlen(a);
        int lb = strlen(b);
        coverdata(a,la);
        coverdata(b,lb);
       // printf("%s %s",a,b);
        mutiply(a,la,b,lb);
    }
    return 0;
}
