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
    freopen("in.txt","r",stdin);
    scanf("%s",s);
    while(s[0]!='.')
    {

        m=strlen(s);
                get_next();

      //  for(int i=1;i<=m;i++)
       //     printf("%d ",next[i]);
      //  printf("Test case #%d\n",test++);

        if(m%(m-next[m])==0&&next[m]!=0) printf("%d\n",m/(m-next[m]));
        else printf("1\n");
        //cout<<endl;
        memset(s,0,sizeof(s));
        scanf("%s",s);
    }
    return 0;
}
