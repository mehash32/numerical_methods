#include<iostream>
#include<cmath>
using namespace std;
double f(double x)
{

    double a = 0.2 + 25*x - 200*x*x + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5);
    //double a = (exp(x)*sin(x))/(1+x*x);
    return a;
}
int main()
{
    int n,i;
    double a,b,h,sum=0,integral;
    cout<<"Enter the limits of integration,\nInitial limit,a=";
    cin>>a;
    cout<<"Final limit, b=";
    cin>>b;
    cout<<"Enter the no. of subintervals, n=";
    cin>>n;
    double x[n+1],y[n+1];
    h=(b-a)/n;                ///Width of the subintervals
    for (i=0;i<=n;i++)
    {                    ///Loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;
        y[i]=f(x[i]);
    }
    for (i=1;i<n;i++)            ///Sum =  h*(y1+...+yn-1)
    {
        sum=sum+h*y[i];
    }
    integral=h/2.0*(y[0]+y[n])+sum;        /// I = h*(f(x0) + sum + f(xn))/2
    cout<<"I ="<<integral<<endl;
    return 0;
}
