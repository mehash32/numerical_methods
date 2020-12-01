#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double f(double x);
double f(double x)
{
   //double a=cos(x)-(x*pow(2.71828,x));
   //double a=(x*x*x-4*x-9);
    double a=cos(x)-x*exp(x);
   return a;
}
double fprime(double x);
double fprime(double x)
{
    //double b= -sin(x)-(x*pow(2.71828,x))-pow(2.71828,x);
   // double b=(3*x*x-4);
   double b=-sin(x)-exp(x)-x*exp(x);
    return b;
}

int main()
{
    double x,x1,es,fx,fx1;
    cout.precision(5);
    cout.setf(ios :: fixed);
    cout<<"enter the initial value:";
    cin>>x1;
    cout<<"\nPercentage of error:";
    cin>>es;
    cout<<"x[i]"<<"        "<<"x[i+1]"<<"    "<<"Percentage of Error"<<endl;
    while(es<(abs((x1-x)/x1)*100))
    {
       x=x1;
       fx=f(x);
       fx1=fprime(x);
       x1=x-(fx/fx1);
       cout<<x<<"      "<<x1<<"      "<<(abs((x1-x)/x1)*100)<<endl;

    }

    cout<<"\n The root of the equation is:"<<x1<<endl;

}
