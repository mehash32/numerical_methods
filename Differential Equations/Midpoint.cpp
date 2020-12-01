#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x, double y)
{
    double a = (1+2*x)*sqrt(y);
    //double a =-2*pow(x,3) + 12*pow(x,2) - 20*x + 8.5;
   // double a = 4*exp(.8*x) - .5*y;
    return a;
}
int main()
{
    int n;
    double x0,y0,x,y,h,y1,y2;
    cout.precision(5);
    cout.setf(ios::fixed);
    cout<<"\nEnter the initial values of x and y:\n";
    cin>>x0>>y0;
    cout<<"\nEnter the value of x:\n";
    cin>>x;
    cout<<"\nEnter the step size:\n";
    cin>>h;
    cout<<"x"<<setw(19)<<"y\n";
    cout<<"----------------------------------------\n";
    while(fabs(x-x0)>0.0000001)
    {
        y1  = f(x0,y0);    //25.38 a
        y2 = f(x0+h/2,y0+y1*h/2);
        y = y0 + h*y2;
        cout<<x0<<setw(16)<<y0<<endl;
        y0=y;
        x0=x0+h;
    }
    cout<<x0<<setw(16)<<y0<<endl;
    cout<<"The approximate value of y at x="<<x0<<"is "<<y<<endl;
    return 0;
}
