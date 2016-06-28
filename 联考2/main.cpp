#include <iostream>
#include <cstdio>
#include <cmath>
#define pi 3.14159265358979
using namespace std;
double abs(double x,double y)
{
    if(x>y) return x-y;
    else return y-x;
}
double bian(double x1,double x2,double y1,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double cosj(double a,double b,double c)
{
    return ((a*a+b*b-c*c)/(2*a*b));
}
int main()
{
    int t;
    freopen("in.txt","r",stdin);
    scanf("%d",&t);
    double x1,x2,x3,y1,y2,y3;
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        double a,b,c,d,f,e,x,y;
        a=2*(x2-x1);
        b=2*(y2-y1);
        c=x2*x2+y2*y2-x1*x1-y1*y1;
        d=2*(x3-x2);
        e=2*(y3-y2);
        f=x3*x3+y3*y3-x2*x2-y2*y2;
        x=(b*f-e*c)/(b*d-e*a);
        y=(d*c-a*f)/(b*d-e*a);
       // printf("x=%lf y=%lf ",x,y);
        double j1,j2,j3;
        double a1,a2,a3,b1,b2,b3,c1,c2,c3;
        c1=bian(x1,x2,y1,y2);
        a1=bian(x1,x,y1,y);
        b1=bian(x2,x,y2,y);
        c2=bian(x2,x3,y2,y3);
        a2=bian(x2,x,y2,y);
        b2=bian(x3,x,y3,y);
        c3=bian(x1,x3,y1,y3);
        b3=bian(x1,x,y1,y);
        a3=bian(x3,x,y3,y);
        j1=acos(cosj(a1,b1,c1));
        j2=acos(cosj(a2,b2,c2));
        j3=acos(cosj(a3,b3,c3));
        double min=1000000000;
        double p;
        double s;
       // printf("jij2j3=%lf %lf %lf\n",j1,j2,j3);

        if(j1<=j2&&j1<=j3)
        {
            p=(a1+b1+c1)/2;
            s=sqrt(p*(p-a1)*(p-b1)*(p-c1));
           // printf("s=%f",s);
            if(s*(2*pi/j1)<min)
            min = s*(2*pi/j1);
        }
        if(j2<=j1&&j2<=j3)
        {
            p=(a2+b2+c2)/2;
            s=sqrt(p*(p-a2)*(p-b2)*(p-c2));
             if(s*(2*pi/j2)<min)
            min = s*(2*pi/j2);
        }
         if(j3<=j1&&j3<=j2)
        {
            p=(a3+b3+c3)/2;
            s=sqrt(p*(p-a3)*(p-b3)*(p-c3));
             if(s*(2*pi/j3)<min)
            min = s*(2*pi/j3);
        }
        printf("%lf\n",min);


    }
    return 0;
}
