#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<map>
#include<string>
#define inf 1<<30
#define eps 1e-7
#define LD long double
#define LL long long
#define maxn 1000000005
using namespace std;
int hhhh;
struct Node{
	int maze[3][3];   //八数码具体情况
	int f,d,w,p;    //估价函数
	int x,y;   //空位的位置
	int Hash;   //HASH值
	friend bool operator<(Node n1,Node n2){     //优先队列关键字为f
		return n1.f>n2.f;
	}
	bool check(){    //判断是否合法
		if(x>=0&&x<3&&y>=0&&y<3)
			return true;
		return false;
	}
}s,u,v,tt,goal;
int HASH[9]={1,1,2,6,24,120,720,5040,40320};   //HASH的权值
int destination;   //目标情况的HASH值
int vis[400000];            //判断状态已遍历，初始为-1，否则为到达这步的转向（相当于加入了close表）
int pre[400000];        //路径保存
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};   //四个方向
void debug(Node tmp){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			printf("%d ",tmp.maze[i][j]);
		printf("\n");
	}
	printf("x=%d y=%d\nd=%d p=%d\n",tmp.x,tmp.y,tmp.d,tmp.p);
	printf("hash=%d\n",tmp.Hash);
}
int get_hash(Node tmp){    //获得HASH值
	int a[9],k=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[k++]=tmp.maze[i][j];
	int res=0;
	for(int i=0;i<9;i++){
		int k=0;
		for(int j=0;j<i;j++)
			if(a[j]>a[i])
				k++;
		res+=HASH[i]*k;
	}
	return res;
}
bool isok(Node tmp){    //求出逆序对，判断是否有解
	int a[9],k=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[k++]=tmp.maze[i][j];
	int sum=0;
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
			if(a[j]&&a[i]&&a[i]>a[j])
				sum++;
	return !(sum&1);    //由于目标解为偶数，所以状态的逆序数为偶数才可行
}
int get_w(Node tmp){   //获得估价函数W
	int ans=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(tmp.maze[i][j])
				if(tmp.maze[i][j]!=goal.maze[i][j])
                    ans++;
	return ans;
}
struct position
{
    int x;
    int y;
}pos[9];
int get_p(Node tmp){   //获得估价函数p
	int ans=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
		    pos[goal.maze[i][j]].x=i;
		    pos[goal.maze[i][j]].y=j;
		}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(tmp.maze[i][j])
				ans+=abs(pos[tmp.maze[i][j]].x-i)+abs(pos[tmp.maze[i][j]].y-j);
	return ans;
}
void astar(){    //搜索
	priority_queue<Node>que;
	que.push(s);
	int lll=0;
	while(!que.empty()){

		u=que.top();
		que.pop();

		for(int i=0;i<4;i++){
			v=u;
			v.x+=way[i][0];
			v.y+=way[i][1];
			if(v.check()){
				swap(v.maze[v.x][v.y],v.maze[u.x][u.y]);   //将空位和相邻位交换
				v.Hash=get_hash(v);			    //得到HASH值
				if(vis[v.Hash]==-1){   //判断是否已遍历且是否可行，后者可以不要
					vis[v.Hash]=i;           //保存方向
					v.d++;             //已花代价+1
					pre[v.Hash]=u.Hash;     //保存路径
					v.p=get_p(v);
					v.f=v.d+v.p;
					cout<<"u:"<<endl;
					debug(u);
					cout<<"v:"<<endl;
					debug(v);
					cout<<"i="<<i<<endl;cout<<"lll="<<lll++<<endl;
                   // cin>>hhhh;   //得到新的估价函数H
					que.push(v);     //入队
				}
				if(v.Hash==destination)
					return ;
			}
		}
	}
}
void print(){
	string ans;
	ans.clear();
	int nxt=destination;
	while(pre[nxt]!=-1){  //从终点往起点找路径
		switch(vis[nxt]){   //四个方向对应
		case 0:ans+='r';break;
		case 1:ans+='l';break;
    	case 2:ans+='d';break;
    	case 3:ans+='u';break;
    	}
		nxt=pre[nxt];
	}
	for(int i=ans.size()-1;i>=0;i--)
		putchar(ans[i]);
	puts("");
}
int main(){
	char str[100];
	char str1[100];
	freopen("in.txt","r",stdin);
	int xxoo=1;
	while(xxoo--)
	{
	    printf("请输入初始状态：\n");
	    gets(str);
	    printf("请输入目标状态：\n");
	    gets(str1);
		int k=0;
		memset(vis,-1,sizeof(vis));
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				if(str[k]<='9'&&str[k]>='0'){
					if(str[k]=='0'){
						s.maze[i][j]=0;
						s.x=i;
						s.y=j;
					}
					else
						s.maze[i][j]=str[k]-'0';
				}
				else
					j--;
				k++;
			}
			k=0;
        for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				if(str1[k]<='9'&&str1[k]>='0'){
					if(str1[k]=='0'){
						goal.maze[i][j]=0;
						goal.x=i;
						goal.y=j;
					}
					else
						goal.maze[i][j]=str1[k]-'0';
				}
				else
					j--;
				k++;
			}
        destination=get_hash(goal);
		if(isok(s)!=isok(goal)){   //起始状态不可行
			printf("unsolvable\n");
			continue;
		}
		s.Hash=get_hash(s);
		if(s.Hash==destination){   //起始状态为目标状态
			puts("");
			continue;
		}
		vis[s.Hash]=-2;
		s.d=0;s.p=get_p(s);
		//debug(s);
		astar();
		print();
	}
	return 0;
}
