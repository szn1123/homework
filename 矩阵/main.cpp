/*
������иù��ɵľ���
����
��ʼ���ֺ;����С�� 1 3
���
1 2 5
4 3 6
9 8 7
*/
#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;
// ��a[4][4]Ϊ��
//�þ���Ĺ������Ծ�����ʼ��Ϊ��㣬�������ε���������ʼ��Ϊ1���ߴ�Ϊ4Ϊ�������������Σ�����ֵ�ֱ�Ϊ1 2 3 4 5��������16
int **ArrayConstruct(int startNum,int ArraySize)  // ����ʼ��������ߴ�
{
    int **a;  //����a[4][4]�Ŀռ�
    if(ArraySize==1){
        a[0][0] = startNum;
    }
    else{
        ArrayConstruct(startNum,ArraySize-1); //�ݹ���øú���
          a[0][ArraySize-1] = a[ArraySize-2][0]+1; //��a[0][3]��ֵΪ[2][0]+1
         for(int i=1;i<ArraySize;i++){
            a[i][ArraySize-1] = a[i-1][ArraySize-1]+1; //�� a[0][3]����a[3][3]���θ�ֵ
        }
        for(int i=ArraySize-2;i>=0;i--){
            a[ArraySize-1][i] = a[ArraySize-1][i+1]+1; //��a[3][3]����a[3][0]���θ�ֵ
        }
    }
    return a;
}


int main()
{
    int startNum,Arraysize;
    scanf("%d%d",&startNum,Arraysize);
    int **a;
    a = ArrayConstruct(startNum,Arraysize);//���ú���
    //����þ���
    for(int i=0;i<Arraysize;i++){
    for(int j=0;j<Arraysize;j++){
        printf("%d\t",a[i][j]);
    }
    printf("\n");
    }
    return 0;
}
