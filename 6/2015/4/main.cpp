#include <iostream>
#include <cstdio>
using namespace std;
const int Max=60000;
int Parent[Max],rank[Max];
int find(int p)
{
    if(Parent[p]==p) return p;
    Parent[p]=find(Parent[p]);
    return (Parent[p]);
}
int main()
{
    int n,m;
    int i;
    int a,b;
    cin>>n>>m;
    int t;
    t=1;
    while(n!=0&&m!=0)
    {
        int ans=0;
        for(i=1;i<=n;i++) Parent[i]=i;
        for(i=1;i<=m;i++)
        {
            cin>>a>>b;
            find(a);
            find(b);
            Parent[Parent[a]]=Parent[b];
        }
        for(i=1;i<=n;i++)
        {
            find(i);
            if(Parent[i]==i) ans++;
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
        cin>>n>>m;
        t++;
    }
    return 0;
}
