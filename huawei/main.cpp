#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Line{
    int id;
    int s;
    int d;
    int w;
}line[5000];//边
int pre[650];//路径点保存
int rode[650];//路径边保存
int map[650][10];//边的line索引关系表
int lineCount[650];//关系边的个数
int v[55];//必须经过的点
int vis[650];
int x,y;
long long hash[55];
struct Node{
    int point;
    int f,d,p;//f=d+p d已走步数 p未经过的点数
    long long visHash;
    set<int> vis;
}node[650];
Node start,end;
int cmp(Node a,Node b){
    if(a.f==b.f)
    {
        return a.p>b.p;
    }
    return a.f<b.f;
}
int pn(){
    int sum = 0;
    for(int i = 0;i<y;i++)
    {
        sum+=line[i].w;
    }
    return sum/y;
}
void init()
{
    freopen("result.csv","w",stdout);

   // printf("start=%d,end=%d\n",start,end);
   /* for(int i=0;i<x;i++)
    {
        printf("%d,",v[i]);
    }
    printf("\n");*/
    y=0;//边数
    freopen("topo.csv","r",stdin);
    while((scanf("%d,%d,%d,%d",&line[y].id,&line[y].s,&line[y].d,&line[y].w)!=EOF))
    {
        y++;
        getchar();
    }
   // for(int i=0;i<y;i++)
   // {
       // printf("i=%d,lineid=%d,ls=%d,ld=%d,lw=%d\n",i,line[i].id,line[i].s,line[i].d,line[i].w);
   // }
    for(int i=0;i<y;i++){
        map[line[i].s][lineCount[line[i].s]++]=i;
    }
    freopen("demand.csv","r",stdin);

    scanf("%d,",&start.point);
    scanf("%d,",&end.point);
    x=0;//必经点的个数
    hash[0]=1;
    for(int i=1;i<50;i++)
    {
        hash[i]=hash[i-1]*2;
    }
    while((scanf("%d",&v[x]))!=EOF)
    {
        x++;
        getchar();
    }
     start.d = 0;
     start.p = x;

     start.visHash = hash[x]-1;
     start.f = start.d+start.p*pn();
     start.vis.insert(start.point);

}
void debug(Node node){
    printf("debug--------\n");
    printf("point=%d\n",node.point);
  //  printf("p=%d\n",node.p);
    //printf("d=%d\n",node.d);
    printf("f=%d\n",node.f);
    //printf("hash=%I64d\n",node.visHash);
}
vector<Node> close_set;
vector<Node> open_set;
std::vector<Node>::iterator openHasIt;
vector<Node>::iterator closeHasIt;
void Astar(){
    int Pn = pn();
    open_set.push_back(start);
    while(!open_set.empty()){
        Node u = *open_set.begin();
      //  printf("u=%d ",u.point);

        // debug(u);
       //  printf("----u");
        open_set.erase(open_set.begin());
        //printf("lineCount[0]=%d\n",lineCount[0]);
        for(int i=0;i<lineCount[u.point];i++){//u的每个子节点

            Node now = u;

            now.point = line[map[u.point][i]].d;//当前子节点
            if(now.vis.count(now.point)==1) continue;
            now.vis.insert(now.point);
            if(now.point==end.point&&now.p!=0) continue;
           // debug(now);
            bool flag1 = 0,flag2=0;
            vector<Node>::iterator it;

            now.d=u.d+line[map[u.point][i]].w;
            bool isv = 0;
            int j;
                for(j=0;j<x;j++){
                    if(v[j]==now.point)
                    {
                        isv=true;
                        break;
                    }
                }
                if(isv&&((hash[j]|u.visHash)==u.visHash))
                {
                    now.p=u.p-1;
                    now.visHash = u.visHash - hash[j];
                }
                now.f=now.d+now.p*Pn;//求估价函数f


             for(it = open_set.begin();it!=open_set.end();++it)
            {
                if((*it).point==now.point&&(*it).p==now.p)
                {
                     flag1=1;
                     openHasIt = it;
                }

            }
              for(it = close_set.begin();it!=close_set.end();++it)
            {
                if((*it).point==now.point&&(*it).p==now.p)
                {
                     flag2=1;
                     closeHasIt = it;
                }

            }
            if(!flag1&&!flag2){


                pre[now.point]=u.point;
                rode[now.point]=line[map[u.point][i]].id;

                open_set.push_back(now);
            //    printf("newnow=%d\n",now.point);



            }
            else if(flag1){

                if(now.f<(*openHasIt).f)
                {
                    (*openHasIt) = now;
                    pre[now.point]=u.point;
                rode[now.point]=line[map[u.point][i]].id;
                //    printf("openhasit---");
                //    debug(*openHasIt);
                }
               // printf("flushopen=%d\n",now.point);

            }
            else
            {

                if(now.f<(*closeHasIt).f)
                {
                     Node lala;
                     lala = now;
                     pre[now.point]=u.point;
                rode[now.point]=line[map[u.point][i]].id;
                    close_set.erase(closeHasIt);
                    open_set.push_back(lala);
                  //  debug(lala);
                }
               // printf("closehasit");
               // debug(*closeHasIt);

              //  printf("flushclose=%d\n",now.point);
               // debug(lala);
               // printf("hohoho\n");
            }
           // debug(now);



            sort(open_set.begin(),open_set.end(),cmp);
             if(now.point==end.point&&now.p==0) return;

        }
        close_set.push_back(u);
    }
}
void print()
{
    int ans[650];
    memset(ans,0,sizeof(ans));
    int nxt=end.point;
    int haha=0;

    //printf("ans-------begin\n");
    while(nxt!=start.point)
    {
      //  printf("%d ",nxt);
        ans[haha++]=rode[nxt];
      //  printf("haha=%d\n",haha);
        nxt = pre[nxt];

    }
     if(haha==0)printf("NA\n");
        else
        {
            for(int i=haha-1;i>0;i--)
            {
                printf("%d|",ans[i]);
            }

        }
    printf("%d\n",ans[0]);
    //printf("ans-------end\n");
}
int main()
{
    init();
    Astar();
    print();
 //   for(int i=0;i<20;i++){
   //     for(int j=0;j<lineCount[i];j++)
      //  printf("map[%d][%d]=%d\n",i,j,map[i][j]);
  //  }
    return 0;
}
