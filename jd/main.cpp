#include <cstdio>
#include <cmath>
using namespace std;
int main(){
      int m,n;

      while(scanf("%d%d",&m,&n)!=EOF)
      {
          bool flag = 0;
            for(int i=m;i<=n;i++)
          {
              int g = i%10;
              int s = i%100/10;
              int b = i/100;
              if(g*g*g+s*s*s+b*b*b==i)
              {
                  if(flag==0)
                  {
                      printf("%d",i);
                      flag=1;
                  }
                  else{
                      printf(" %d",i);
                  }

              }
          }
          if(flag==0) printf("no");
          printf("\n");

      }
      return 0;
}
