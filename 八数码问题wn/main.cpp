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
	int maze[3][3];   //������������
	int f,d,w,p;    //���ۺ���
	int x,y;   //��λ��λ��
	int Hash;   //HASHֵ
	friend bool operator<(Node n1,Node n2){     //���ȶ��йؼ���Ϊf
		return n1.f>n2.f;
	}
	bool check(){    //�ж��Ƿ�Ϸ�
		if(x>=0&&x<3&&y>=0&&y<3)
			return true;
		return false;
	}
}s,u,v,tt,goal;
int HASH[9]={1,1,2,6,24,120,720,5040,40320};   //HASH��Ȩֵ
int destination;   //Ŀ�������HASHֵ
int vis[400000];            //�ж�״̬�ѱ�������ʼΪ-1������Ϊ�����ⲽ��ת���൱�ڼ�����close��
int pre[400000];        //·������
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};   //�ĸ�����
void debug(Node tmp){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			printf("%d ",tmp.maze[i][j]);
		printf("\n");
	}
	printf("x=%d y=%d\nd=%d p=%d\n",tmp.x,tmp.y,tmp.d,tmp.p);
	printf("hash=%d\n",tmp.Hash);
}
int get_hash(Node tmp){    //���HASHֵ
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
bool isok(Node tmp){    //�������ԣ��ж��Ƿ��н�
	int a[9],k=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[k++]=tmp.maze[i][j];
	int sum=0;
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
			if(a[j]&&a[i]&&a[i]>a[j])
				sum++;
	return !(sum&1);    //����Ŀ���Ϊż��������״̬��������Ϊż���ſ���
}
int get_w(Node tmp){   //��ù��ۺ���W
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
int get_p(Node tmp){   //��ù��ۺ���p
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
void astar(){    //����
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
				swap(v.maze[v.x][v.y],v.maze[u.x][u.y]);   //����λ������λ����
				v.Hash=get_hash(v);			    //�õ�HASHֵ
				if(vis[v.Hash]==-1){   //�ж��Ƿ��ѱ������Ƿ���У����߿��Բ�Ҫ
					vis[v.Hash]=i;           //���淽��
					v.d++;             //�ѻ�����+1
					pre[v.Hash]=u.Hash;     //����·��
					v.p=get_p(v);
					v.f=v.d+v.p;
					cout<<"u:"<<endl;
					debug(u);
					cout<<"v:"<<endl;
					debug(v);
					cout<<"i="<<i<<endl;cout<<"lll="<<lll++<<endl;
                   // cin>>hhhh;   //�õ��µĹ��ۺ���H
					que.push(v);     //���
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
	while(pre[nxt]!=-1){  //���յ��������·��
		switch(vis[nxt]){   //�ĸ������Ӧ
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
	    printf("�������ʼ״̬��\n");
	    gets(str);
	    printf("������Ŀ��״̬��\n");
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
		if(isok(s)!=isok(goal)){   //��ʼ״̬������
			printf("unsolvable\n");
			continue;
		}
		s.Hash=get_hash(s);
		if(s.Hash==destination){   //��ʼ״̬ΪĿ��״̬
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
