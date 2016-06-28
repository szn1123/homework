#include <iostream>
#include <cstido>
#include <cstring>
using namespace std;
const int maxnode=1000000+100;
const int sigma_size=26;
int sz;//字典树节点个数
struct Trie
{
    int ch[sigma_size];//节点编号
    int val;//节点的值
    bool isword;
}trie[maxnode];
    void init()
    {
        sz=1;
        //memset(ch,0,sizeof(ch));
        memset(trie,0,sizeof(trie));
    }
    void insert(char *s)
    {
        int n=strlen(s),u=0;
        for(int i=0;i<n;i++)
        {
            int id=s[i]-'a';
            if(trie[u].ch[id]==0)
            {
                trie[u].ch[id]=sz++;
            }
            u=trie[u].ch[id];
            trie[u].val++;

        }

    }
}
int main()
{

    return 0;
}
