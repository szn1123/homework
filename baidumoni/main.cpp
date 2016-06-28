#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int dfs(int st,int cnt,int map[][30]){
    if(cnt == 0) return 1;
    for(int i=0;i<26;i++)
    {
        if(map[st][i]>0)
        {
            map[st][i] --;
            if(dfs(i,cnt-1,map)==1) return 1;
            map[st][i] ++;
        }
    }
    return 0;
}
int hohoho(int num,char arr[][300])
{

     int map[30][30];
     int head[30],tile[30];
     for(int i=0;i<30;i++)
        {
            head[i] = 0;
            tile[i] = 0;
            for(int j=0;j<30;j++)
                map[i][j]=0;
        }
    for(int i=0;i<num;i++)
    {
        int len = strlen(arr[i]);
            int headid = arr[i][0]-'a';
            int tileid = arr[i][len-1]-'a';
            map[headid][tileid] ++;
            head[headid] ++;
            tile[tileid] ++;
    }
    int h = -1;
    int ch=0,ct=0;
    for(int i=0;i<26;i++)
    {
        if(head[i]-tile[i]>1||tile[i]-head[i]>1) return 0;
        if(head[i]-tile[i]==1)
        {
            h = i;
           ch++;
        }
        if(tile[i]-head[i]==1) ct++;
    }
    int cnt=0;
    printf("ch=%d ct=%d\n",ch,ct);
    if(ch==1&&ct==1)
    {


        if(dfs(h,num,map)) return 1;
        else return 0;
    }
    else if(ch==0&&ct==0)
    {
        h=arr[0][0]-'a';
        if(dfs(h,num,map)) return 1;
        else return 0;
    }
    else return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF){
        char arr[300][300];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++)
            scanf("%s",arr[i]);
        printf("%d\n",hohoho(n,arr));


    }
    return 0;
}
