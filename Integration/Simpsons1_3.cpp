#include<iostream>
#include<cmath>
using namespace std;
double f(double x)
{
    double a= 0.2 + 25*x - 200*x*x + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5);
   // double a = (exp(x)*sin(x))/(1+x*x);
    return a;
}
int main()
{    cout.precision(4);
    cout.setf(ios::fixed);
    int n,i;
    double a,b,c,h,sum=0,integral;
    cout<<"Enter the limits of integration,\nInitial limit,a= ";
    cin>>a;
    cout<<"Final limit, b=";
    cin>>b;
    cout<<"\nEnter the no. of subintervals, n=";
    cin>>n ;
    double x[n+1],y[n+1];
    h=(b-a)/n;                        ///Width of the subintervals
    for (i=0;i<n+1;i++)
    {                        ///Loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;
        y[i]=f(x[i]);
    }
    for (i=1;i<n;i+=2)
    {
        sum=sum+4.0*y[i];                ///Loop to evaluate 4*(y1+y3+y5+...+yn-1)
    }
    for (i=2;i<n-1;i+=2)
    {
        sum=sum+2.0*y[i];                /// loop to evaluate 4*(y1+y3+y5+...+yn-1)+ 2*(y2+y4+y6+...+yn-2)
    }
    integral=h/3.0*(y[0]+y[n]+sum);    /// I = h*(f(x0) + 4*f(x1) + f(x2))/3 (for n = 2) // Pdf: 21.8(for n=4)
    cout<<"\nI = "<<integral<<"\n"<<endl;
    return 0;
}
