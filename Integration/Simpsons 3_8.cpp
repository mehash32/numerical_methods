#include<iostream>
#include<cmath>
using namespace std;
double f(double x)
{
    //double a= 0.2 + 25*x - 200*x*x + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5);
    double a = (exp(x)*sin(x))/(1+x*x);
    return a;
}
int main()
{   cout.precision(4);
    cout.setf(ios::fixed);
    int n,i;
    double a,b,c,h,sum=0,integral;
    cout<<"Enter the limits of integration,\nInitial limit,a= ";
    cin>>a;
    cout<<"Final limit, b=";
    cin>>b;
    //cout<<"\nEnter the no. of subintervals, n=";
   n = 3;
    double x[n+1],y[n+1];
    h=(b-a)/n;                        ///Width of the subintervals
    for (i=0;i<n+1;i++)
    {                        ///Loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;
        y[i]=f(x[i]);


       /// cout<<"y["<<i<<"]="<<y[i]<<endl;
    }


    integral=((b-a)*(y[0]+3.0*y[1]+3.0*y[2]+y[3]))/8.0;    /// Pdf: 21.20
    cout<<"\nI = "<<integral<<"\n"<<endl;
    return 0;
}
