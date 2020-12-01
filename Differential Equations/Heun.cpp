#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;
double f(double x, double y)
{
    //double a=-2*pow(x,3) + 12*pow(x,2) - 20*x + 8.5;
  //  double a = 4*exp(.8*x) - .5*y;
    double a = (1+2*x)*sqrt(y);
    return a;
}
int main()
{

    double x0,y0,x,y1,y2,x1,ans,h;
    cout<<"\nEnter the initial values of x and y:\n";
    cin>>x0>>y0;
    cout<<"\nEnter the value of x:\n";
    cin>>x;
    cout<<"\nEnter the step size:\n";
    cin>>h;
    cout<<"x"<<setw(16)<<"Y heun"<<endl;
    cout<<"----------------------------\n";
   for(x0;x0<=x; )
    {
        y1 = f(x0,y0)*h;    /// 25.36 (not this equation) 25.12
        x1 = x0+h;
        y2 = y0 + (f(x0,y0)+f(x1,y1)*h)/2.0; /// 25.36b
        cout<<x0<<setw(16)<<y0<<endl;
        x0=x0+h;
        y0=y2;                /// y as y0 in the next iteration.
    }

}
