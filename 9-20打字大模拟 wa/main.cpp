#include <iostream>
#include  <cstdio>
#include <cstring>
#include <stdlib.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
char b[10010];
string ans;
crope a,board;
int main()
{
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        int m;
        memset(b,0,sizeof(b));
        a.clear();
        scanf("%d",&m);
        scanf("%s",b);
        int len=strlen(b);
        int p=0;//���ڹ���λ��
        bool cs=0,mode=0;//����״̬��0nothing��1start��ģʽ��0���룬1����
        int start;//���ƿ�ʼ��־
        for(int i=0;i<len;i++)
        {
            if(b[i]=='L')
            {
                if(p!=0) p--;
            }
            if(b[i]=='R')
            {
                if(p!=a.size()) p++;
            }
            if(b[i]=='S')
            {
                if(cs) cs=0;
                mode=!mode;
            }
            if(b[i]=='D')
            {
                if(cs)
                {
                    if(p>start)
                    {
                        a.erase(start,p-start);
                        p=start;
                    }
                    else
                    {
                        a.erase(p,start-p);
                    }
                    cs=0;
                }
                else
                {
                    if(a.size())//֮ǰ����д
                    {
                        if(p!=a.size())
                         a.erase(p,1);
                    }
                }
            }
             if(b[i]=='B')
            {
                if(cs) cs=0;
                if(p!=0)
                {
                    a.erase(p-1,1);
                    p--;
                }
            }
            if(b[i]=='C')
            {
                if(cs)
                {
                    board.clear();//���ճ���������ݣ�����д���һֱwa�˺þ�
                    if(p>start)
                    {
                        board=a.substr(start,p-start);
                    }
                    else if(p<start)
                    {
                        board=a.substr(p,start-p);
                    }
                    cs=0;
                }
                else
                {
                    start=p;
                    cs=1;
                }
            }
            if(b[i]=='V')
            {
                if(cs) cs=0;
                if(!board.empty()&&a.size()+board.size()<=m)
                {
                    if(mode==0)
                    {
                        for(int j=0;j<board.size();j++)
                            a.insert(p+j,board.at(j));
                        p=p+board.size();
                    }
                    else
                    {
                        for(int j=0;j<board.size();j++)
                            a.replace(p+j,board.at(j));
                        p=p+board.size();
                    }
                }
            }
            if(b[i]>='a'&&b[i]<='z')
            {
                if(cs) cs=0;
                if(a.size()<m)
                {
                    if(mode==0)
                    {
                        a.insert(p,b[i]);
                        p++;
                    }
                    else
                    {
                        if(p<a.size())
                            a.replace(p,b[i]);
                        else
                            a.push_back(b[i]);
                        p++;
                    }
                }
            }
        }
        if(a.empty()) printf("NOTHING\n");
        else cout<<a<<endl;
    }
    return 0;
}
