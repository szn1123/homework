#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int next[1000010],m;
char s[1000010];

void get_next()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<=m)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int main()
{
    int test=1;
   // freopen("in.txt","r",stdin);
    scanf("%d",&m);
    while(m!=0)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        get_next();
      //  for(int i=1;i<=m;i++)
       //     printf("%d ",next[i]);
        printf("Test case #%d\n",test++);
        for(int i=2;i<=m;i++)
        {
            if(next[i]!=0&&i%(i-next[i])==0)
            {
                printf("%d %d\n",i,i/(i-next[i]));
            }
        }
        cout<<endl;
        scanf("%d",&m);
    }
    return 0;
}
