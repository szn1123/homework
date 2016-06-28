#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char dict[10010][20];
int dc;
char word[20];
bool change(char * word,char *dict)
{
    int dif=0;
    while(*word)
    {
        if(*(word++)!=*(dict++))
        {
            dif++;
            if(dif>1)
                return false;
        }
    }
    return true;
}
bool del(char * word,char * dict)
{
    int dif=0;
    while(*word)
    {
        if(*word!=*dict)
        {
            word++;
            dif++;
            if(dif>1)
                return false;
        }
        else
        {
            word++;
            dict++;
        }
    }
    return true;
}
bool add(char *word,char *dict)
{
    int dif=0;
    while(*word)
    {
        if(*word!=*dict)
        {
            dict++;
            dif++;
            if(dif>1)
                return false;
        }
        else
        {
            word++;
            dict++;
        }
    }
    return true;
}
int address[10010];
int main()
{
    dc=0;
    freopen("in.txt","r",stdin);
    while(1)
    {
        scanf("%s",dict[dc]);
        if(dict[dc++][0]=='#') break;
    }
    dc--;
    int dl[10010];
    for(int i=0;i<dc;i++)
        dl[i]=strlen(dict[i]);
    while(scanf("%s",word)&&word[0]!='#')
    {
        bool flag=0;
        int pa=0;
        int l=strlen(word);
        for(int k=0;k<dc;k++)
        {
            if(dl[k]==l)
            {
                if(strcmp(word,dict[k])==0)
                {
                    flag=1;
                    break;
                }
                else if(change(word,dict[k]))
                {
                    address[pa++]=k;
                }
            }
            else if(l-dl[k]==1)
            {
                if(del(word,dict[k]))
                {
                    address[pa++]=k;
                }
            }
            else if(dl[k]-l==1)
            {
                if(add(word,dict[k]))
                {
                    address[pa++]=k;
                }
            }
        }
        if(flag)
            printf("%s is correct\n",word);
        else
        {
            printf("%s: ",word);
            for(int j=0;j<pa;j++)
            {
                printf("%s ",dict[address[j]]);
            }
            printf("\n");
        }
        memset(address,0,sizeof(address));
    }

    return 0;
}
