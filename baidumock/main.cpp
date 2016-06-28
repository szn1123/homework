#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int hohoho(int num,char arr[][300])
{
    printf("num=%d",num);
    for(int i=0;i<num;i++)
        printf("%s ",arr[i]);
    printf("\n");
    int head[30],tile[30];
        for(int i=0;i<30;i++)
        {
            head[i] = 0;
            tile[i] = 0;
        }
        for(int i=0;i<num;i++)
        {
            int len = strlen(arr[i]);
            int headid = arr[i][0]-'a';
            int tileid = arr[i][len-1]-'a';
            if(tile[headid]>0)
            {
                tile[headid] --;

            }
            else
            {
                head[headid] ++;

            }
            if(head[tileid]>0&&(!(head[tileid]==1&&headid==tileid)))
            {
                head[tileid] --;

            }
            else
            {
                tile[tileid] ++;
            }
            printf("head:");
            for(int i=0;i<26;i++)
            {
                if(head[i]>0)
                {
                    printf("%c%d ",i+'a',head[i]);
                }
            }
            printf("   tile:");
             for(int i=0;i<26;i++)
            {
                if(tile[i]>0)
                {
                    printf("%c%d ",i+'a',tile[i]);
                }
            }
            printf("\n");

        }
            int ch=0,ct=0;
           // int ans;
            for(int i=0;i<26;i++)
            {
                if(head[i]==1) ch++;
                if(tile[i]==1) ct++;
                if(head[i]>1||tile[i]>1)
                {
                    return 0;
                }
            }
            printf("ch=%d,ct=%d\n",ch,ct);
            if(ch==1&&ct==1||ch==0&&ct==0)
            {
                return 1;
            }
            else return 0;



}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF){
        char arr[300][300];
        for(int i=0;i<n;i++)
            scanf("%s",arr[i]);
        printf("%d\n",hohoho(n,arr));


    }
    return 0;
}
