#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[1000010];
int main()
{
    int T;
    freopen("in.txt","r",stdin);
    scanf("%d",&T);getchar();
    for(int t=1;t<=T;t++)
    {
        int i,j,k;
        bool both,flag;
        printf("Case #%d: ",t);
        scanf("%s",s);
        int ans=0;
        int l=strlen(s);
        both=1;flag=1;
        for(i=0;i<l;i++)
        {
            if(s[i]=='c')
            {
                both=0;
                if(s[(i+1)%l]=='f'&&s[(i+2)%l]=='f')
                {
                    ans++;
                }
                else flag=0;
            }
            else if(s[i]!='f') flag=0;
        }
        if(flag==0) printf("-1\n");
        else
        {
            if(both==1) printf("%d\n",l/2+l%2);
            else printf("%d\n",ans);
        }
    }
    return 0;
}
