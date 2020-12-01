#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

float f(float x,float y)
{

    float a = (1+2*x)*sqrt(y);
    //float a = -2*pow(x,3) + 12*pow(x,2) - 20*x + 8.5;
    return a;
}

int main()
{
    float x0,y0,m1,m2,m3,m4,m,y,x,h,xn;
    cout<<"\nEnter the initial values of x and y:\n";
    cin>>x0>>y0;
    cout<<"\nEnter the value of x:\n";
    cin>>xn;
    cout<<"\nEnter the step size:\n";
    cin>>h;


    x=x0;
    y=y0;
    printf("\n\nX\t\tY\n");
    while(x<xn)
    {
        m1=f(x0,y0);                         /// 25.39a
        m2=f((x0+h/2.0),(y0+m1*h/2.0));      /// 25.39b
        m3=f((x0+h/2.0),(y0+m2*h/2.0));      /// 25.39c

        m=((m1+2*m2+2*m3+m4)/6);             /// 25.39 (p)
        y=y+m*h;                             /// 25.39
        x=x+h;
        printf("%f\t%f\n",x,y);
    }
}

