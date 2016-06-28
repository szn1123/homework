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
//小顶堆
//从i开始，到其父节点，父节点的父节点...，依次检查、调整以符合“小顶堆”的性质
void MinHeapAdjustUp(int data[], int i)
{
    if(i <= 0) return;
    int j, auxiliary;
    auxiliary =data[i];
    j = (i - 1) / 2; //父结点
    while(j >= 0&& i != 0)
    {
        if(data[j] <=auxiliary) break;
        data[i] = data[j]; //较大结点下移,替换它的子结点
        i =j;
        j = (i - 1) / 2;
    }
    data[i] =auxiliary;
}
//向“小顶堆”中添加新的数据
//每次插入都是将新数据放在数组最后，然后从新插入数据开始，
//到其父节点，父节点的父节点...，依次检查、调整以符合“小顶堆”的性质
void MinHeapAddData(int data[], int count, int new_data)
{
    data[count] =new_data;
    MinHeapAdjustUp(data, count);
}
//从i节点开始，进行一次从上向下的“小顶堆”调整
//count为节点总数，i节点的左右孩子节点依次为 2*i+1， 2*i+2
void MinHeapAdjustDown(int data[], int i, int count)
{
    int j, auxiliary;
    auxiliary =data[i];
    j = 2* i + 1; //左孩子结点
    while(j <count)
    {
        if(j + 1< count && data[j + 1] < data[j]) //在左右孩子中找最小的
            j++;
        if(data[j] >=auxiliary) break;
        data[i] = data[j]; //把较小的子结点往上移动,替换它的父结点
        i =j;
        j = 2* i + 1;
    }
    data[i] =auxiliary;
}
//从“小顶堆”中删除数据
//堆中每次都只能删除第0个数据。为便于重建堆，将最后一个数据的值赋给根结点
//然后再从根结点开始进行一次从上向下的调整
void MinHeapDeleteData(int data[], int count)
{
    Swap(data[0], data[count - 1]);
    MinHeapAdjustDown(data, 0, count - 1);
}
//建立“小顶堆”
//因为对叶子结点来说，它已经是一个合法的“小顶堆”
//所以这里只需要，从下往上，从右到左，将每个“非叶结点”当作根结点，将其与其子树调整成“小顶堆”
void MakeMinHeap(int data[], int count)
{
    for(int i = count / 2- 1; i >= 0; i--)
        MinHeapAdjustDown(data, i, count);
}
//堆排序（利用小顶堆，进行降序排序）
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
int get_h(Node tmp){   //获得估价函数H
	int ans=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(tmp.maze[i][j])
				ans+=abs(i-(tmp.maze[i][j]-1)/3)+abs(j-(tmp.maze[i][j]-1)%3);
	return ans;
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
				swap(v.maze[v.x][v.y],v.maze[u.x][u.y]);   //将空位和相邻位交换
				v.Hash=get_hash(v);			    //得到HASH值
				if(vis[v.Hash]==-1){   //判断是否已遍历且是否可行，后者可以不要
					vis[v.Hash]=i;           //保存方向
					v.g++;;                  //已花代价+1
					pre[v.Hash]=u.Hash;     //保存路径
					v.w=get_w(v);
					v.f=v.g+v.w;          //得到新的估价函数F
					open.push_back(v);//入队
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
		s.g=0;s.w=get_w(s);
		astar();
		print();
	}
    return 0;
}
