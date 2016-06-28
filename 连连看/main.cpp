#include <iostream>
#include <cstdio>
using namespace std;
int map[1005][1005];
int main()
{
    int m,n;
    bool flag1,flag2,flag3;
    freopen("in.txt","r",stdin);
    scanf("%d%d",&m,&n);
    while(m!=0&&n!=0)
    {
        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&map[i][j]);
        int c;
        scanf("%d",&c);
        for(int i=0;i<c;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            bool ans = 0;
            if(map[x1][y1]!=map[x2][y2]||map[x1][y1]==0||map[x2][y2]==0) //���ε����ͼ����ͬ����ͼ��Ϊ�հ����ܱ���ȥ
            {
                ans=0;
                printf("NO\n");
                continue;
            }
               int minx,maxx;
                if(x1>x2)
                {
                    maxx=x1;
                    minx=x2;
                }
                else{
                    minx=x1;
                    maxx=x2;
                }

            int miny,maxy;
                if(y1>y2)
                {
                    maxy=y1;
                    miny=y2;
                }
                else{
                    miny=y1;
                    maxy=y2;
                }
            if(x1==x2) //ֻ��Ҫ��һ���ߵ����
            {
                ans=1;
                for(int j=miny+1;j<maxy;j++)
                {
                    if(map[x1][j]!=0)
                    {
                        ans=0;
                        break;
                    }
                }
                if(ans==1)
                {
                    printf("YES\n");
                    continue;
                }
            }
             if(y1==y2)
            {
                ans=1;
                for(int j=minx+1;j<maxx;j++)
                {
                    if(map[j][y1]!=0)
                    {
                        ans=0;
                        break;
                    }
                }
                if(ans==1)
                {
                    printf("YES\n");
                    continue;
                }
            }
            int ex;
            if(x1>x2)
            {
                ex=x1;
                x1=x2;
                x2=ex;
                ex=y1;
                y1=y2;
                y2=ex;
            }

            for(int i=1;i<=m;i++)//�������������ߵ���� flag1�Ǻ��� flag2 flag3�ֱ�����������
            {
                flag1 = 1;


                for(int j=miny+1;j<maxy;j++)// ������
                {
                    if(map[i][j]!=0)
                    {
                        flag1=0;
                        break;
                    }
                }
                if(flag1==1) //���ں��ߵ�ʱ��ſ�������
                {
                    flag2=1;

                    //��x1y1������ߵ�����
                    if(i>x1)//��Ϊ���߿���������֮�� �м� ��������֮�� �������ߵ���ʼ��ֹ����Ҫ���������
                    {
                        for(int j=x1+1;j<=i;j++)
                        if(map[j][y1]!=0)
                        {
                            flag2=0;
                            break;
                        }
                    }
                    else //i==x1���������Ҳ�������� Ҳ���������ߵ����
                    {
                       for(int j=i;j<x1;j++)
                        if(map[j][y1]!=0)
                        {
                            flag2=0;
                            break;
                        }
                    }

                    flag3=1;
                    //��x2y2�����ߵ�����
                    if(i>x2)
                    {
                        for(int j=x2+1;j<=i;j++)
                        {
                            if(map[j][y2]!=0)
                            {
                                flag3=0;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(int j=i;j<x2;j++)
                        {
                            if(map[j][y2]!=0)
                            {
                                flag3=0;
                                break;
                            }
                        }
                    }

                    if(flag2==1&&flag3==1)//������ͬʱ���ڲſ�����ȥ
                    {
                        ans=1;
                        break;//ֻҪ�ҵ����������߾�ȷ��������ȥ
                    }
                }
            }
            if(ans==1)
            {
               // printf("heng---%d%d%d",flag1,flag2,flag3);
                printf("YES\n");
                continue;
            }
            if(y1>y2)
            {
                ex=x1;
                x1=x2;
                x2=ex;
                ex=y1;
                y1=y2;
                y2=ex;
            }
             for(int i=1;i<=n;i++) //����������
            {
                flag1 = 1;


                for(int j=minx;j<=maxx;j++)//������
                {
                    if(map[j][i]!=0)
                    {
                        flag1=0;
                        break;
                    }
                }
                if(flag1==1)
                {
                    flag2=1;

                    if(i>y1)//����1
                    {
                        for(int j=y1+1;j<=i;j++)
                        if(map[x1][j]!=0)
                        {
                            flag2=0;
                            break;
                        }
                    }
                    else
                    {
                        for(int j=i;j<y1;j++)
                        if(map[x1][j]!=0)
                        {
                            flag2=0;
                            break;
                        }
                    }

                    flag3=1;

                    if(i>y2)//����2
                    {
                       for(int j=y2+1;j<=i;j++)
                        {
                            if(map[x2][j]!=0)
                            {
                                flag3=0;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(int j=i;j<y2;j++)
                        {
                            if(map[x2][j]!=0)
                            {
                                flag3=0;
                                break;
                            }
                        }
                    }

                    if(flag2==1&&flag3==1)
                    {
                        ans=1;
                        break;
                    }
                }
            }
          // printf("shu---%d%d%d",flag1,flag2,flag3);
            if(ans==1) printf("YES\n");
            else printf("NO\n");//��������������ܲ����no

        }
        scanf("%d%d",&m,&n);
    }
    return 0;
}
