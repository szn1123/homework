#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct Node
{
    char maze[9];
    int f,h,g;
    int x,y;
    int hash;
    bool check()
    {
        if(x>=0&&x<3&&y>=0&&y<3)
            return true;
        return false;
    }

}s,u;
void Swap(int& left_data, int&right_data)
{
    int auxiliary =left_data;
    left_data =right_data;
    right_data =auxiliary;
}
//----------------------------------------------------------------------------------
//С����
//��i��ʼ�����丸�ڵ㣬���ڵ�ĸ��ڵ�...�����μ�顢�����Է��ϡ�С���ѡ�������
void MinHeapAdjustUp(int data[], int i)
{
    if(i <= 0) return;
    int j, auxiliary;
    auxiliary =data[i];
    j = (i - 1) / 2; //�����
    while(j >= 0&& i != 0)
    {
        if(data[j] <=auxiliary) break;
        data[i] = data[j]; //�ϴ�������,�滻�����ӽ��
        i =j;
        j = (i - 1) / 2;
    }
    data[i] =auxiliary;
}
//��С���ѡ�������µ�����
//ÿ�β��붼�ǽ������ݷ����������Ȼ����²������ݿ�ʼ��
//���丸�ڵ㣬���ڵ�ĸ��ڵ�...�����μ�顢�����Է��ϡ�С���ѡ�������
void MinHeapAddData(int data[], int count, int new_data)
{
    data[count] =new_data;
    MinHeapAdjustUp(data, count);
}
//��i�ڵ㿪ʼ������һ�δ������µġ�С���ѡ�����
//countΪ�ڵ�������i�ڵ�����Һ��ӽڵ�����Ϊ 2*i+1�� 2*i+2
void MinHeapAdjustDown(int data[], int i, int count)
{
    int j, auxiliary;
    auxiliary =data[i];
    j = 2* i + 1; //���ӽ��
    while(j <count)
    {
        if(j + 1< count && data[j + 1] < data[j]) //�����Һ���������С��
            j++;
        if(data[j] >=auxiliary) break;
        data[i] = data[j]; //�ѽ�С���ӽ�������ƶ�,�滻���ĸ����
        i =j;
        j = 2* i + 1;
    }
    data[i] =auxiliary;
}
//�ӡ�С���ѡ���ɾ������
//����ÿ�ζ�ֻ��ɾ����0�����ݡ�Ϊ�����ؽ��ѣ������һ�����ݵ�ֵ���������
//Ȼ���ٴӸ���㿪ʼ����һ�δ������µĵ���
void MinHeapDeleteData(int data[], int count)
{
    Swap(data[0], data[count - 1]);
    MinHeapAdjustDown(data, 0, count - 1);
}
//������С���ѡ�
//��Ϊ��Ҷ�ӽ����˵�����Ѿ���һ���Ϸ��ġ�С���ѡ�
//��������ֻ��Ҫ���������ϣ����ҵ��󣬽�ÿ������Ҷ��㡱��������㣬�����������������ɡ�С���ѡ�
void MakeMinHeap(int data[], int count)
{
    for(int i = count / 2- 1; i >= 0; i--)
        MinHeapAdjustDown(data, i, count);
}
//����������С���ѣ����н�������
void MinHeapSortDesc(int data[], int count)
{
    for(int i = count - 1; i >= 1; i--)
    {
        Swap(data[i], data[0]);
        MinHeapAdjustDown(data, 0, i); }
}
int get_hash(Node tmp)
{
    int ni[9];
    memset(ni,0,sizeof(ni));
    for(int i=0;i<9;i++)
    {
        if(tmp.maze[i]==0)
        {
            ni[i]=9-i;
        }
        else
         for(int j=0;j<i;j++)
        {
            if(tmp.maze[j]>tmp.maze[i])
            {
              //  cout<<data[j]<<" "<<data[i]<<endl;
                ni[i]++;
              //  cout<<"ni["<<i<<"]="<<ni[i]<<endl;
            }
        }
    }
    int ret=0;
    int x=1;
    for(int i=1;i<9;i++)
    {
        x*=i;
        ret+=x*ni[i];
    }
    return ret;
}
int vis[400000];
int pre[400000];
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
int get_h(Node tmp){   //��ù��ۺ���H
	int ans=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(tmp.maze[i][j])
				ans+=abs(i-(tmp.maze[i][j]-1)/3)+abs(j-(tmp.maze[i][j]-1)%3);
	return ans;
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
				ans+=abs(pos[tmp.maze[i][j]].x-(tmp.maze[i][j]-1)/3)+abs(pos[tmp.maze[i][j]].y-(tmp.maze[i][j]-1)%3);
	return ans;
}
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void astar()
{
    vector<Node>open;
    vector<Node>close;
    open.push_back(s);
    while(open.size()!=0)
    {
        u=open[0];
        for(int i=0;i<4;i++){

			v=u;
			v.x+=way[i][0];
			v.y+=way[i][1];
			if(v.check()){
				swap(v.maze[v.x][v.y],v.maze[u.x][u.y]);   //����λ������λ����
				v.Hash=get_hash(v);			    //�õ�HASHֵ
				if(vis[v.Hash]==-1){   //�ж��Ƿ��ѱ������Ƿ���У����߿��Բ�Ҫ
					vis[v.Hash]=i;           //���淽��
					v.g++;;                  //�ѻ�����+1
					pre[v.Hash]=u.Hash;     //����·��
					v.w=get_w(v);
					v.f=v.g+v.w;          //�õ��µĹ��ۺ���F
					open.push_back(v);//���
					MakeMinHeap(open);
				}
				if(v.Hash==destination)
					return ;
			}
		}

    }
}
int main()
{
    char str[100];
	char str1[100];
	while(1){
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
		s.g=0;s.w=get_w(s);
		astar();
		print();
	}
    return 0;
}
