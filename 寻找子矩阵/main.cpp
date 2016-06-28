#include <iostream>
#include <cstdio>
using namespace std;
int a[100][100],b[100][100];
int ma,na,mb,nb;
bool check(int x,int y)
{
    bool ans=1;
    for(int i=0;i<nb;i++)
    {
        for(int j=0;j<mb;j++)
        {
            if(a[x+i][y+j]!=b[i][j])
            {
                ans=0;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d%d%d",&na,&ma,&nb,&mb);
    for(int i=0;i<na;i++)
    {
        for(int j=0;j<ma;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
     for(int i=0;i<nb;i++)
    {
        for(int j=0;j<mb;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<na;i++)
    {
        for(int j=0;j<ma;j++)
        {
            if(check(i,j)==1)
            {
                ans=1;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
