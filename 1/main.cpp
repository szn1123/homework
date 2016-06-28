#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,i,j,blood;
    int s,d,p,si,ar,c,;
    char gg[6][3],mm[4][3];
    cin>>n;
    while(n--)
    {
        blood=3;
        s=0;d=0;p=0;si=0;ar=0;c=0;
        for(i=0;i<6;i++)
        {
            scanf("%s",gg[i]);
            if(gg[i]=="ss") s++;
            else if(gg[i]=="si") si++;
            else if(gg[i]=="ar") ar++;

        }
        for(i=0;i<4;i++)
        {
            scanf("%s",mm[i]);
            if(mm[i]=="dd") d++;
            else if(mm[i]=="cc") c++;
            else if(mm[i]=="pp") p++;
            else if(mm[i]=="ss") si++;
        }
        if(ss>dd) {blood-=ss-dd;dd=0;}
        else if{dd=dd-ss};
        if(si>)

    }
    return 0;
}
