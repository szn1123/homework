#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char a[100];
int len;
void PreOrder(int i){
    if(i>=len) return;
    if(a[i]!='#')
     printf("%c",i,a[i]);
    PreOrder(i*2);
    PreOrder(i*2+1);



}
int main(){

    scanf("%s",a);
    len = strlen(a);
    PreOrder(1);
    return 0;
}

