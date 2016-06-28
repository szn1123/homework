#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define LL long long
#define FOR(i,x,y)  for(int i = x;i < y;i ++)
#define IFOR(i,x,y) for(int i = x;i > y;i --)
#define MAXN 11000

using namespace std;

int n,m,du[MAXN];
bool vis[MAXN];
LL v[MAXN];

queue <int> q;

vector <int> mat[MAXN];

void topo(){
    while(!q.empty()){
        int u = q.front();  q.pop();
        vis[u] = true;
        for(int i = 0;i < mat[u].size();i ++){
            int v = mat[u][i];
            du[v] --;
            if(du[v] == 1){
                q.push(v);
            }
            if(!du[v]){
                vis[v] = true;
            }
        }
    }
}

int cnt;
LL ans;
LL w;

void dfs(int u){
    vis[u] = true;
    w += v[u];
    cnt ++;
    for(int i = 0;i < mat[u].size();i ++){
        int k = mat[u][i];
        if(vis[k])  continue;
        dfs(k);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        FOR(i,1,n+1){
            scanf("%I64d",&v[i]);
        }
        if(!q.empty())  q.pop();
        FOR(i,1,n+1)    mat[i].clear();
        int u,k;
        memset(du,0,sizeof(du));
        FOR(i,0,m){
            scanf("%d%d",&u,&k);
            mat[u].push_back(k);
            mat[k].push_back(u);
            du[u]++;
            du[k]++;
        }
        memset(vis,false,sizeof(vis));
        FOR(i,1,n+1){
            if(!du[i]){
                vis[i] = true;
                continue;
            }
            if(du[i] == 1){
                q.push(i);
            }
        }
        topo();
        ans = 0;
        FOR(i,1,n+1){
            if(!vis[i]){
                cnt = 0; w = 0;
                dfs(i);
                if(cnt % 2){
                    ans += w;
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
