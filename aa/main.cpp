#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a[]={1,2,3,4,5};
    int*p[]={a,a+1,a+2,a+3};
    int **q=p;
    cout<<*(p[0]+1)+**(q+2);
    return 0;
}
