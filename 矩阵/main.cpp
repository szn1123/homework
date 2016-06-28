/*
输出具有该规律的矩阵
输入
开始数字和矩阵大小如 1 3
输出
1 2 5
4 3 6
9 8 7
*/
#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;
// 以a[4][4]为例
//该矩阵的规律是以矩阵起始数为起点，承螺旋形递增，以起始数为1，尺寸为4为例，按照螺旋形，矩阵值分别为1 2 3 4 5····16
int **ArrayConstruct(int startNum,int ArraySize)  // 矩阵开始数，矩阵尺寸
{
    int **a;  //申请a[4][4]的空间
    if(ArraySize==1){
        a[0][0] = startNum;
    }
    else{
        ArrayConstruct(startNum,ArraySize-1); //递归调用该函数
          a[0][ArraySize-1] = a[ArraySize-2][0]+1; //将a[0][3]赋值为[2][0]+1
         for(int i=1;i<ArraySize;i++){
            a[i][ArraySize-1] = a[i-1][ArraySize-1]+1; //对 a[0][3]——a[3][3]依次赋值
        }
        for(int i=ArraySize-2;i>=0;i--){
            a[ArraySize-1][i] = a[ArraySize-1][i+1]+1; //对a[3][3]——a[3][0]依次赋值
        }
    }
    return a;
}


int main()
{
    int startNum,Arraysize;
    scanf("%d%d",&startNum,Arraysize);
    int **a;
    a = ArrayConstruct(startNum,Arraysize);//调用函数
    //输出该矩阵
    for(int i=0;i<Arraysize;i++){
    for(int j=0;j<Arraysize;j++){
        printf("%d\t",a[i][j]);
    }
    printf("\n");
    }
    return 0;
}
