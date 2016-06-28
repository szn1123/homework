#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    char c;
    int p;
    int q;
}node[1005];
int cmp1(Node a,Node b){
    return a.p>b.p;
}
int cmp2(Node a,Node b){
    return a.p<b.p;
}
int main()
{
    int n,s;
    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&s)!=EOF){
        int ct=0;
        int vis[1005];

        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
             getchar();
            scanf("%c%d%d",&node[i].c,&node[i].p,&node[i].q);
        }
        vector<Node> S;
        vector<Node> B;
             vector<Node>::iterator it;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(vis[i]==1||vis[j]==1) continue;
                if(node[i].c==node[j].c&&node[i].p==node[j].p)
                {
                    if(node[i].c=='S')
                    {
                        int flag=0;
                        for(it = S.begin();it!=S.end();++it)
                        {
                            if(node[i].p==(*it).p)
                            {
                                (*it).q+=node[i].q;
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0)
                        {
                            node[i].q+=node[j].q;
                            vis[j]=1;
                            S.push_back(node[i]);
                        }

                    }
                    else if(node[i].c=='B')
                    {
                        int flag=0;
                        for(it = B.begin();it!=B.end();++it)
                        {
                            if(node[i].p==(*it).p)
                            {
                                (*it).q+=node[i].q;
                                flag=1;
                                break;
                            }
                        }
                        if(flag==0)
                        {
                            node[i].q+=node[j].q;
                            vis[j]=1;
                            B.push_back(node[i]);
                        }

                    }

                }
            }
        }

        if(S.size()<=s)
        {
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                    S.push_back(node[i]);
            }
            sort(S.begin(),S.end(),cmp1);
            for(it = S.begin();it!=S.end();++it)
            {
                printf("%c %d %d\n",(*it).c,(*it).p,(*it).q);
                printf("SS");
            }
        }
        else
        {
            for(int i=0;i<S.size()-s;i++)
            {
                S.erase(S.end()-1);
            }
             for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                    S.push_back(node[i]);
            }
             sort(S.begin(),S.end(),cmp1);
            for(it = S.begin();it!=S.end();++it)
            {
                printf("%c %d %d\n",(*it).c,(*it).p,(*it).q);
                printf("SS");
            }
        }
         if(B.size()<=s)
        {
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                    B.push_back(node[i]);
            }
            sort(B.begin(),B.end(),cmp2);
            for(it = B.begin();it!=B.end();++it)
            {
                printf("%c %d %d\n",(*it).c,(*it).p,(*it).q);
                printf("BB");
            }
        }
        else
        {
            for(int i=0;i<B.size()-s;i++)
            {
                B.erase(B.end()-1);
            }
             for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                    B.push_back(node[i]);
            }
             sort(B.begin(),B.end(),cmp1);
            for(it = B.begin();it!=B.end();++it)
            {
                printf("%c %d %d\n",(*it).c,(*it).p,(*it).q);
                printf("BB");
            }
        }
    }
    return 0;
}
